//-----------------------------------------------------------------------------
// STRING.h	- STL의 동작을 이해하기 위한 class / std::string과 유사하게 작성	
//
// 2025. 4. 10 - 시작					
// 2025. 4. 14 - 이동의미론(move semantics) 구현
// 2025. 5. 1 - operator==
// 2025. 5. 15 - begin, end 제공 
// 2025. 5. 19 - rbegin, rend 제공 - class로만 가능
// 2025. 5. 22 - 반복자가 질문에 응답하도록 한다
// 2025. 5. 22 - begiin과 end를 class로 코딩하여 반복자를 return 하도록 한다
// 2025. 5. 26 - sort가능하도록 필요한 연산자를 모두 코딩
//				(c++연산자 오버로딩을 잘 이해해야 할 수 있다)
//-----------------------------------------------------------------------------
#pragma once
#include <memory>
#include <iostream>


//iterator adaptor - 반복자의 인터페이스르 제공하지만 실제로는 다르게 동작
//표준 반복자라면, 제공해야 할 5가지 타입을 제공한다
/*
difference_type	Iter::difference_type
value_type	Iter::value_type
pointer	Iter::pointer
reference	Iter::reference
iterator_category	Iter::iterator_category
*/
class STRING_Reverse_Iterator {
public:
	using difference_type = std::ptrdiff_t;
	using value_type = char;
	using pointer = char*;
	using reference = char&;
	using iterator_category = std::random_access_iterator_tag;

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

class STRING_Iterator {
public:
	using difference_type = std::ptrdiff_t;
	using value_type = char;
	using pointer = char*;
	using reference = char&;
	using iterator_category = std::random_access_iterator_tag;

public:
	//2025. 5. 26
	//special 생성자인 default ctor를 요구
	STRING_Iterator() = default;

	STRING_Iterator(char* p) : p{ p } {};
	

	// 이것의 의미를 제대로 코딩해야한다
	//2025. 5. 26수정
	STRING_Iterator& operator++()
	{
		++p;
		return *this;
	}

	//2025. 5. 26
	// 이 연산의 결과가 l-value가 아니다
	// char-> reference(char&)로 변경, 이후 불변성이 깨지므로 const 제거
	char& operator*()
	{
		return *p;
	}

	//cv-qualifier는 오버로딩으로 구분 가능하다
	char& operator*() const
	{
		return *p;
	}

	//죽였다가 안돼서 다시 살림
	//안되는 이유 알아보기
	bool operator==(const STRING_Iterator& rhs) const 
	{
		return p == rhs.p;
	}


	//sort가 동작하도록 연산자 추가
	
	difference_type operator-(const STRING_Iterator rhs) const
	{
		return p - rhs.p; // 연산의 결과가 클래스의 불변성을 해치나 관찰
	}

	// 멤버 변수가 변하고, 자기 자신을 리턴해 줘야 함으로
	// STRING_iterator&를 반환

	STRING_Iterator& operator--()
	{
		--p;
		return *this;
	}

	// 모든 comparison operation을 할 수 있게 <=>를 정의해 본다
	// <, <=,==, !=, >=, >
	//return type 공부해보기
	auto operator<=>(const STRING_Iterator rhs) const
	{
		return p <=> rhs.p;
	 }
	
	//임시면 충분하기 때문에 &없이
	STRING_Iterator operator+(difference_type n) const
	{
		return p + n;
	}

	STRING_Iterator operator-(difference_type n) const
	{
		return p - n;
	}

private:
	char* p{ }; //=nullptr

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
	STRING_Iterator begin() const;

	STRING_Iterator end() const;

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
