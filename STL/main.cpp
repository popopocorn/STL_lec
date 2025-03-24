//----------------------------------------------------------------------------
// 2025/1�б� STL
//----------------------------------------------------------------------------
// ���� ���� �ڷ� �ٷ�� - Dog�� �а� �� �� �ֱ�
//----------------------------------------------------------------------------
#include<iostream>
#include"save.h"
//----------------------------------------------------------------------------
#include<string>
#include<fstream>
#include<array>
//----------------------------------------------------------------------------


// ���� Dog 10�� �������� Dog��ü 10������ ����Ǿ� �ִ�
// ������ binary���� ������, Dog ��ü�� ������ write �Լ��� ����Ͽ� �޸𸮿� �����Ͽ���.
// �����ڵ尡 �������� ���� �� �� �ֵ��� �ʿ��� �ڵ��� �߰��϶�

class Dog {
public:
	friend std::ostream& operator<<(std::ostream& os, const Dog& dog) {
		os << "id - " << dog.id << ", name: " << dog.name << std::endl;
		return os;
	}
	friend std::istream& operator>>(std::istream& is, Dog& dog) {
		
		return is.read((char*)&dog, sizeof(dog));
	}
private:
	std::string name;
	int id;
};

std::array < Dog, 100'000> dogs;

int main() {
	
	std::ifstream in{ "Dog 10�� ����", std::ios::binary };
	if (not in) {
		std::cout << "������ ���� ���߽��ϴ�\n";
		return 20250324;
	}

	for (int i = 0; i < dogs.size(); ++i) {
		in >> dogs[i];
	}

	//���
	for (const Dog& dog : dogs) {
		std::cout << dog;
	}

	save("main.cpp");
	
}