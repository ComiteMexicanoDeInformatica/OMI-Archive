#include <cstdio>

int N;

int main() {
  scanf("%d", &N);

  int delta = 0;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      char c;
      scanf(" %c", &c);
      delta += c == 'X' ? 1 : -1;
    }

  printf("%s\n", delta ? "DIFERENTES" : "IGUALES");
}
