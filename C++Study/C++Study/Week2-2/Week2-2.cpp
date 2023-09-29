#include <iostream>
using namespace std;


class SelfRef
{
private:
    int* num;
public:
    SelfRef(int n) : num(new int(n))
    {
        cout << "°´Ã¼»ý¼º" << endl;
    }
    SelfRef(const SelfRef& obj) {
        num = new int(*obj.num);
    }
    void setNumber()
    {
        *num += 1;
    }
    void ShowTwoNumber()
    {
        cout << *num << endl;
    }
};

int main(void)
{
    SelfRef obj(3);
    SelfRef obj2(obj);

    obj.setNumber();

    obj.ShowTwoNumber();
    obj2.ShowTwoNumber();
    return 0;
}