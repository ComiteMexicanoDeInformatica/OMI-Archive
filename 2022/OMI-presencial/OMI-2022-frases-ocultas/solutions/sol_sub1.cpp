#include <iostream>

#define debugsl(x) std::cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << "\n";

#define MAX 100000

int t, n, largo;
std::string st, palabra[MAX + 2];

int main() {
  std::cin >> t >> n >> st;

  for (int i = 1; i <= n; ++i) std::cin >> largo >> palabra[i];

  bool o, m, i;
  o = m = i = false;

  // LETRA POR LETRA BUSCA QUE EL TEXTO TENGA PRIMERO UNA o, LUEGO UNA m Y
  // FINALMENTE UNA i
  for (int pos = 0; pos < t; ++pos) {
    if (!o && st[pos] == 'o')
      o = true;
    else if (o && !m && st[pos] == 'm')
      m = true;
    else if (o && m && !i && st[pos] == 'i')
      i = true;
  }

  if (o && m && i)
    std::cout << "1\n";
  else
    std::cout << "0\n";

  return 0;
}
