#include <iostream>
using namespace std;

class MidSquareRandom {
public:
    MidSquareRandom(int m) : m(m) {
        if (m < 10 || m > 99) {
            cerr << "Must be 2-digit number." << endl;
            exit(1);
        }
    }

    int generateRandom() {
        m = m * m;
        m /= 100;
        m %= 10000;
        return m;
    }

private:
    int m;
};

int main() {
    int m;
    cout << "Enter a 2-digit m: ";
    cin >> m;

    MidSquareRandom random(m);

    int n;
    cout << "Enter the number of random numbers to generate: ";
    cin >> n;

    cout << "Generated Random Numbers:" << endl;
    for (int i = 0; i < n; i++) {
        int randomNum = random.generateRandom();
        cout << randomNum << " ";
    }

    cout << endl;
    return 0;
}