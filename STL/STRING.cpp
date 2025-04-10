//-------------------------------------------------------------------
// STRING.c++ STL의 동작을 이해하기 위한 클래스 / std::stirng과 유사하게
// 2025/4/10시작
// 2024/4/10 - 복사생성/복사할당, 스페셜함수의 동작관찰
//-------------------------------------------------------------------

#include<memory>
#include<print>
#include"STRING.h"

size_t STRING::gid{ 0 };	//2025/4/10 고유 번호 생성

STRING::STRING()
	: id{++gid}
{
	std::println("[{:6}]  {:<16} 자원수: {:4}, 주소: {:16} 자원의 주소: {:16}",
		id, " 디폴트 생성 ", len, (void*)this, (void*)str.get());
	//		  이동할당연산자
}

STRING::~STRING()
{
	std::println("[{:6}]  {:<16} 자원수: {:4}, 주소: {:16} 자원의 주소: {:16}",
		id, " 소멸자 ", len, (void*)this, (void*)str.get());
}


STRING::STRING(const char* c) 
	: len{ strlen(c) }, id{ ++gid }
{	
		str.release();							
		str = std::make_unique<char[]>(len);
		memcpy(str.get(), c, len);				
		std::println("[{:6}]  {:<16} 자원수: {:4}, 주소: {:16} 자원의 주소: {:16}",
			id, " 생성자(char*) ", len, (void*)this, (void*)str.get());
}

STRING::STRING(const STRING& other) :
	len{ other.len }, id{ ++gid }

{
	str.release();
	str = std::make_unique<char[]>(len);
	memcpy(str.get(), other.str.get(), len);
	std::println("[{:6}]  {:<16} 자원수: {:4}, 주소: {:16} 자원의 주소: {:16}",
		id, " 복사 생성 ", len, (void*)this, (void*)str.get());
}


STRING& STRING::operator=(const STRING& other) 
{
	if (this == &other) {
		return *this;
	}

	len = other.len;
	str.release();
	str = std::make_unique<char[]>(len);
	memcpy(str.get(), other.str.get(), len);
	std::println("[{:6}]  {:<16} 자원수: {:4}, 주소: {:16} 자원의 주소: {:16}",
		id, " copy operator= ", len, (void*)this, (void*)str.get());
	return *this;
}

size_t STRING::size() const {
		return len;
}

std::ostream& operator<<(std::ostream& os, const STRING& s) {
		for (int i = 0; i < s.len; ++i) {
			os << s.str[i];
		}
		return os;
}

