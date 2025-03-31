//----------------------------------------------------------------------------
// 2025/1�б� STL
//----------------------------------------------------------------------------
// Callable - ȣ�� ������ Ÿ��
// 1.�Լ�
//----------------------------------------------------------------------------
#include<iostream>
#include"save.h"
//----------------------------------------------------------------------------
#include<array>
#include<random>
#include<print>
#include<ranges>
#include<algorithm>
#include<chrono>
//----------------------------------------------------------------------------
std::default_random_engine dre;
std::uniform_int_distribution uid{ 0, 9'999'999 };


// [����] ���� int��[ 0, 10'000'000 ) 1000������ ������ �޸𸮸� Ȯ���ϰ�, ���� ä����
// ���� - qsort�� �������� �����϶�
// ���� ��� ��, �տ��� 1000���� ����϶�
// 

std::array<int, 10'000'000> arr;

bool ��������(int a, int b) { // const�� �ٿ��� �Ⱥٿ��� ��� ����
	return a > b;
}

int main() {
	for (int& i : arr) {
		i = uid(dre);
	}
	//sort�� �������� ���� 
	//�ð��� ����
	auto b = std::chrono::high_resolution_clock::now();
	sort(arr.begin(), arr.end(), ��������);
	auto e = std::chrono::high_resolution_clock::now();

	std::cout << "���Ľð�: " << e - b << std::endl;
	
	for (int num : arr | std::views::take(1000)) {
		std::print("{:8}", num);
	}
	save("main.cpp");
}