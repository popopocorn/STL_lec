//-------------------------------------------------------------------
// STRING.h - STL의 동작을 이해하기 위한 클래스 / std::stirng과 유사하게
// 2025/4/10시작
//-------------------------------------------------------------------


#pragma once
#include<memory>
#include<iostream>




class STRING {
public:

	STRING();		//진짜 스페셜 함수
	~STRING();		//코딩할 이유가 없는 class 관찰용


	STRING(const char* c);	//그냥 생성자

			

	//복사 생성자와 복사할당 연산자 - 0410
	STRING(const STRING& other);
	STRING& operator=(const STRING& other);
	 
	
	size_t size() const;

private:
	size_t len{};
	std::unique_ptr<char[]> str{};
	size_t id;			//2025/4/10 관찰을위한 객체 고유 번호


	friend std::ostream& operator<<(std::ostream& os, const STRING& s);


	static size_t gid;	//2025/4/10 고유 번호 생성
};