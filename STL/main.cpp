//----------------------------------------------------------------------------
// 2025/1학기 STL
//----------------------------------------------------------------------------
// 많은 수의 자료 다루기 - Dog를 읽고 쓸 수 있기
//----------------------------------------------------------------------------
#include<iostream>
#include"save.h"
//----------------------------------------------------------------------------
#include<string>
#include<fstream>
#include<array>
//----------------------------------------------------------------------------


// 파일 Dog 10만 마리에는 Dog객체 10만개가 저장되어 있다
// 파일은 binary모드로 열었고, Dog 객체는 파일의 write 함수를 사용하여 메모리에 저장하였다.
// 메인코드가 수정없이 실행 될 수 있도록 필요한 코딩을 추가하라

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
	
	std::ifstream in{ "Dog 10만 마리", std::ios::binary };
	if (not in) {
		std::cout << "파일을 읽지 못했습니다\n";
		return 20250324;
	}

	for (int i = 0; i < dogs.size(); ++i) {
		in >> dogs[i];
	}

	//출력
	for (const Dog& dog : dogs) {
		std::cout << dog;
	}

	save("main.cpp");
	
}