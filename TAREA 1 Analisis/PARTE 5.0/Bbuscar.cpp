#include<iostream>
using namespace std;

int bsearch(double a[], double key, int l, int u)
{
    int m;
    if (u<l)
        return -1;
    m = (l+u) / 2;
    if (a[m] == key)
        return m;
    if (a[m] > key)
        return bsearch(a, key, l, m-1);
    else
        return bsearch(a, key, m+1, u);
}

int main() {
    double arr[] = {2,5, 3.4, 3.7, 6.5, 6.9, 8.9, 9.1};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    double key;
    std::cout << "Ingrese el numero a buscar: ";
    std::cin >> key;
    
    int index = bsearch(arr, key, 0, size - 1);
    
    if (index == -1)
        std::cout << "El numero no esta en el arreglo." << std::endl;
    else
        std::cout << "El numero se encuentra en : " << index << std::endl;
    
    return 0;
}
