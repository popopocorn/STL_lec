//-------------------------------------------------------------------
// STRING.c++ STL�� ������ �����ϱ� ���� Ŭ���� / std::stirng�� �����ϰ�
// 2025/4/10����
// 2024/4/10 - �������/�����Ҵ�, ������Լ��� ���۰���
//-------------------------------------------------------------------

#include<memory>
#include<print>
#include"STRING.h"

size_t STRING::gid{ 0 };	//2025/4/10 ���� ��ȣ ����

STRING::STRING()
	: id{++gid}
{
	std::println("[{:6}]  {:<16} �ڿ���: {:4}, �ּ�: {:16} �ڿ��� �ּ�: {:16}",
		id, " ����Ʈ ���� ", len, (void*)this, (void*)str.get());
	//		  �̵��Ҵ翬����
}

STRING::~STRING()
{
	std::println("[{:6}]  {:<16} �ڿ���: {:4}, �ּ�: {:16} �ڿ��� �ּ�: {:16}",
		id, " �Ҹ��� ", len, (void*)this, (void*)str.get());
}


STRING::STRING(const char* c) 
	: len{ strlen(c) }, id{ ++gid }
{	
		str.release();							
		str = std::make_unique<char[]>(len);
		memcpy(str.get(), c, len);				
		std::println("[{:6}]  {:<16} �ڿ���: {:4}, �ּ�: {:16} �ڿ��� �ּ�: {:16}",
			id, " ������(char*) ", len, (void*)this, (void*)str.get());
}

STRING::STRING(const STRING& other) :
	len{ other.len }, id{ ++gid }

{
	str.release();
	str = std::make_unique<char[]>(len);
	memcpy(str.get(), other.str.get(), len);
	std::println("[{:6}]  {:<16} �ڿ���: {:4}, �ּ�: {:16} �ڿ��� �ּ�: {:16}",
		id, " ���� ���� ", len, (void*)this, (void*)str.get());
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
	std::println("[{:6}]  {:<16} �ڿ���: {:4}, �ּ�: {:16} �ڿ��� �ּ�: {:16}",
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

