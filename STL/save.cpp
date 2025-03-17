//-------------------------------------------------------------------
// save.cpp - ���б� ���Ǹ� ����
//														   2025.03.13
//-------------------------------------------------------------------


#include<string_view>
#include<fstream>
#include<iostream>
#include<filesystem>
#include<chrono>
#include "save.h"

void save(std::string_view file_name) {
	//1.���ڷ� ���޵� file_name�� �б� ���� ����
	std::ifstream in{ file_name.data() };	//RAII, �ڿ�ȹ��� �ʱ�ȭ
	if (not in) {
		std::cout << "Failed to read " << file_name << std::endl;
		// exit(404); ���� ���X
	}
	in >> std::noskipws;

	// �����ߴٴ� ���� ȭ�鿡 ǥ������
	std::cout << file_name << "(" << std::filesystem::file_size(file_name)
		<< "bytes) �����Ͽ����ϴ�.\n";


	//2.���� ���� ������ ������ �����̱� ���� ����
	std::ofstream out{ "2025�� 1�б� STL ��������.txt", std::ios::app }; // {}uniform initializer
	//�ð��� ���
	auto now = std::chrono::system_clock::now();			//epoch�κ��� ����� tick ��
	auto utc = std::chrono::system_clock::to_time_t(now);	//UTC�� ��ȯ
	auto lt = std::localtime(&utc);							//os�� �����ð����� ����
	auto old = out.imbue(std::locale("ko_KR"));				//stream�� ������ ����

	out << "\n" << "\n";
	out << "==============================================================================================================================\n";
	out << "������ �ð�: " << std::put_time(lt, "%c, %A") << '\n';
	out << "==============================================================================================================================\n\n";
	out.imbue(old);											//����
	//3.�� ������ �о ������ ���Ͽ� �����δ�.
	std::copy(std::istreambuf_iterator{ in }, {}, std::ostreambuf_iterator(out));
}
