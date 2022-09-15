#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAX = 8 + 1;

int N, M;
int arr[MAX];
bool visited[MAX];
void func(int cnt,string k)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
			cout << k[arr[i]-1];
		cout << "n\n";
		return;
	}

	for (int i = 1; i <= N; i++)
		if (!visited[i])
		{
			visited[i] = true;
			arr[cnt] = i;
			func(cnt + 1,k);
			visited[i] = false;
		}
}

int main(void)
{
    string k="vasgi";
	cin >> N >> M;

	func(0,k);
	return 0;
}