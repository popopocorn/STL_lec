//----------------------------------------------------------------------------
// 2025/1�б� STL
//----------------------------------------------------------------------------
// class STRING �ۼ� ���� - sdt::string ���
// 1.OOPL - Ư�� �ڷ��� ���� ���� �ڵ� - virtual, polymorphism
// 2.Generic - �ڷ����� ���� ���� �ڵ�(�Լ� - alghrothm
//									   Ŭ���� - �ڷᱸ��)
//  �� standard "TEMPLETE" library
//----------------------------------------------------------------------------
#include<iostream>
#include"save.h"
//----------------------------------------------------------------------------
#include<string>
#include<memory>
//----------------------------------------------------------------------------

class STRING {
public:
	STRING(const char* c) : len{ strlen(c) } {	//���ڿ��� t[N] - t*�� collapsing
		str.release();							// ������� �ʱ�ȭ �صθ� �� �ʿ�� ����
		str = std::make_unique<char[]>(len);
		memcpy(str.get(), c, len);					// DMA�� ������ ���
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

	STRING s{ "std::string�� ����� Ŭ����" };

	std::cout << "s�� �����ϴ� ����Ʈ �� - " << s.size() << std::endl;

	//STRING t = s;

	
	std::cout << s <<std::endl;
	//std::cout << t <<std::endl;

	save("main.cpp");
}

