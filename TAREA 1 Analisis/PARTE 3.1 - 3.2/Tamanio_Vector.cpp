#include<iostream>
using namespace std;
// Parte de static vector
int gVect[100];
int gnCount;

void Insert(int elem) {
    if(gnCount < 100)
        gVect[gnCount++] = elem;
}

int main() {

    Insert(4);
    Insert(2);
    Insert(1);

    for(int i = 0; i < gnCount; i++) {
        cout<<gVect[i]<<" ";
    }

    return 0;
}
