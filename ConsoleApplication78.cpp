#include <iostream>
#include <list>     // подключаем заголовок списка
#include <iterator>
using namespace std;

class Detail {
private:

public:
	string name;
	int id = 0, tmp = 0;
	friend class Controller;
	Detail() {
		int defaultId = 1111111;
		id = defaultId;
	}
	void init(const Detail& data) {
		this->id = data.id;
		this->name = data.name;
	}

	int idSetter(int number) {
		id = number;
		return 0;
	}
	void nameSetter(string userName) {
		name = userName;
		return;
	}

	void printDetailInfo() {
		cout << "Id:" << id << endl;
		cout << "Name:" << name << endl;
	}
	int getId() {
		return id;
	}
	friend std::ostream& operator<<(std::ostream& out, const Detail& detail);
};
ostream& operator<<(ostream& out, const Detail& detail) {
	out << "Name: ";
	out << detail.name << '\n';
	out << "Id: ";
	out << detail.id << '\n';
	return out;
}

void idChanger(list<Detail> myList, string name) {
	auto it = myList.begin();
	for (int i = 0; i < myList.size(); i++) {
		if (it->name == name) {
			it->id = 0;
			it->printDetailInfo();
		}
		it++;
	}
}

int main()
{
	Detail object;
	string userName;
	int number = 117;
	int chk = 1;
	list<Detail> myList;
	while (chk != 0) {
		std::cout << "Enter a name of the detail " << '\n';
		cin >> userName;
		object.nameSetter(userName);
		std::cout << "Enter the id of the detail" << '\n';
		std::cin >> number;
		object.idSetter(number);
		std::cout << "wanna continue?                        1/0";
		std::cout << '\n';
		myList.push_back(object);
		cin >> chk;
		if (chk == 0) {
			break;
		}
		std::cout << '\n';
	}
	auto it = myList.begin();
	while (it != myList.end()) {
		it->printDetailInfo();
		it++;
	}
	int size = myList.size();
	it = myList.begin();
	auto it1 = myList.begin();
	int halfeSize = size / 2;
	if (size % 2 == 0) halfeSize--;
	for (int i = 0; i < halfeSize; i++) {
		it++;
		it1++;
	}
	halfeSize++;
	bool isBegin=false, isEnd=false;
	cout << halfeSize<<endl;
	if (size % 2 == 0) it1++;
	for (int i = 0; i < halfeSize; i++) { // qwe 1 1 asd 2 1 zxc 3 1 vbn 4 0
		if (it == it1) {
			it->printDetailInfo();
		}
		if (it != it1) {
			it->printDetailInfo();
			it1->printDetailInfo();
		}
		if(it!=myList.begin())
		it--;
		if (it != myList.end())
		it1++;
	}
	idChanger(myList, "qwe");
}

