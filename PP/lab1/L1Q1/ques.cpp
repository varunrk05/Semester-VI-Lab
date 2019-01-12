#include <iostream>
using namespace std;

int main(){
	int m, n, p;
	cout << "Enter m,n,p:\n";
	cin >> m >> n >> p;

	int a[m][n], b[n][p];
	cout << "Enter a:\n";
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			cin >> a[i][j];

	cout << "Enter b:\n";
		for(int i = 0; i < n; i++)
			for(int j = 0; j < p; j++)
				cin >> b[i][j];

	int c[m][p] = {0};

	for(int i = 0; i < m; i++)
		for(int j = 0; j < p; j++)
			for(int k = 0; k < n; k++)
				c[i][j] += a[i][k] * b[k][j];

	cout << "The final matrix is:";
	for(int i = 0; i < m; i++){
		for(int j = 0; j < p; j++){
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
}
