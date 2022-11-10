#include <iostream>
#include <vector>
#include <string>
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
#define endl "\n"
using namespace std;
int main() {
	fast;
	int N, M,count=0;
	cin >> N >> M;
	string a;
	bool Array[50][50];
	bool Array2[50][50];
	for (int i = 0; i < N; i++) {
		cin >> a;
		for (int j = 0; j < M; j++) {
			Array[i][j] = a[j]-48;
		}
	}
	for (int i = 0; i < N; i++) {
		cin >> a;
		for (int j = 0; j < M; j++) {
			Array2[i][j] = a[j] - 48;
		}
	}
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 2; j++) {
			if (Array[i][j] != Array2[i][j] ||
				Array[i][j+1] != Array2[i][j+1] ||
				Array[i][j+2] != Array2[i][j+2]) {
				for (int z = i; z < i + 3; z++) {
					Array[z][j] = !Array[z][j];
					Array[z][j+1] = !Array[z][j+1];
					Array[z][j+2] = !Array[z][j+2];
				}
				count++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Array[i][j] != Array2[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << count;
}