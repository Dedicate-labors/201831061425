#include"pch.h"
#include"NumEssay.h"
#include"myText.h"
#include<string>
#include<cstring>
#include<iostream>
#include<vector>
#include<Windows.h>

using namespace std;
int flag[4] = { 0 }, sum=0;
vector<string> pd(4);


int CheckArgs()
{
	if(sum <=0 || sum > 4) { 
		cout << "��������ȷ�Ĳ�����ʽ" << endl;
		exit(-1);
	} 
	if(!flag[0] || pd[0] != "input.txt") 
	{
		cout << "��������ȷ�ļ���" << endl;
		exit(-1);
	}
	if(!flag[3])
	{     
		cout << "��������ȷ����ļ�" << endl;
		exit(-1);
	}
} 

int main(int argv, char *args[])
{
	char str[][3] = { "-i", "-m", "-n", "-o" };
	//��������
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < argv; j++)
		{
			if (!strcmp(str[i], args[j]))
			{
				flag[i] += 1;
				sum++;
				try {
					j++;
					if (j >= argv)
						throw -1;
					pd[i] = args[j]; //�����±�Խ�������һ������ֵ
				}
				catch (int e)
				{
					cout << "����Ĳ������������Ϊ�յ�" << endl;
					exit(e);
				}
				break;
			}
		}
	}
	//�������Ƿ���ȷ
	CheckArgs();
	
	NumEssay Essay;//��������
	myText T;
	int NChar=0, NLin=0;//�洢�ַ��� ����

	cout << "======================" << endl;
	
	if (flag[0]) //-i 0 д�Ķ�һЩ �����ļ����� ��ӡ������Ϣ
	{
		Essay.read(pd[0]);
		NChar = Essay.charnum();
		NLin = Essay.linenum();
		Essay.print(NLin, NChar);
		T.getfile(pd[0]);
		T.frequency();
	}
	if (flag[1]) //-m 1
	{
		//cout << pd[1] << endl;
		//cout << stoi(pd[1]) << endl;
		T.nWords(stoi(pd[1]));
	}
	if (flag[2]) //-n 2
	{
		//cout << pd[2] << endl;
		//cout << stoi(pd[2]) << endl;
		T.frequency(stoi(pd[2]));
	}
	if (flag[3]) //-o 3 ��ӡ���ļ���
	{
		Essay.print(pd[3], NLin, NChar);
		T.writeToFile(pd[3]);
	}
	return 0;
}
