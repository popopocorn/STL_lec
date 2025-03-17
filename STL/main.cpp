//----------------------------------------------------------------------------
// 2025/1�б� STL
// 3.10 ������	(1���� 2��)
//----------------------------------------------------------------------------
// Generic Programming - �ٽ�Ű���� Template
//----------------------------------------------------------------------------
#include<iostream>
#include"save.h"


// template�� ����� ���Ǹ� ���ÿ� �ؾ���
template<typename t> // 
void change(t& x, t& y); 
class Dog {
public:
	Dog() = default;
	Dog(int n) : age{ n } {}
	friend std::ostream& operator<<(std::ostream& os, const Dog& d) {
		return os << d.age;
	}
private:
	int age;
};

int main() {

	{
		Dog a{ 1 }, b{ 2 };
		change(a, b); //�� �����ϴ°���
		//1.change(Dog, Dog)
		//2.change(Dog&, Dog&)
		//3.�����Ϸ��� ���� ���� - template

		std::cout << a << ", " << b << std::endl;
	}

	{
		int a{ 1 }, b{ 2 };
		change(a, b); //ab�ٲٱ�

		std::cout << a << ", " << b << std::endl;
	}

	save("main.cpp");

}
template<typename t>
void change(t& x, t& y) {
	t temp{ x };
	x = y;
	y = temp;
}