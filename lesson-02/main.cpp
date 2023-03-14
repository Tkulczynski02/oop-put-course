#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Desk{
public:
    string color;
    string material;
    int width;
    int length;
};
class Plant{
public:
    string color;
    int height;
    int age;
};
int main()
{
    Desk ikea;
    cout << "Your color: ";
    cin >> ikea.color;
    cout << "Your material: ";
    cin >> ikea.material;
    ikea.width = rand()%99;
    ikea.length = rand()%99;
    cout << "Chosen color: " << ikea.color <<endl;
    cout << "Chosen material: " << ikea.material <<endl;
    cout << "Random width: " << ikea.width <<" width"<<endl;
    cout << "Random lentgh: " << ikea.length <<" length"<<endl;

    Plant cacti;
    cout << "Color: ";
    cin >> cacti.color;
    cout << "Name: ";
    cin >> cacti.age;
    cout << "Age: ";
    cin >> cacti.age;
    cacti.height = 20;
    cacti.age=15;
    cout << "Cacti color: " << cacti.color <<endl;
    cout << "Cacti height: " << cacti.height <<endl;
    cout << "Cacti age: " << cacti.age <<endl;
    return 0;
}
