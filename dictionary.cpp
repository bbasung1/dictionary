#include <iostream>
#include <vector>
#include <string>
using namespace std;

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
    string k;
	cin>>k;
	N=k.length();
	cin >> M >> fn;
	X=N+M;
	int *pos=new int(fn);
	char *ltr=new char(fn);
	for(int i=0;i<fn;i++){
		cin>>pos[i]>>ltr[i];
	}
	func(0,k,pos,ltr);
	for(auto i:word){
		cout<<i<<"\n";
	}
	return 0;
}