#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

struct event {
  int year;
  int operation;  // 1: una persona nace, 2: preguntar, 3: una persona muere
  int person_query_id;
};

bool eventLessThan(const event& event1, const event& event2) {
  // Ordenar primero por menor año, segundo por tipo de operacion
  if (event1.year < event2.year) {
    return true;
  } else {
    if (event1.year == event2.year) {
      return event1.operation < event2.operation;
    } else {
      return false;
    }
  }
}

struct person {
  int birth;
  int death;
};

struct answer {
  int query_id;
  int alive_counter;
  int min_age;
  int max_age;
};

bool answerLessThan(const answer& answer1, const answer& answer2) {
  // Ordenar por id ascendente para imprimir las respuestas en el mismo orden
  // de las preguntas
  return answer1.query_id < answer2.query_id;
}

vector<event> events;
set<pair<int, int>> alive;  // Pares {year, person_id}
map<int, int> person_birth_date;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  cin >> n >> q;

  // Lee las personas
  for (int i = 1; i <= n; i++) {
    person person1;
    cin >> person1.birth >> person1.death;

    // Crea eventos de nacimiento y muerte de la persona i
    event birth = {/*year =*/person1.birth, /*operation =*/1, /*person_id=*/i};
    event death = {/*year =*/person1.death, /*operation =*/3, /*person_id=*/i};

    events.push_back(birth);
    events.push_back(death);
  }

  // Lee las preguntas
  for (int i = 1; i <= q; i++) {
    int year;
    cin >> year;

    // Crea evento de pregunta
    event query = {year, /*operation =*/2, /*query_id =*/i};
    events.push_back(query);
  }

  vector<answer> answers;  // Almacena las respuestas a las preguntas

  // Ordena los eventos usando la funcion de ordenamiento
  sort(events.begin(), events.end(), eventLessThan);

  // Procesa los eventos en orden cronologico
  for (event cur_event : events) {
    int current_year = cur_event.year;
    int person_id = cur_event.person_query_id;

    if (cur_event.operation == 2) {
      // Pregunta

      // Obtiene la cantidad de personas vivas
      int alive_counter = alive.size();

      // Si no hay nadie vivo, la salida es 0
      int min_age = 0;
      int max_age = 0;

      // Obtiene la edad de la persona mas joven y mas anciana
      // si hay alguien vivo
      if (alive_counter > 0) {
        // Persona mas joven
        auto youngest_person = alive.end();
        youngest_person--;

        int youngest_birth_year = youngest_person->first;
        min_age = current_year - youngest_birth_year;

        // Persona mas anciana
        auto oldest_person = alive.begin();
        int oldest_birth_year = oldest_person->first;
        max_age = current_year - oldest_birth_year;
      }

      // Almacena las respuestas
      answer cur_answer;
      cur_answer.query_id = cur_event.person_query_id;
      cur_answer.alive_counter = alive_counter;
      cur_answer.min_age = min_age;
      cur_answer.max_age = max_age;
      answers.push_back(cur_answer);

    } else if (cur_event.operation == 3) {
      // Una persona muere

      // Se elimina la persona del conjunto de personas vivas
      alive.erase(make_pair(/*year =*/person_birth_date[person_id], person_id));
      person_birth_date.erase(person_id);
    } else {
      // Una persona nace

      // Se agrega la persona al conjunto de personas vivas
      alive.insert(make_pair(current_year, person_id));
      person_birth_date[person_id] = current_year;
    }
  }

  // Imprime las respuestas en el mismo orden que las preguntas
  sort(answers.begin(), answers.end(), answerLessThan);

  for (answer cur_answer : answers) {
    // Imprime las respuestas
    cout << cur_answer.alive_counter << " " << cur_answer.min_age << " "
         << cur_answer.max_age << '\n';
  }

  return 0;
}