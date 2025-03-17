//----------------------------------------------------------------------------
// 2025/1학기 STL
// 3.10 월요일	(1주차 2일)
//----------------------------------------------------------------------------
// Generic Programming - 핵심키워드 Template
//----------------------------------------------------------------------------
#include<iostream>
#include"save.h"


// template은 선언과 정의를 동시에 해야함
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
		change(a, b); //뭘 실행하는거임
		//1.change(Dog, Dog)
		//2.change(Dog&, Dog&)
		//3.컴파일러가 직접 생성 - template

		std::cout << a << ", " << b << std::endl;
	}

	{
		int a{ 1 }, b{ 2 };
		change(a, b); //ab바꾸기

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