#include <iostream>
using namespace std;

class SelfRef
{
private:
    int num;
public:
    SelfRef(int n) : num(n) //SelfRef클래스의 맴버변수 num의 값을 n으로 선언해줌(생성자에 멤버이니셜라이저 써 줌)
    {
        cout << "객체생성" << endl;
    }

    SelfRef& Adder(int n) //*this 를 반환하므로 함수의 반환형은 자기참조형임.
    {
        num += n;
        return *this;
    }
    SelfRef& ShowTwoNumber()
    {
        cout << num << endl;
        return *this;
    }
};

int main(void)
{
    SelfRef obj(3); //obj라는 객체가 생성됨. num = 3임.
    SelfRef& ref = obj.Adder(2); //객체 obj에 +2를 해주는 함수의 반환형이 *this이므로(= 참조자를 반환하므로) 참조자 담는 변수 ref를 선언해줌,
    //얕은복사임

    obj.ShowTwoNumber(); //바로 위에서 객체 obj에 +2를 하였으므로, ShowTwoNumber에서 num의 값은 5임.
    ref.ShowTwoNumber(); //변수 ref는 obj.Adder(2)의 값을 담는 변수이므로 마찬가지로 5임.

    ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
    //*this를 반환하는 함수들이므로, ref.Adder(1)이 객체가 되고, -> num값은 6
    //객체.ShowTwoNumber().Adder(2).ShowTwoNumber(); 에서 객체.ShowTwoNumber()로 인해 6을 출력
    // 객체.Adder(2).ShowTwoNumber(); 에서 객체.Adder(2)로 인해 -> num값은 8
    // 객체.ShowTwoNumber(); 형태가 됨.  8을 출력
    //멤버함수를 이런식으로 무한 반복해서 쓸 수 있음..
    return 0;
}