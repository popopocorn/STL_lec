//-------------------------------------------------------------------
// STRING.h - STL�� ������ �����ϱ� ���� Ŭ���� / std::stirng�� �����ϰ�
// 2025/4/10����
//-------------------------------------------------------------------


#pragma once
#include<memory>
#include<iostream>




class STRING {
public:

	STRING();		//��¥ ����� �Լ�
	~STRING();		//�ڵ��� ������ ���� class ������


	STRING(const char* c);	//�׳� ������

			

	//���� �����ڿ� �����Ҵ� ������ - 0410
	STRING(const STRING& other);
	STRING& operator=(const STRING& other);
	 
	
	size_t size() const;

private:
	size_t len{};
	std::unique_ptr<char[]> str{};
	size_t id;			//2025/4/10 ���������� ��ü ���� ��ȣ


	friend std::ostream& operator<<(std::ostream& os, const STRING& s);


	static size_t gid;	//2025/4/10 ���� ��ȣ ����
};