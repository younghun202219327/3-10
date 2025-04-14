#include <iostream>
#include <vector>
#include <cmath>

class SparsePoly {
public:
    std::vector<int> exponents;  // 차수
    std::vector<float> coefficients;  // 계수

    // 다항식 입력 함수
    void read() {
        int numTerms;
        std::cout << "항의 개수를 입력하시오: ";
        std::cin >> numTerms;

        exponents.resize(numTerms);
        coefficients.resize(numTerms);

        for (int i = 0; i < numTerms; ++i) {
            std::cout << i + 1 << "번째 항의 계수와 차수를 입력하시오: ";
            std::cin >> coefficients[i] >> exponents[i];
        }
    }

    // 다항식 출력 함수
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

    // 다항식 덧셈 함수
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
            else {  // 두 다항식의 차수가 같을 경우
                float sum = a.coefficients[i] + b.coefficients[j];
                if (sum != 0) {  // 계수가 0이면 저장하지 않음
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

    
    std::cout << "다항식 A를 입력하세요:" << std::endl;
    A.read();
    std::cout << "다항식 B를 입력하세요:" << std::endl;
    B.read();

   
    A.display("Poly A");
    B.display("Poly B");

    
    C.add(A, B);

    C.display("Poly C");

    return 0;
}

