//----------------------------------------------------------------------------
// 2025/1학기 STL
//----------------------------------------------------------------------------
// Callable - 호출 가능한 타입
// 1.함수
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


// [문제] 랜덤 int값[ 0, 10'000'000 ) 1000만개를 저장할 메모리를 확보하고, 값을 채워라
// 시작 - qsort로 오름차순 정렬하라
// 정렬 결과 중, 앞에서 1000개만 출력하라
// 

std::array<int, 10'000'000> arr;

bool 내림차순(int a, int b) { // const를 붙여도 안붙여도 상관 없다
	return a > b;
}

int main() {
	for (int& i : arr) {
		i = uid(dre);
	}
	//sort로 내림차순 정렬 
	//시간을 보자
	auto b = std::chrono::high_resolution_clock::now();
	sort(arr.begin(), arr.end(), 내림차순);
	auto e = std::chrono::high_resolution_clock::now();

	std::cout << "정렬시간: " << e - b << std::endl;
	
	for (int num : arr | std::views::take(1000)) {
		std::print("{:8}", num);
	}
	save("main.cpp");
}