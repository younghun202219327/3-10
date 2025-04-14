#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "배열의 크기를 입력하시오: ";  
    cin >> n;  

    int maxVal;
    cout << "숫자를 입력하시오: ";  
    cin >> maxVal;  

    
    for (int i = 1; i < n; ++i) {
        int num;
        cin >> num;  
        if (num > maxVal) {
            maxVal = num;  
        }
    }

    cout << "최댓값은: " << maxVal << endl;  

    return 0;
}