#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

class Logarithm{
 private:
  double base_;
  double argument_;
 public:

  Logarithm(double base, double argument) {
    base_ = base;
    argument_ = argument;
  }
   double Calculate() const{
     if(base_<=0){
        throw invalid_argument("Base cant be less than 0 or equal to 0");
     }
     if(base_==1){
        throw invalid_argument("Base cant be equal to 1");
     }
     if(argument_<=0){
        throw invalid_argument("Argument cant be less than 1");
     }
     return log(argument_) / log(base_);
    }
   };
int main(){
    while(1){
        double b,a;
        b=0,a=0;
        cin>>b;
        cin>>a;
        try{
        Logarithm log(a,b);
        log.Calculate();
    }
    catch(invalid_argument e){
        cerr << e.what();
        }
    }
return 0;
}
