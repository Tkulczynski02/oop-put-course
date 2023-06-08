#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class IntegerSequence {
public:
    virtual vector<int> Numbers() const = 0;
};

class VectorSequence : public IntegerSequence {
private:
    vector<int> number;
public:
    VectorSequence(const vector<int>& numbers) : number(numbers) {}

    vector<int> Numbers() const override {
        return number;
    }
};

int main() {
    vector<int> inputNumbers = { 1, 2, 3, 4, 5 };

    IntegerSequence* sequence = new VectorSequence(inputNumbers);

    vector<int>numbers = sequence->Numbers();

    cout << "Sequence: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    delete sequence;

    return 0;
}

