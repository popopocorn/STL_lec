//----------------------------------------------------------------------------
// 2025/1학기 STL
//----------------------------------------------------------------------------
// class STRING 작성 시작 - sdt::string 모방
// 1.OOPL - 특정 자료형 만을 위한 코딩 - virtual, polymorphism
// 2.Generic - 자료형과 관계 없는 코딩(함수 - alghrothm
//									   클래스 - 자료구조)
//  ㄴ standard "TEMPLETE" library
//----------------------------------------------------------------------------
#include<iostream>
#include"save.h"
//----------------------------------------------------------------------------
#include<string>
#include<memory>
//----------------------------------------------------------------------------

class STRING {
public:
	STRING(const char* c) : len{ strlen(c) } {	//인자에서 t[N] - t*로 collapsing
		str.release();							// 멤버에서 초기화 해두면 할 필요는 없음
		str = std::make_unique<char[]>(len);
		memcpy(str.get(), c, len);					// DMA가 가능한 명령
	}

	size_t size() const {
		return len;
	}
private:
	std::unique_ptr<char[]> str{};
	size_t len{};


	friend std::ostream& operator<<(std::ostream& os, const STRING& s) {
		for (int i = 0; i < s.len; ++i) {
			os << s.str[i];
		}
		return os;
	}

};
int main() {

	STRING s{ "std::string을 모방한 클래스" };

	std::cout << "s가 관리하는 바이트 수 - " << s.size() << std::endl;

	//STRING t = s;

	
	std::cout << s <<std::endl;
	//std::cout << t <<std::endl;

	save("main.cpp");
}

