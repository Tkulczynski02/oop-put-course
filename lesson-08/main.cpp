#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;

class Product{
private:
    string name;
    float price;
    int UpID;
public:
    Product(string n, float p){name=n, price=p;}
    Product()=default;
    ~Product()=default;
    string pName(){return this->name;}
    int pPrice(){return this->price;}
};
class Customer{
private:
    string name;
    string email;
    int UcID;
public:
    Customer(){name="Thomas", email="Thomas02@gmail.com", UcID=1111;}
    ~Customer()=default;
};
class Order{
private:
    int UoID;
    string order[100];
    int hoodie=0;
    int TotalAmount=0;
public:
    Order(){UoID=rand()%10000;}
    ~Order()=default;
    void APTO(string prod){
        hoodie++;
        for(int i=0; i<hoodie; i++){
            order[i]=prod;
            cout<<"Your order is: "<<order[i]<<endl;
        }
    }
    void COTO(int a){
        TotalAmount+=a;
        cout<<"Total amount of your order is: "<<a<<endl;
    }
};
int main()
{
    srand(time(NULL));
    class Product p;
    class Customer c;
    class Order o;
    o.COTO(p.pName());
    o.APTO(p.pPrice());
    return 0;
}
