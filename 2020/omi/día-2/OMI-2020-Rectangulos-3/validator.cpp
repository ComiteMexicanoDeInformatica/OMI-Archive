#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <optional>
#include <set>
#include <vector>

using Range = std::pair<int, int>;

struct Rectangle {
  Range x;
  Range y;
};

std::ostream& operator<<(std::ostream& o, const Rectangle& r) {
  return o << "Rectangle(" << r.x.first << ", " << r.y.first << ", "
           << r.x.second << ", " << r.y.second << ")";
}

enum EventType : int {
  // OPEN needs to come first. The reason is that all the open events need to
  // be processed before the close events, so that contiguous rectangles are
  // correctly flagged as contiguous.
  OPEN = 0,
  CLOSE = 1,
};

struct Event {
  int coord;
  EventType event_type;
  Rectangle rect;

  bool operator<(const Event& e) const {
    if (coord != e.coord) return coord < e.coord;
    if (event_type != e.event_type) return event_type < e.event_type;
    return rect.x < e.rect.x;
  }
};

bool intersects(Range a, Range b) {
  return (a.first <= b.second + 1 && b.first <= a.second + 1);
}

int64_t score(std::istream& f, int64_t map_width, int64_t map_height) {
  size_t n;
  std::set<Range> sizes;
  std::vector<Event> events;
  int64_t repeats = 0, buzzers = 0;
  f >> n;
  events.reserve(2 * n);
  while (true) {
    int x1, y1, x2, y2;
    if (!(f >> x1 >> y1 >> x2 >> y2)) {
      break;
    }

    if (x1 > x2) std::swap(x1, x2);
    if (y1 > y2) std::swap(y1, y2);

    Rectangle rect{Range{x1, x2}, Range{y1, y2}};

    // Validate that the rectangle provided lies within the allowable area.
    if (x1 <= 0 || x2 > map_width || y1 <= 0 || y2 > map_height) {
      std::cerr << rect << " out of bounds.\n";
      std::cout << "0\n";
      exit(0);
    }

    // Calculate the total number of points that the rectangle would obtain.
    const int64_t width = x2 - x1 + 1;
    const int64_t height = y2 - y1 + 1;

    buzzers += width * height;

    if (sizes.insert(std::make_pair(width, height)).second == false) repeats++;

    events.emplace_back(Event{x1, EventType::OPEN, rect});
    events.emplace_back(Event{x2 + 1, EventType::CLOSE, rect});
  }

  if (n * 2 != events.size()) {
    std::cerr << "Expected " << n << " rectangles. Found " << events.size() / 2
              << "\n";
    std::cout << "0\n";
    exit(0);
  }

  std::sort(events.begin(), events.end());

  std::set<Range> active;
  for (const Event& event : events) {
    const Range& range = event.rect.y;
    if (event.event_type == EventType::CLOSE) {
      active.erase(range);
      continue;
    }

    if (!active.empty()) {
      // Compare the current event's range with the two adjacent ranges in the
      // active set.
      std::set<Range>::iterator it = active.lower_bound(range);
      if (it == active.end()) {
        const Range& other_range = *active.rbegin();
        if (intersects(other_range, range)) {
          std::cerr << event.rect << " and Range(" << other_range.first << ", "
                    << other_range.second << ") are contiguous.\n";
          std::cout << "0\n";
          exit(0);
        }
      } else {
        if (intersects(*it, range)) {
          std::cerr << event.rect << " and Range(" << it->first << ", "
                    << it->second << ") are contiguous.\n";
          std::cout << "0\n";
          exit(0);
        }
        if (it != active.begin()) {
          --it;
          if (intersects(*it, range)) {
            std::cerr << event.rect << " and Range(" << it->first << ", "
                      << it->second << ") are contiguous.\n";
            std::cout << "0\n";
            exit(0);
          }
        }
      }
    }
    active.insert(range);
  }
  return std::max(static_cast<int64_t>(0),
                  static_cast<int64_t>((buzzers - repeats) * sizes.size()));
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int64_t map_width, map_height;
  {
    std::ifstream f("data.in");
    f >> map_width >> map_height;
  }

  const int64_t contestant_score = score(std::cin, map_width, map_height);

  int64_t judge_score = 1;
  {
    std::ifstream f("data.out");
    judge_score = score(f, map_width, map_height);
  }

  const double score = std::pow(((double)contestant_score / judge_score), 1.5);

  printf("%.2f\n", std::min(1.0, (std::ceil(score * 100.0) / 100.0)));
}
