#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "�迭�� ũ�⸦ �Է��Ͻÿ�: ";  
    cin >> n;  

    int maxVal;
    cout << "���ڸ� �Է��Ͻÿ�: ";  
    cin >> maxVal;  

    
    for (int i = 1; i < n; ++i) {
        int num;
        cin >> num;  
        if (num > maxVal) {
            maxVal = num;  
        }
    }

    cout << "�ִ���: " << maxVal << endl;  

    return 0;
}