#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;
ofstream ofs("./wow.txt");
const int MAX = 8 + 1;
int fn;
int N, M,X;
int arr[MAX];
bool visited[MAX];
vector<string>word;
void func(int cnt,string k,int pos[],char ltr[])
{
	vector<char> tmp;
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
			// cout << k[arr[i]-1];
			tmp.push_back(k[arr[i]-1]);
		// cout << "n\n";
		int j=0;
		for(int i=0;i<fn;i++){
			tmp.insert(tmp.begin()+pos[i]-1,ltr[j]);
			j++;
		}
		string s(tmp.begin(),tmp.end());
		word.push_back(s);
		//cout<<s<<"\n";
		//ofs<<s;
		//ofs<<s<<"\n";
		return;
	}

	for (int i = 1; i <= N; i++)
		if (!visited[i])
		{
			visited[i] = true;
			arr[cnt] = i;
			func(cnt + 1,k,pos,ltr);
			visited[i] = false;
		}
}

int main(void)
{
	#ifdef _WIN32
	//system("chcp 65001");
	SetConsoleOutputCP(CP_UTF8);
	#endif
    string k;
	string test="이미 나온 글자들을 제외하고, 제시 낱말들을 이어 쓰세요: ";
	cout<<test;
	cin>>k;
	N=k.length();
	cout<<"비어있는 칸의 수와 채워져 있는 칸 수를 입력하세요: ";
	cin >> M >> fn;
	X=N+M;
	int *pos=new int(fn);
	char *ltr=new char(fn);
	for(int i=0;i<fn;i++){
		cout<<"채워져 있는 자리의 위치와 글자를 입력하세요: ";
		cin>>pos[i]>>ltr[i];
	}
	func(0,k,pos,ltr);
	sort(word.begin(),word.end());
	word.erase(unique(word.begin(),word.end()),word.end());
	for(auto i:word){
		cout<<i<<"\n";
		ofs<<i<<"\n";
	}
	ofs.close();
	system("node checktest.js > log.txt");
	return 0;
}