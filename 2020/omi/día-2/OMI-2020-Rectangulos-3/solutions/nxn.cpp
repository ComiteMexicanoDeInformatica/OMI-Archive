#include <iostream>
#include <vector>

#define MP std::make_pair

typedef long long int lli;
typedef std::pair<std::pair<lli, lli>, std::pair<lli, lli> > pplli;

std::vector<pplli> coordinates;

int main() {
  int W, H, sizeH, sizeV, actualX, actualY, rectangles, timeX, timeY;
  std::cin >> H >> W;

  actualX = actualY = 1;
  sizeH = 0;
  sizeV = 0;

  while (actualY + sizeV <= W) {
    actualX = 1;
    sizeH = 0;
    while (actualX + sizeH <= H) {
      if (actualY + sizeV <= W) {
        coordinates.push_back(
            MP(MP(actualX, actualY), MP(actualX + sizeH, actualY + sizeV)));
      }
      actualX = actualX + sizeH + 2;
      sizeH += 1;
      /*if(actualX + 2*sizeH + 1 >= H && timeX == 0){
          timeX = 1;
          sizeH = H - actualX;
      }*/
    }
    actualY += sizeV;
    actualY += 2;
    sizeV += 1;
    timeX = 0;
    /*if( actualY + 2*sizeV + 1 >= W && timeY == 0){
       timeY = 1;
       sizeV = W - actualY;
    }*/
  }
  rectangles = coordinates.size();
  std::cout << rectangles << "\n";
  for (int i = 0; i < rectangles; i++) {
    std::cout << coordinates[i].first.first << " "
              << coordinates[i].first.second << " "
              << coordinates[i].second.first << " "
              << coordinates[i].second.second << "\n";
  }
}
