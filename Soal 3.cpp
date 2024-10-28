#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int hitungPostfix(string ekspresi) {
    stack<int> s;
    for (char c : ekspresi) {
        if (isdigit(c)) {
            s.push(c - '0');
        } else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            switch (c) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
                case '^': s.push(pow(a, b)); break;
            }
        }
    }
    return s.top();
}

int main() {
    string ekspresi;
    cout << "Masukkan ekspresi postfix: "; cin >> ekspresi;
    cout << "Hasil: " << hitungPostfix(ekspresi) << endl;
    return 0;
}
