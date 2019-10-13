#include "pch.h"
#include"myText.h"
// pch.cpp: ��Ԥ�����ͷ��Ӧ��Դ�ļ�������ɹ��������
typedef pair<string, int> PAIR;

struct cmp
{
	bool operator()(const pair<string, int> &p1, const pair<string, int> &p2)
	{
		return p1.second > p2.second;
	}
};
//���ļ�
void myText::getfile(string path)
{
	this->path = path;
}

//ͳ��Ƶ����ߵ�ǰn������
void myText::frequency(int n)
{
	ifile.open(path);
	string str;
	string sss;
	while (getline(ifile, sss))
	{
		str += sss;
	}
	stringstream ss(str);
	string s;
	vector<string>vt;
	map<string, int>m1;
	while (getline(ss, s, ' '))
	{
		int flag = 0;
		int i = 0;
		int j = 0;
		int k = 0;
		while (i < s.size())
		{
			if (s[i] <= 'z'&& s[i] >= 'a' || s[i] <= 'Z'&& s[i] >= 'A')
			{
				j++;
				if (s[i] <= 'Z'&& s[i] >= 'A')
				{
					s[i] += 32;
				}
			}
			else
			{
				k++;
			}

			if (j < 4 && k>0)
			{
				i++;
				flag = 0;
				break;
			}
			else if (j >= 4)
			{
				i++;
				flag = 1;
			}
			else
			{
				i++;
				flag = 0;
			}
		}
		if (flag == 1)
			vt.push_back(s);
	}
	for (int i = 0; i < vt.size(); i++)
	{
		m1[vt[i]] += 1;
	}

	//cout << "�ַ��������ܸ��� : " << vt.size() << endl;
	//cout << "��ͬ���ʵĸ��� : " << m1.size() << endl;
	cout << "ǰ" << n << "����ͬ���ʳ��ֵ�Ƶ�� :" << endl;

	vector<pair<string, int>>vt2(m1.begin(), m1.end());
	sort(vt2.begin(), vt2.end(), cmp());
	int k = 0;
	for (vector<pair<string, int>>::iterator it = vt2.begin(); it != vt2.end(); it++)
	{
		k++;
		cout << it->first << " ��" << it->second << endl;
		if (k > n)
		{
			break;
		}
	}
	ifile.close();
}
//��ͨͳ��Ƶ�ʺ͵���
void myText::frequency()
{
	ifile.open(path);
	string str;
	string sss;
	while (getline(ifile, sss))
	{
		str += sss;
	}
	stringstream ss(str);
	string s;
	vector<string>vt;
	map<string, int>m1;
	while (getline(ss, s, ' '))
	{
		int flag = 0;
		int i = 0;
		int j = 0;
		int k = 0;
		while (i < s.size())
		{
			if (s[i] <= 'z'&& s[i] >= 'a' || s[i] <= 'Z'&& s[i] >= 'A')
			{
				j++;
				if (s[i] <= 'Z'&& s[i] >= 'A')
				{
					s[i] += 32;
				}
			}
			else
			{
				k++;
			}

			if (j < 4 && k>0)
			{
				i++;
				flag = 0;
				break;
			}
			else if (j >= 4)
			{
				i++;
				flag = 1;
			}
			else
			{
				i++;
				flag = 0;
			}
		}
		if (flag == 1)
			vt.push_back(s);
	}
	for (int i = 0; i < vt.size(); i++)
	{
		m1[vt[i]] += 1;
	}

	cout << "�ܵĵ��ʸ�����" << vt.size() << endl;
	cout << "��ͬ���ʵĸ��� : " << m1.size() << endl;
	cout << "��ͬ���ʳ��ֵ�Ƶ�� :" << endl;

	vector<pair<string, int>>vt2(m1.begin(), m1.end());
	sort(vt2.begin(), vt2.end(), cmp());
	int k = 0;
	for (vector<pair<string, int>>::iterator it = vt2.begin(); it != vt2.end(); it++)
	{
		k++;
		cout << it->first << " ��" << it->second << endl;
		if (k > 10)
		{
			break;
		}
	}
	ifile.close();
}
//�ַ�����Ϊn�ĵ���
void myText::nWords(int n)
{
	ifile.open(path);
	string str;
	string sss;
	while (getline(ifile, sss))
	{
		str += sss;
	}
	stringstream ss(str);
	string s;
	vector<string>vt;
	map<string, int>m1;
	while (getline(ss, s, ' '))
	{
		int flag = 0;
		int i = 0;
		int j = 0;
		int k = 0;
		while (i < s.size())
		{
			if (s[i] <= 'z'&& s[i] >= 'a' || s[i] <= 'Z'&& s[i] >= 'A')
			{
				j++;
				if (s[i] <= 'Z'&& s[i] >= 'A')
				{
					s[i] += 32;
				}
			}
			else
			{
				k++;
			}

			if (j < 1 && k>0)
			{
				i++;
				flag = 0;
				break;
			}
			else if (j + k == n)
			{
				i++;
				flag = 1;
			}
			else
			{
				i++;
				flag = 0;
			}
		}
		if (flag == 1)
			vt.push_back(s);
	}
	for (int i = 0; i < vt.size(); i++)
	{
		m1[vt[i]] += 1;
	}

	cout << "�ַ�����Ϊ " << n << "�ĵ��ʸ�����" << vt.size() << endl;
	cout << "��ͬ���ʵĸ��� : " << m1.size() << endl;
	cout << "��ͬ���ʳ��ֵ�Ƶ�� :" << endl;

	vector<pair<string, int>>vt2(m1.begin(), m1.end());
	sort(vt2.begin(), vt2.end(), cmp());
	int k = 0;
	for (vector<pair<string, int>>::iterator it = vt2.begin(); it != vt2.end(); it++)
	{
		k++;
		cout << it->first << " ��" << it->second << endl;
		if (k > 10)
		{
			break;
		}
	}
	ifile.close();
}
//д���ļ���
void myText::writeToFile(string path)
{
	ifile.open(this->path);
	ofstream outfile(path, ios::app);
	string str;
	string sss;
	while (getline(ifile, sss))
	{
		str += sss;
	}
	stringstream ss(str);
	string s;
	vector<string>vt;
	map<string, int>m1;
	while (getline(ss, s, ' '))
	{
		int flag = 0;
		int i = 0;
		int j = 0;
		int k = 0;
		while (i < s.size())
		{
			if (s[i] <= 'z'&& s[i] >= 'a' || s[i] <= 'Z'&& s[i] >= 'A')
			{
				j++;
				if (s[i] <= 'Z'&& s[i] >= 'A')
				{
					s[i] += 32;
				}
			}
			else
			{
				k++;
			}

			if (j < 4 && k>0)
			{
				i++;
				flag = 0;
				break;
			}
			else if (j >= 4)
			{
				i++;
				flag = 1;
			}
			else
			{
				i++;
				flag = 0;
			}
		}
		if (flag == 1)
			vt.push_back(s);
	}
	for (int i = 0; i < vt.size(); i++)
	{
		m1[vt[i]] += 1;
	}
	outfile << "�ַ��������ܸ��� : " << vt.size() << endl;
	outfile << "��ͬ���ʵĸ��� : " << m1.size() << endl;
	outfile << "��ͬ���ʳ��ֵ�Ƶ�� :" << endl;

	map<string, int>::iterator it;

	for (it = m1.begin(); it != m1.end(); it++)
	{
		outfile << "<" << it->first << ">" << ":" << it->second << endl;
	}

	outfile.close();
	ifile.close();
}

myText::myText()
{
}

myText::~myText()
{
	ifile.close();
}
// һ������£����Դ��ļ����������ʹ�õ���Ԥ�����ͷ���뱣������
