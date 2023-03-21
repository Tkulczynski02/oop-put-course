#include <iostream>

using namespace std;
class Clothes{
private:
    string HoodieSize = "M";
public:
    string color = "Black";
}Hoodie;

class Human{
private:
    string body;
public:
    Clothes clothes;
    int height=183;
    void PutOn(Clothes c){
        this -> clothes = c;
    }
    /*void TakeOff(){
        this->clothes = nullptr;
    }
    */
}Man;


int main()
{
    Clothes clothing;
    cout<<"What color is this hoodie"<<endl;
    cout<< clothing.color<<endl;
    Human man;
    cout<<"Does this hoodie fit you"<<endl;
    if(man.height<183){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
    return 0;
}
