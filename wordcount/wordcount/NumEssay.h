#pragma once
#include"pch.h"
#include<string>
#include<fstream>

class NumEssay { //������, ȫ����public ��privated
public:
	void read(std::string file_name) {
		this->file_name = file_name;
	}
	int linenum();
	int charnum();
	//�������
	void print(int &lnum, int &chnum);//�ն�չʾ
	void print(const std::string &out_file, int &lnum, int &chnum);//���뵽�ļ�
private:
	std::string file_name; //�洢�ļ���
	std::string buffer; // �洢�ڴ�
	std::fstream in, out;//in �������룬 out�������
};


