#include <iostream>

using namespace std;
class Animals{
public:
    Animals(){};
    virtual Animals *Kingdom(string animalia)=0;
    virtual string specie()=0;
};
class Species: public Animals{
private:
    string name;
public:
    Species(){this->name="Animal";};
    string specie(){return this->name;}
    Species(string n){name=n;}
    Species *Kingdom(string animalia){return new Species(animalia);}
};
int main()
{
    class Species FoodChain;
    class Species Mammal("Human");
    class Species Bird("Chicken");
    class Species Worm("Worm");
    cout<<"The basic food chain is: "<<Worm.specie()<<" then "<<Bird.specie()<<" then "<<Mammal.specie()<<endl;
}
