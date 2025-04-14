#include <iostream>
#include <vector>
#include <cmath>

class SparsePoly {
public:
    std::vector<int> exponents;  // ����
    std::vector<float> coefficients;  // ���

    // ���׽� �Է� �Լ�
    void read() {
        int numTerms;
        std::cout << "���� ������ �Է��Ͻÿ�: ";
        std::cin >> numTerms;

        exponents.resize(numTerms);
        coefficients.resize(numTerms);

        for (int i = 0; i < numTerms; ++i) {
            std::cout << i + 1 << "��° ���� ����� ������ �Է��Ͻÿ�: ";
            std::cin >> coefficients[i] >> exponents[i];
        }
    }

    // ���׽� ��� �Լ�
    void display(const char* str) {
        std::cout << str << " = ";
        for (size_t i = 0; i < exponents.size(); ++i) {
            if (i > 0) {
                std::cout << (coefficients[i] >= 0 ? " + " : " - ");
                std::cout << std::abs(coefficients[i]);
            }
            else if (coefficients[i] < 0) {
                std::cout << "-";
                std::cout << std::abs(coefficients[i]);
            }
            else {
                std::cout << coefficients[i];
            }

            if (exponents[i] > 0) {
                std::cout << "x";
                if (exponents[i] > 1) {
                    std::cout << "^" << exponents[i];
                }
            }
        }
        std::cout << std::endl;
    }

    // ���׽� ���� �Լ�
    void add(const SparsePoly& a, const SparsePoly& b) {
        size_t i = 0, j = 0;
        while (i < a.exponents.size() || j < b.exponents.size()) {
            if (i < a.exponents.size() && (j >= b.exponents.size() || a.exponents[i] > b.exponents[j])) {
                exponents.push_back(a.exponents[i]);
                coefficients.push_back(a.coefficients[i]);
                i++;
            }
            else if (j < b.exponents.size() && (i >= a.exponents.size() || a.exponents[i] < b.exponents[j])) {
                exponents.push_back(b.exponents[j]);
                coefficients.push_back(b.coefficients[j]);
                j++;
            }
            else {  // �� ���׽��� ������ ���� ���
                float sum = a.coefficients[i] + b.coefficients[j];
                if (sum != 0) {  // ����� 0�̸� �������� ����
                    exponents.push_back(a.exponents[i]);
                    coefficients.push_back(sum);
                }
                i++;
                j++;
            }
        }
    }
};

int main() {
    SparsePoly A, B, C;

    
    std::cout << "���׽� A�� �Է��ϼ���:" << std::endl;
    A.read();
    std::cout << "���׽� B�� �Է��ϼ���:" << std::endl;
    B.read();

   
    A.display("Poly A");
    B.display("Poly B");

    
    C.add(A, B);

    C.display("Poly C");

    return 0;
}

