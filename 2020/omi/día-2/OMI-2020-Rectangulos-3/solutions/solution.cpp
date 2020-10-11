#include <iostream>
#include <vector>

#define MP std::make_pair

typedef long long int lli;
typedef std::pair<std::pair<lli, lli>, std::pair<lli, lli> > pplli;

std::vector<pplli> coordinates;
int w, h, ActualW, ActualH, RectangleW, RectangleH, counter, p, x, aux, extraH,
    extraW;
bool used[210][210];

void solveH() {
  if (ActualW >= w) return;

  RectangleW = 1;
  while (ActualW + RectangleW <= w) {
    if (ActualW + RectangleW + 1 == w) extraW = 1;

    RectangleH = 1;
    while (used[RectangleH][RectangleW + extraW] == true) RectangleH++;
    ActualH = 0;
    while (ActualH + RectangleH <= p) {
      if (ActualH + 2 * RectangleH + 1 >= p) extraH = p - ActualH - RectangleH;
      while (used[RectangleH + extraH][RectangleW + extraW] == true) extraH--;

      counter++;
      coordinates.push_back(
          MP(MP(ActualW + 1, ActualH + 1),
             MP(ActualW + RectangleW + extraW, ActualH + RectangleH + extraH)));

      ActualH += RectangleH + extraH + 1;
      used[RectangleH + extraH][RectangleW + extraW] = true;
      while (used[RectangleH][RectangleW + extraW] == true) RectangleH++;
      extraH = 0;
    }

    ActualW += RectangleW + extraW + 1;
    RectangleW++;
    extraW = 0;
  }

  solveH();
}

void solveW() {
  if (ActualH >= h) return;

  RectangleH = 1;
  while (ActualH + RectangleH <= h) {
    if (ActualH + RectangleH + 1 == h) extraH = 1;

    RectangleW = 1;
    while (used[RectangleH + extraH][RectangleW] == true) RectangleW++;
    ActualW = 0;
    while (ActualW + RectangleW <= w) {
      if (ActualW + 2 * RectangleW + 1 >= w) extraW = w - ActualW - RectangleW;
      while (used[RectangleH + extraH][RectangleW + extraW] == true) extraW--;

      counter++;
      coordinates.push_back(
          MP(MP(ActualW + 1, ActualH + 1),
             MP(ActualW + RectangleW + extraW, ActualH + RectangleH + extraH)));

      ActualW += RectangleW + extraW + 1;
      used[RectangleH + extraH][RectangleW + extraW] = true;
      while (used[RectangleH + extraH][RectangleW] == true) RectangleW++;
      extraW = 0;
    }

    ActualH += RectangleH + extraH + 1;
    RectangleH++;
    extraH = 0;
  }
  solveW();
}

int main() {
  std::cin >> w >> h;

  ActualH = 0;
  RectangleH = 1;
  while (ActualH + RectangleH <= h) {
    if (ActualH + RectangleH + 1 == h) extraH = 1;

    ActualW = 0;
    RectangleW = 1;
    while (ActualW + RectangleW <= w) {
      if (ActualW + RectangleW + 1 == w) extraW = 1;

      counter++;
      coordinates.push_back(
          MP(MP(ActualW + 1, ActualH + 1),
             MP(ActualW + RectangleW + extraW, ActualH + RectangleH + extraH)));

      ActualW += RectangleW + extraW + 1;
      used[RectangleH + extraH][RectangleW + extraW] = true;
      RectangleW++;
      extraW = 0;
    }

    ActualH += RectangleH + extraH + 1;
    RectangleH++;
    extraH = 0;
  }

  p = ActualH - 1;
  x = ActualW;
  aux = RectangleH;

  solveW();

  ActualW = x;
  RectangleH = aux;
  solveH();

  std::cout << counter << "\n";
  for (int i = 0; i < counter; i++) {
    std::cout << coordinates[i].first.first << " "
              << coordinates[i].first.second << " "
              << coordinates[i].second.first << " "
              << coordinates[i].second.second << "\n";
  }
}
