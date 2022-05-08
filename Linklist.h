class Linklist {
private:
    void* val;
    Linklist* next;

public:
    Linklist();
    Linklist(void* val, Linklist* next);
    Linklist* getNext();
    bool changeNext(Linklist* next);
    void* getVal();
    bool changeVal(void* val);
};

Linklist::Linklist()
{
    this->val = nullptr;
    this->next = nullptr;
}
Linklist::Linklist(void* val, Linklist* next)
{
    this->val = val;
    this->next = next;
}
Linklist* Linklist::getNext()
{
    return this->next;
}
void* Linklist::getVal()
{
    return this->val;
}
bool Linklist::changeNext(Linklist* next)
{
    this->next = next;
    return true;
}
bool Linklist::changeVal(void* val)
{
    this->val = val;
    return true;
}