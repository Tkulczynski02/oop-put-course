#include <iostream>
#include <map>
using namespace std;

class Cantor {
 public:
  Cantor() = default;
  virtual ~Cantor() = default;

  virtual double Rate(const std::string& abbreviation) const = 0;
};

class FakeUsdCantor : public Cantor {
 private:
  std::map<std::string, double> rates_;
 public:
  FakeUsdCantor() {
    // rates_ map with values for ten most popular currencies relative to USD
    rates_ = {
      {"EUR", 0.85},
      {"JPY", 110.66},
      {"GBP", 0.73},
      {"CHF", 0.91},
      {"CAD", 1.25},
      {"AUD", 1.34},
      {"CNY", 6.47},
      {"HKD", 7.78},
      {"NZD", 1.44},
      {"KRW", 1153.89}
    };
  }
  double Rate(const std::string& abbreviation) const override {
    auto it = rates_.find(abbreviation);
    if (it != rates_.end()) {
      return it->second;
    }
    // Handle error case when currency abbreviation is not found
    return 0.0;
  }
};
class Currency {
 public:
  Currency() = default;
  virtual ~Currency() = default;

  virtual double ConvertedToDollars(const Cantor& cantor) const = 0;
  virtual std::string Abbreviation() const = 0;
  virtual double Amount() const = 0;
};
class Yen : public Currency{
private:
    string abbr;
    double money;
public:
    Yen(double v){abbr="JPY"; money=v;};
    string Abbreviation()const override{return abbr;}
    double ConvertedToDollars(const Cantor& cantor)const override{return money/cantor.Rate(abbr);}
    double Amount()const override{return money;}
};
int main() {
  class Yen jpy(1313.0);
  class FakeUsdCantor toUsd;
  cout<<jpy.Abbreviation()<<endl;
  cout<<"USDs: "<<jpy.ConvertedToDollars(toUsd)<<endl;
  cout<<jpy.Amount()<<endl;
  return 0;
}
