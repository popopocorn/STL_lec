//-----------------------------------------------------------------------------
// STRING.cpp	- STL�� ������ �����ϱ� ���� class / std::string�� �����ϰ� �ۼ�	
//
// 2025. 4. 10 - ����		
// 2025. 4. 10 - �������/�����Ҵ翬����, ����� �Լ��� ���� ����	
// 2025. 4. 14 - ������ �����ϵ��� ���������� ���	
// 2025. 4. 14 - �̵��ǹ̷�(move semantics) ���� 	
//-----------------------------------------------------------------------------
#include <memory>
#include <print>
#include "STRING.h"

size_t STRING::gid{ 0 };			// 2025. 4. 10 ������ȣ ����
bool ����{ false };

STRING::STRING()
	: id{ ++gid }
{
	if (����) {
		std::println("[{:6}] {:<16} �ڿ���:{:4}, �ּ�:{:16} �ڿ��� �ּ�:{:16}",
			id, "����Ʈ����", num, (void*)this, (void*)p.get());
	}
}

STRING::~STRING()
{
	if (����) {
		std::println("[{:6}] {:<16} �ڿ���:{:4}, �ּ�:{:16} �ڿ��� �ּ�:{:16}",
			id, "�Ҹ���", num, (void*)this, (void*)p.get());
	}
}

STRING::STRING(const char* str)
	: num{ strlen(str) }, id{ ++gid }
{
	p.release();
	p = std::make_unique<char[]>(num);
	memcpy(p.get(), str, num);

	if (����) {
		std::println("[{:6}] {:<16} �ڿ���:{:4}, �ּ�:{:16} �ڿ��� �ּ�:{:16}",
			id, "������(char*)", num, (void*)this, (void*)p.get());
	}
};

// ��������ڿ� �����Ҵ翬����  2025. 4. 10
STRING::STRING(const STRING& other)
	: num{ other.num }, id{ ++gid }
{
	p = std::make_unique<char[]>(num);
	memcpy(p.get(), other.p.get(), num);

	if (����) {
		std::println("[{:6}] {:<16} �ڿ���:{:4}, �ּ�:{:16} �ڿ��� �ּ�:{:16}",
			id, "���������", num, (void*)this, (void*)p.get());
	}
}

STRING& STRING::operator=(const STRING& other)
{
	if (this == &other)
		return *this;

	num = other.num;

	p.release();
	p = std::make_unique<char[]>(num);
	memcpy(p.get(), other.p.get(), num);

	if (����) {
		std::println("[{:6}] {:<16} �ڿ���:{:4}, �ּ�:{:16} �ڿ��� �ּ�:{:16}",
			id, "copy operator=", num, (void*)this, (void*)p.get());
	}

	return *this;
}

// �̵������ڿ� �̵��Ҵ翬����	- 2025. 4. 14
STRING::STRING(STRING&& other)
	: num{ other.num }, id{ ++gid }
{
	p.reset(other.p.release());

	//	other.num = 0;			// �� �ص� �ȴ�

	if (����) {
		std::println("[{:6}] {:<16} �ڿ���:{:4}, �ּ�:{:16} �ڿ��� �ּ�:{:16}",
			id, "�̵�������", num, (void*)this, (void*)p.get());
	}
}

STRING& STRING::operator=(STRING&& other)
{
	if (this == &other)
		return *this;

	num = other.num;
	p.release();		// ���� Ȯ���� �ڿ��� ����
	p.reset(other.p.release());

	//	other.num = 0;			// �� �ص� ��

	if (����) {
		std::println("[{:6}] {:<16} �ڿ���:{:4}, �ּ�:{:16} �ڿ��� �ּ�:{:16}",
			id, "move operator=", num, (void*)this, (void*)p.get());
	}
	return *this;
}


// �⺻������ ���� < - 2025. 4. 14
bool STRING::operator<(const STRING& rhs) const
{
	return size() < rhs.size();
}

size_t STRING::size() const
{
	return num;
}

std::ostream& operator<<(std::ostream& os, const STRING& s)
{
	for (int i = 0; i < s.num; ++i)
		os << s.p[i];
	return os;
}

std::istream& operator>>(std::istream& is, STRING& s) 		// 2025. 4. 14
{
	std::string str;
	is >> str;

	s.num = str.size();
	s.p.release();
	s.p = std::make_unique<char[]>(s.num);
	memcpy(s.p.get(), str.data(), s.num);

	return is;
}