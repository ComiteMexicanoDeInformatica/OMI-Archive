#include <iostream>

using namespace std;

struct person {
  int birth;
  int death;
};

person persons[1005];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  cin >> n >> q;

  // Lee las personas
  for (int i = 1; i <= n; i++) {
    cin >> persons[i].birth >> persons[i].death;
  }

  // Lee y responde las preguntas
  for (int i = 1; i <= q; i++) {
    int year;
    cin >> year;
    int alive_counter = 0, min_age = 1005, max_age = 0;

    // Verifica cada persona
    for (int j = 1; j <= n; j++) {
      // Verifica si la persona esta viva ese año
      if (persons[j].birth <= year && persons[j].death >= year) {
        // Calcula su edad en ese año
        int age = year - persons[j].birth;

        // Actualiza las respuestas
        alive_counter++;
        min_age = min(min_age, age);
        max_age = max(max_age, age);
      }
    }

    // Si no hubo nadie vivo, es necesario corregir el valor por defecto del
    // minimo
    if (alive_counter == 0) {
      min_age = 0;
    }

    // Imprime las respuestas
    cout << alive_counter << " " << min_age << " " << max_age << '\n';
  }

  return 0;
}