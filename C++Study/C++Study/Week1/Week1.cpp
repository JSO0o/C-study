#include <iostream>
using namespace std;

class nameCard {
    //������ private���� ����
    string* person_name, * company_name, * phone_number; //����, ȸ�� �̸�, ��ȭ��ȣ //�����Ҵ��� ������ ������ ����� ��.
public: //�����ڿ� �Ҹ��ڴ� public���� ����
    void ShowNameCardInfo(); //�Լ��� �����Լ����� ���ڸ� �޾ƾ��ϹǷ� private���� �����ϸ� ������. 
    nameCard(string person_name, string company_name, string phone_number); //�����ڵ� �ϳ��� �Լ��̹Ƿ� �Ű����� ����� ��.
    ~nameCard();
};

nameCard::nameCard(string person_name, string company_name, string phone_number)
    :person_name(new string(person_name)), company_name(new string(company_name)), phone_number(new string(phone_number)) //����̴ϼȶ����� ���
{ //�����Ҵ��ϴ� ������
    /*string* person_name = new string;  -> �̷��� �ϸ� �� ��.  NameCard�� �̹� ����� �Ÿ� �� �������ִ� ��..
    string* company_name = new string;
    string* phone_number = new string;*/
    //����̴ϼȶ����� ����ϸ� this ��� ���ص� ��, ����̴ϼȶ������� �Լ� ������ ����x �Լ� �ۿ���
}

nameCard::~nameCard() { //�����Ҵ��� �����ϴ� �Ҹ���
    delete person_name;
    delete company_name;
    delete phone_number;
}

void nameCard::ShowNameCardInfo() {
    cout << "�̸� : " << *(this->person_name) << '\n'; //person_name�� ������ �����̹Ƿ� this ->��. �׳� ������ ���� ��ħǥ���� ��. 
    cout << "ȸ�� : " << *company_name << '\n'; //�ֽ��͸���ũ �� ���� company_name�� �ּҰ��� ����
    cout << "��ȭ��ȣ : " << *phone_number << '\n';
}

int main(void) {
    nameCard manClerk("Lee", "ABCEng", "010-1111-2222");
    nameCard manAsist("Hong", "OrangeEng", "010-3333-4444");
    nameCard manSENIOR("Kim", "soGoodComp", "010-5555-6666");
    manClerk.ShowNameCardInfo();
    cout << '\n';
    manAsist.ShowNameCardInfo();
    cout << '\n';
    manSENIOR.ShowNameCardInfo();

    return 0;
}