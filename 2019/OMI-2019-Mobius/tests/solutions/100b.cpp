#include "moebius.h"
#include <map>
#include <iostream>

#define ull unsigned long long
#define ll long long

using namespace std;
// Main
//	long long avanza(long long casas)

int directionSign = 1;
ll origin;
ll target;
ll currentIndex=0;
ll currentNumber = 0;
ll bsStart;
ll bsEnd;
std::map< ll, ll > housesMap;

int bsIntervalState = 0;

std::pair<ll, ll> clampBorders(ll start, ll end);

//Layer de avanza para llevar una sola dirección y registro
ll jump(ll houses){
    currentIndex+=houses;
    return housesMap[currentIndex] = currentNumber = avanza(houses)*directionSign;
}

void findSign(){
    ll secondHouse = jump(1);
    if( std::min(origin, secondHouse)< target &&  std::max(origin, secondHouse)>target){
        if(secondHouse>origin){
            directionSign = -1;
        }
    }else{
        if(secondHouse<origin){
            directionSign = -1;
        }
    }
    //Cambia todo los signos para que siempre sea creciente
    origin*=directionSign;
    target*=directionSign;
    currentNumber*=directionSign;
    housesMap[0] = housesMap[0]*directionSign;
    housesMap[1] = housesMap[1]*directionSign;
}


void power2JumpsSearch(){
    ll searchDirection = 1;
    if(target<currentNumber){
        searchDirection=-1;
    }
    ll jumpSize = 1;
    while(1){
        ll nextJump = jumpSize*searchDirection;
        ll lastIndex = currentIndex;
        ll lastNumber = currentNumber;

        jump(nextJump);

        ll newSign = (currentNumber-lastNumber)/std::max(currentNumber-lastNumber, -(currentNumber-lastNumber));

        if( newSign!=searchDirection || (searchDirection==1 && currentNumber>=target) || (searchDirection==-1 && currentNumber<=target)){

            if(searchDirection==1){
                bsStart = lastIndex;
                bsEnd = currentIndex;
            }else{
                bsEnd = lastIndex;
                bsStart = currentIndex;
            }

            bsIntervalState = searchDirection;
            break;
        }

        jumpSize*=2;
    }
}


void binarySearch(){
    while(bsEnd>bsStart){
        ll pivot = (bsStart+bsEnd)/2;
        ll nextJump = pivot-currentIndex;
        jump(nextJump);

        if( bsIntervalState==1 && currentNumber<=housesMap[bsStart] ) {
                bsEnd = currentIndex;

        }else{
            if( bsIntervalState==-1 && currentNumber>=housesMap[bsEnd] ){
                bsStart = currentIndex;
            }else{
                if(currentNumber>target){
                    bsEnd = currentIndex;
                }else{
                    bsStart = currentIndex;
                }
            }
        }

    }
}

void encuentraCasa(long long origen, long long destino) {
    origin = currentNumber = origen;
    target = destino;
	housesMap[currentIndex] = origen;

	findSign();
	power2JumpsSearch();
	binarySearch();

}
