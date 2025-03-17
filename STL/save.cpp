//-------------------------------------------------------------------
// save.cpp - 한학기 강의를 저장
//														   2025.03.13
//-------------------------------------------------------------------


#include<string_view>
#include<fstream>
#include<iostream>
#include<filesystem>
#include<chrono>
#include "save.h"

void save(std::string_view file_name) {
	//1.인자로 전달된 file_name을 읽기 모드로 열기
	std::ifstream in{ file_name.data() };	//RAII, 자원획득시 초기화
	if (not in) {
		std::cout << "Failed to read " << file_name << std::endl;
		// exit(404); 요즘 사용X
	}
	in >> std::noskipws;

	// 저장했다는 것을 화면에 표시하자
	std::cout << file_name << "(" << std::filesystem::file_size(file_name)
		<< "bytes) 저장하였습니다.\n";


	//2.쓰기 모드로 저장할 파일을 덧붙이기 모드로 열기
	std::ofstream out{ "2025년 1학기 STL 강의저장.txt", std::ios::app }; // {}uniform initializer
	//시간을 기록
	auto now = std::chrono::system_clock::now();			//epoch로부터 경과된 tick 수
	auto utc = std::chrono::system_clock::to_time_t(now);	//UTC로 변환
	auto lt = std::localtime(&utc);							//os의 지역시간으로 변경
	auto old = out.imbue(std::locale("ko_KR"));				//stream의 지역을 변경

	out << "\n" << "\n";
	out << "==============================================================================================================================\n";
	out << "저장한 시간: " << std::put_time(lt, "%c, %A") << '\n';
	out << "==============================================================================================================================\n\n";
	out.imbue(old);											//복구
	//3.쓸 파일을 읽어서 저장할 파일에 덧붙인다.
	std::copy(std::istreambuf_iterator{ in }, {}, std::ostreambuf_iterator(out));
}
