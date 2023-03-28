#include <iostream>
using namespace std;

class Fashion{
private:
    int collection;
public:
    int year(){return this-> collection;};
    Fashion(){collection=0;};
    Fashion (int x){collection=x;};
    Fashion (string s):Fashion(stoi(s)){};
    };
int main()
{
    class Fashion Collection;
    class Fashion Raf("2001");
    class Fashion Undercover("2003");
    class Fashion NumberNine("2005");
    cout<<"The best Takahiro Miyashita collection was in: "<< NumberNine.year()<<" And it was Nightcrawler"<<endl;
    cout<<"The best Jun Takahashi collection was in: "<< Undercover.year()<<" And it was SCAB"<<endl;
    cout<<"The best Raf Simons collection was in: "<< Raf.year()<<" And it was Consumed"<<endl;
}
