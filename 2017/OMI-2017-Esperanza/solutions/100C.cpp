#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int N;
char S[20100];
int posX=0;
int posY=0;
set<pair<int, int> > Visited;

void moveGuardByOrder(char order)
{
    switch (order)
    {
    case 'L':
        posX--;
        return;
    case 'R':
        posX++;
        return;
    case 'U':
        posY--;
        return;
    case 'D':
        posY++;
        return;
    default:
        throw "Input error";
    }
}

void markAsVisited(int x, int y){
    Visited.insert(make_pair(x, y));
}

bool isVisited(int x, int y){
    return (Visited.find(make_pair(x, y)) != Visited.end());
}

string solveByArrayAndLength(char* arr, int length){
    posX = 0;
    posY = 0;
    markAsVisited(posX, posY);
    for (int i=0; i<N; i++)
    {
        moveGuardByOrder(arr[i]);
        if(isVisited(posX, posY)){
            return "Impossibru";
        }
        markAsVisited(posX, posY);
    }
    return "Esperanza";
}

int main()
{
    cin >> N >> S;
    cout << solveByArrayAndLength(S, N) << endl;
    return 0;
}
