#pragma once
#include"pch.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;
class myText
{
public:
	myText();
	~myText();
	void getfile(string path);//��ö�ȡ���ļ�
	void frequency();//����������ǰ10��Ƶ����ߵĵ���
	void frequency(int n);//Ƶ����ߵ�ǰn������
	void nWords(int n);//�ַ�Ϊn�ĵ��ʸ�����Ƶ��
	void writeToFile(string path);//д���ļ�
private:
	ifstream ifile;
	string path;

};
