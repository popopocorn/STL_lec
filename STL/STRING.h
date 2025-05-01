//-----------------------------------------------------------------------------
// STRING.h	- STL�� ������ �����ϱ� ���� class / std::string�� �����ϰ� �ۼ�	
//
// 2025. 4. 10 - ����					
// 2025. 4. 14 - �̵��ǹ̷�(move semantics) ����
// 2025. 5. 1 - operator==
//-----------------------------------------------------------------------------
#pragma once
#include <memory>
#include <iostream>

class STRING {
public:
	STRING();
	~STRING();

	STRING(const char* str);		// ������

	// ��������ڿ� �����Ҵ翬����  2025. 4. 10
	STRING(const STRING&);
	STRING& operator=(const STRING&);

	// �̵������ڿ� �̵��Ҵ翬����	- 2025. 4. 14
	STRING(STRING&&);
	STRING& operator=(STRING&&);

	// �⺻������ ���� < - 2025. 4. 14
	bool operator<(const STRING& rhs) const;

	// ���� ��ü���� �� == - 2025. 5. 1
	bool operator==(const STRING& rhs) const;

	size_t size() const;

private:
	size_t num{};
	std::unique_ptr<char[]> p{};

	size_t id;				// 2025. 4. 10 ������ ���� ��ü ������ȣ

	friend std::ostream& operator<<(std::ostream&, const STRING&);

	friend std::istream& operator>>(std::istream&, STRING&);		// 2025. 4. 14

	static size_t gid;		// 2025. 4. 10 ������ȣ ����
};
