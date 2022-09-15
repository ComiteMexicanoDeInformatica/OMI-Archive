#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct person {
  int birth, death;  // Año de nacimiento y año de muerte de una persona.
};

bool sortByBirth(const person &p1, const person &p2) {
  return (p1.birth != p2.birth) ? p1.birth < p2.birth : p1.death < p2.death;
}

struct query {
  int index, year;  // Número y año de la pregunta.
  int alive;        // Número de personas vivas.
  int youngest;     // Edad de la persona viva más joven.
  int oldest;       // Edad de la persona viva más anciana.
};

bool sortByYear(const query &q1, const query &q2) { return q1.year < q2.year; }

bool sortByIndex(const query &q1, const query &q2) {
  return q1.index < q2.index;
}

// Guarda en una cola de prioridad las personas que están vivas, ordenadas por
// menor año de muerte. Además, para cada sub-árbol guarda el mínimo y el
// máximo año de nacimiento.
class heap {
 public:
  struct node {
    int birth, death;        // Año de nacimiento y año de muerte.
    int minBirth, maxBirth;  // Mínimo y máximo año de nacimiento.
  };

  void push(const person &p) {
    nodes.push_back(node{p.birth, p.death, p.birth, p.birth});
    int current = nodes.size() - 1;
    while (current > 0) {
      int parent = (current - 1) / 2;
      if (nodes[parent].death < nodes[current].death) {
        break;
      }
      swap(nodes[current], nodes[parent]);
      current = parent;
    }
    update(nodes.size() - 1);
  }

  void pop() {
    node tmp = nodes.back();
    nodes.pop_back();
    if (nodes.empty()) return;
    update(nodes.size() / 2);
    nodes[0] = tmp;
    int current = 0;
    while (2 * current + 1 < nodes.size()) {
      int lchild = 2 * current + 1, rchild = 2 * current + 2;
      int child =
          (rchild < nodes.size() && nodes[rchild].death < nodes[lchild].death)
              ? rchild
              : lchild;
      if (nodes[current].death < nodes[child].death) {
        break;
      }
      swap(nodes[current], nodes[child]);
      current = child;
    }
    update(current);
  }

  node &top() { return nodes[0]; }

  int size() { return nodes.size(); }

  bool empty() { return nodes.empty(); }

  friend ostream &operator<<(ostream &ostr, heap &pq) {
    for (int i = 0; i < pq.size(); ++i) {
      ostr << "(" << pq.nodes[i].birth << "," << pq.nodes[i].death << ") ";
    }
    return ostr << "\n";
  }

 private:
  vector<node> nodes;

  void update(int n) {
    int l = 2 * n + 1, r = 2 * n + 2;
    nodes[n].minBirth = nodes[n].birth;
    nodes[n].maxBirth = nodes[n].birth;
    if (l < nodes.size()) {
      nodes[n].minBirth = min(nodes[n].minBirth, nodes[l].minBirth);
      nodes[n].maxBirth = max(nodes[n].maxBirth, nodes[l].maxBirth);
    }
    if (r < nodes.size()) {
      nodes[n].minBirth = min(nodes[n].minBirth, nodes[r].minBirth);
      nodes[n].maxBirth = max(nodes[n].maxBirth, nodes[r].maxBirth);
    }
    if (n > 0) {
      update((n - 1) / 2);
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  // Número de personas y número de preguntas.
  int N, Q;
  cin >> N >> Q;
  // Lee las personas y las ordena primero por año de nacimiento y luego por
  // año de muerte.
  vector<person> persons(N);
  for (int i = 0; i < N; ++i) {
    cin >> persons[i].birth >> persons[i].death;
  }
  sort(persons.begin(), persons.end(), sortByBirth);
  // Lee las preguntas y las ordena por año.
  vector<query> queries(Q);
  for (int i = 0; i < Q; ++i) {
    cin >> queries[i].year;
    queries[i].index = i;
  }
  sort(queries.begin(), queries.end(), sortByYear);
  // Responde las preguntas en orden. Guarda en una cola de prioridad las
  // personas que siguen vivas. Ordena por menor año de muerte.
  heap alive;
  for (int i = 0, j = 0; i < Q; ++i) {
    // Agrega a la cola de prioridad las personas que hayan nacido.
    for (; j < N && persons[j].birth <= queries[i].year; ++j) {
      alive.push(persons[j]);
    }
    // Elimina de la cola de prioridad las personas que hayan muerto.
    while (!alive.empty() && alive.top().death < queries[i].year) {
      alive.pop();
    }
    // Responde la pregunta.
    // cerr << queries[i].year << ": " << alive;
    queries[i].alive = alive.size();
    queries[i].youngest =
        alive.empty() ? 0 : queries[i].year - alive.top().maxBirth;
    queries[i].oldest =
        alive.empty() ? 0 : queries[i].year - alive.top().minBirth;
  }
  // Reacomoda las preguntas en el orden original e imprime la respuesta.
  sort(queries.begin(), queries.end(), sortByIndex);
  for (int i = 0; i < Q; ++i) {
    cout << queries[i].alive << " " << queries[i].youngest << " "
         << queries[i].oldest << "\n";
  }
  return 0;
}
