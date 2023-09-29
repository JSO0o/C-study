#include <iostream>
using namespace std;

class SelfRef
{
private:
    int num;
public:
    SelfRef(int n) : num(n) //SelfRefŬ������ �ɹ����� num�� ���� n���� ��������(�����ڿ� ����̴ϼȶ����� �� ��)
    {
        cout << "��ü����" << endl;
    }

    SelfRef& Adder(int n) //*this �� ��ȯ�ϹǷ� �Լ��� ��ȯ���� �ڱ���������.
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
    SelfRef obj(3); //obj��� ��ü�� ������. num = 3��.
    SelfRef& ref = obj.Adder(2); //��ü obj�� +2�� ���ִ� �Լ��� ��ȯ���� *this�̹Ƿ�(= �����ڸ� ��ȯ�ϹǷ�) ������ ��� ���� ref�� ��������,
    //����������

    obj.ShowTwoNumber(); //�ٷ� ������ ��ü obj�� +2�� �Ͽ����Ƿ�, ShowTwoNumber���� num�� ���� 5��.
    ref.ShowTwoNumber(); //���� ref�� obj.Adder(2)�� ���� ��� �����̹Ƿ� ���������� 5��.

    ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
    //*this�� ��ȯ�ϴ� �Լ����̹Ƿ�, ref.Adder(1)�� ��ü�� �ǰ�, -> num���� 6
    //��ü.ShowTwoNumber().Adder(2).ShowTwoNumber(); ���� ��ü.ShowTwoNumber()�� ���� 6�� ���
    // ��ü.Adder(2).ShowTwoNumber(); ���� ��ü.Adder(2)�� ���� -> num���� 8
    // ��ü.ShowTwoNumber(); ���°� ��.  8�� ���
    //����Լ��� �̷������� ���� �ݺ��ؼ� �� �� ����..
    return 0;
}