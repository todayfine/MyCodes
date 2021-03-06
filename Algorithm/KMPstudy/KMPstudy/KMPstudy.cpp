// KMPstudy.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
#define MAXSIZE 100
char m[MAXSIZE];
char n[MAXSIZE];
int Next[MAXSIZE];

using namespace std;

void kmpgetNext()
{
	if (strlen(m) <= 0)return;
	int len = strlen(m);
	int k = 0;
	memset(Next, 0, MAXSIZE);
	for (int i = 1; i < len; i++)
	{
		while (k>0 && m[i] != m[k])
			k = Next[k];
		if (m[i] == m[k])k++;
		Next[i+1] = k;
	}
}

void kmpGetNext()
{
	int len = strlen(m);
	int i = 0, k = -1;
	Next[0] = -1;
	while (i < len)
	{
		if (k == -1|| m[i] == m[k])
		{
			i++;
			k++;
			Next[i] = k;
		}
		else
			k = Next[k];
	}
}

bool kmpsearch()
{
	if (strlen(m) <= 0 || strlen(n) <= 0)return false;
	int i = 0, k = 0;
	int m_len = strlen(m), n_len = strlen(n);
	for (i = 0; i < n_len; i++)
	{
		for (k = 0; k < m_len; k++)
		{
			if (m[k] == n[i+k])
				continue;
			else
			{
				i += k - Next[k] - 1;
				break;
			}
		}
		if (k == m_len)return true;
	}
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	strcpy(m, "abcd");
	strcpy(n, "\0");
	kmpGetNext();
	for (int i = 0; i < strlen(m); i++)
		cout << m[i] << " ";
	cout << endl;
	for (int i = 0; i < strlen(m)+1; i++)
		cout << Next[i] << " ";
	cout << endl;
	kmpgetNext();
	for (int i = 0; i < strlen(m) + 1; i++)
		cout << Next[i] << " ";
	cout << endl;
	bool isfind = kmpsearch();
	if (isfind)
		cout << "Find" << endl;
	else
		cout << "Not Find" << endl;
	cin.get();
	return 0;
}

