#include"pch.h"
#include"NumEssay.h"
#include<ios>
#include<cstdio>
#include<string>
#include<iostream>


int NumEssay::linenum() // �������
{
	in.open(file_name, std::ios::in);
	int count = 0;
	if (in.is_open()) //����ļ��Ƿ��
	{
		while (!in.eof())
		{
			if (in.good()) ///����ļ����ԣ��ͼ�������
			{
				getline(in, buffer);
				if (buffer != "")
					++count;
			}
			else
			{
				std::cout << "Error:��ȡ���ļ����ܹ����ڴ��޷��洢" << std::endl;
			}
		}
	}
	else
	{
		std::cout << "Open " << file_name << "failing!!!" << std::endl;
	}
	in.close();
	return count;
}

int NumEssay::charnum()
{
	in.open(file_name, std::ios::in);
	int count = 0;
	if (in.is_open())//����ļ��Ƿ��
	{
		while (!in.eof())
		{
			if (in.good())//����ļ����ԣ��ͼ�������
			{
				getline(in, buffer);
				if (buffer != "")
				{
					count += buffer.size();
					if (!in.eof())
						count += 1; //���ϻ��з�
				}
				else if (!in.eof())//bufferΪ�գ�����Ϊ���з�, 
				{
					count += 1;
				}
			}
			else
			{
				std::cout << "Error:��ȡ���ļ��д���" << std::endl;
			}
		}
	}
	else
	{
		std::cout << "Open " << file_name << "failing!!!" << std::endl;
	}
	in.close();
	return count;
}

void  NumEssay::print(int &lnum, int &chnum)//���д�ӡ
{
	std::cout << "������" << lnum << std::endl;
	std::cout << "�ַ�����" << chnum << std::endl;
}

void NumEssay::print(const std::string &out_file, int &lnum, int &chnum)//��ӡ���ļ���
{
	out.open(out_file, std::ios::out);
	out << "������" << lnum << "\n";
	out << "�ַ�����" << chnum << "\n";
	out.close();
	std::cout << "����ɹ�!" << std::endl;
}