#include <iostream>
using namespace std;

int n;
int a[100] = {0};
bool unused[100] = {true};

void display() {
    for (int i = 1; i <= n; i++) {
        cout << a[i];
    }
    cout << endl;
}

void Back_Track(int i) {
    for (int j = 1; j <= n; j++) {
        if (unused[j] == true) {
            a[i] = j;
            unused[j] = false;
            if (i == n) {
                display();
            } else {
                Back_Track(i + 1);
            }
            unused[j] = true; // Ðánh d?u ph?n t? j là chua s? d?ng sau khi quay lui
        }
    }
}

int main() {
    cin >> n;
    Back_Track(1);
    return 0;
}
