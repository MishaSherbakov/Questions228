//
// Created by misha on 27/06/2020.
//

/* std::vector<SomeClass> data;
data.emplace_back(3, 2.0) вместо data.push_back({3, 2.0}),который создает новый объект

for (auto it = data.rbegin(); it != data.rend(); ++it) */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>

class Fraction {
public:
    Fraction(int numerator, int denominator) : numerator_(numerator), denominator_(denominator) {
        int gcd = std::gcd(denominator_, numerator_);// Находим НОД
        numerator_ /= gcd;
        denominator_ /= gcd;

    }

    Fraction(int numerator) : numerator_(numerator), denominator_(1) {
        Fraction(numerator_, denominator_);
    }

    int Numerator() const {
        return numerator_;
    }

    int Denominator() const {
        return denominator_;
    }

    Fraction operator*(const Fraction& rhs) const {
        return Fraction(numerator_ * rhs.numerator_, denominator_ * rhs.denominator_);
    }
private:
    int numerator_, denominator_;
};

void PrintFraction(const Fraction& f) {
    std::cout << f.Numerator() << "/" << f.Denominator() << std::endl;
}



int main() {
    Fraction f(3,6);
    PrintFraction(f);
    Fraction c(4);
    Fraction d(4,6);
    PrintFraction(f * c);//f.operator*(c) !!!!

}