#include <iostream>
#include <string>

class Polynomial {
private:
    int k;
    std::string s;
    int pow;

public:
    Polynomial();
    Polynomial(int k, std::string s, int pow);
    int getK();
    std::string getS();
    int getPow();
    bool canMerge(Polynomial* p);
    bool mergeItem(Polynomial* p);
    bool buidNewItem(Polynomial* list, Polynomial* p);
    std::string print();
};

Polynomial::Polynomial()
{
    this->k = 0;
    this->s = nullptr;
    this->pow = 1;
}

Polynomial::Polynomial(int k, std::string s, int pow)
{
    this->k = k;
    this->s = s;
    this->pow = pow;
}

int Polynomial::getK()
{
    return this->k;
}
std::string Polynomial::getS()
{
    return this->s;
}
int Polynomial::getPow()
{
    return this->pow;
}
bool Polynomial::canMerge(Polynomial* p)
{
    return (this->pow == p->getPow()) && (this->s == p->getS());
}

bool Polynomial::mergeItem(Polynomial* p)
{
    this->k = this->k + p->getK();
    delete p;
    return true;
}

std::string Polynomial::print()
{
    std::string outcome = "";
    if (this->k != 1) {
        if (k < 0) {
            outcome += "(" + std::to_string(this->k) + ")";
        } else
            outcome += std::to_string(this->k);
    }
    if (this->pow == 0)
        return outcome;
    outcome += this->s;
    if (this->pow != 1)
        outcome += "{" + std::to_string(this->pow) + "}";
    return outcome;
}