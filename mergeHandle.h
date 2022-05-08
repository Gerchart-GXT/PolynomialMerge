#include "Linklist.h"
#include "Polynomial.h"

Linklist* buidLinklist()
{
    auto list = new Linklist();
    return list;
}

bool insertWithNewItem(Linklist* list, Polynomial* val)
{
    auto tnode = new Linklist(val, list->getNext());
    list->changeNext(tnode);
    return true;
}
bool insertWithOldItem(Linklist* list, Polynomial* val)
{
    auto tval = (Polynomial*)list->getVal();
    // std::cout << tval->getPow() << std::endl;
    tval->mergeItem(val);
    return true;
}
Linklist* findInsertPosition(Linklist* list, Polynomial* val)
{
    while (list->getNext() != nullptr) {
        auto tlist = list->getNext();
        auto tval = (Polynomial*)tlist->getVal();
        if (tval->getPow() == val->getPow()) {
            return tlist;
        } else if (tval->getPow() < val->getPow())
            break;
        list = list->getNext();
    }
    return list;
}

Linklist* divIntoList(Linklist* list, std::string s)
{
    using namespace std;
    {
        int len = s.length();
        int ps = 0;
        while (ps < len) {
            int k = 0, pow = 0;
            string ss;

            bool flag = false;
            if (ps < len && s[ps] == '+')
                ps++;
            if (ps < len && s[ps] == '-') {
                flag = true;
                ps++;
            }
            if (ps < len && s[ps] <= '9' && s[ps] >= '0') {
                while (ps < len && s[ps] <= '9' && s[ps] >= '0') {
                    k *= 10;
                    k += s[ps++] - '0';
                }
            } else
                k = 1;
            if (flag)
                k = -k;

            ss += s[ps++];
            flag = false;
            if ((ps < len && s[ps] != '{') || ps == len) {
                pow = 1;
            } else {
                ps++;
                if (ps < len && s[ps] == '-') {
                    flag = true;
                    ps++;
                }
                while (ps < len && s[ps] != '}') {
                    pow *= 10;
                    pow += s[ps++] - '0';
                }
                ps++;
                if (flag)
                    pow = -pow;
            }
            auto tval = new Polynomial(k, ss, pow);
            auto tplist = findInsertPosition(list, tval);
            auto tpval = (Polynomial*)tplist->getVal();
            if (tpval != nullptr && tpval->canMerge(tval)) {
                insertWithOldItem(tplist, tval);
            } else {
                insertWithNewItem(tplist, tval);
            }
        }
    }
    return list;
}

void printAllItems(Linklist* list)
{
    bool flag = false;
    while (list->getNext() != nullptr) {
        auto tlist = list->getNext();
        list = list->getNext();
        auto tval = (Polynomial*)tlist->getVal();
        if (tval->getK() == 0) {
            if (list->getNext() != nullptr)
                list = list->getNext();
            delete tlist;
            continue;
        }
        flag = true;
        std::cout << tval->print();
        if (list->getNext() != nullptr)
            std::cout << '+';
    }
    if (!flag)
        std::cout << 0;
    return;
}