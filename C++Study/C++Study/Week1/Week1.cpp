#include <iostream>
using namespace std;

class nameCard {
    //변수는 private으로 지정
    string* person_name, * company_name, * phone_number; //성명, 회사 이름, 전화번호 //동적할당은 포인터 선언을 해줘야 함.
public: //생성자와 소멸자는 public으로 지정
    void ShowNameCardInfo(); //함수는 메인함수에서 인자를 받아야하므로 private으로 선언하면 오류남. 
    nameCard(string person_name, string company_name, string phone_number); //생성자도 하나의 함수이므로 매개변수 써줘야 함.
    ~nameCard();
};

nameCard::nameCard(string person_name, string company_name, string phone_number)
    :person_name(new string(person_name)), company_name(new string(company_name)), phone_number(new string(phone_number)) //멤버이니셜라이저 사용
{ //동적할당하는 생성자
    /*string* person_name = new string;  -> 이렇게 하면 안 됨.  NameCard에 이미 선언된 거를 또 선언해주는 꼴..
    string* company_name = new string;
    string* phone_number = new string;*/
    //멤버이니셜라이저 사용하면 this 사용 안해도 됨, 멤버이니셜라이저는 함수 내에서 선언x 함수 밖에서
}

nameCard::~nameCard() { //동적할당을 해제하는 소멸자
    delete person_name;
    delete company_name;
    delete phone_number;
}

void nameCard::ShowNameCardInfo() {
    cout << "이름 : " << *(this->person_name) << '\n'; //person_name이 포인터 변수이므로 this ->임. 그냥 변수일 때는 마침표쓰면 됨. 
    cout << "회사 : " << *company_name << '\n'; //애스터리스크 안 쓰면 company_name의 주소값이 나옴
    cout << "전화번호 : " << *phone_number << '\n';
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