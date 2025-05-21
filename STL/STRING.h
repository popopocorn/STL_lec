//-----------------------------------------------------------------------------
// STRING.h	- STL의 동작을 이해하기 위한 class / std::string과 유사하게 작성	
//
// 2025. 4. 10 - 시작					
// 2025. 4. 14 - 이동의미론(move semantics) 구현
// 2025. 5. 1 - operator==
// 2025. 5. 15 - begin, end 제공
// 2025. 5. 19 - rbegin, rend 제공 - class로만 가능
//-----------------------------------------------------------------------------
#pragma once
#include <memory>
#include <iostream>


//iterator adaptor - 반복자의 인터페이스르 제공하지만 실제로는 다르게 동작
class STRING_Reverse_Iterator {
public:
	explicit STRING_Reverse_Iterator(char* p) : p{ p } {};
	//반복자라면 제공해야할 기본동작이 있다
	void operator++() {
		--p;
	}
	char operator*() const {
		 return *(p - 1);
	}
	bool operator==(STRING_Reverse_Iterator& rhs) const{
		return p == rhs.p;
	}
	

private:
	char* p;

};

class STRING {
public:
	STRING();
	~STRING();

	STRING(const char* str);		// 생성자

	// 복사생성자와 복사할당연산자  2025. 4. 10
	STRING(const STRING&);
	STRING& operator=(const STRING&);

	// 이동생성자와 이동할당연산자	- 2025. 4. 14
	STRING(STRING&&);
	STRING& operator=(STRING&&);

	// 기본정렬을 위한 < - 2025. 4. 14
	// 사전식 정렬을 위한 수정 < - 2025. 5. 15
	bool operator<(const STRING& rhs) const;

	// 같은 객체인지 비교 == - 2025. 5. 1
	bool operator==(const STRING& rhs) const;

	size_t size() const;

	//2025. 5. 15
	char* begin() const;

	char* end() const;

	//2025. 5. 19
	STRING_Reverse_Iterator rbegin() const;

	STRING_Reverse_Iterator rend() const;
	


private:
	size_t num{};
	std::unique_ptr<char[]> p{};

	size_t id;				// 2025. 4. 10 관찰을 위한 객체 고유번호

	friend std::ostream& operator<<(std::ostream&, const STRING&);

	friend std::istream& operator>>(std::istream&, STRING&);		// 2025. 4. 14

	static size_t gid;		// 2025. 4. 10 고유번호 생성
};
