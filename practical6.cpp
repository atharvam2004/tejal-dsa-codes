#include <iostream>
#include <vector>
using namespace std;

int main(){

	int n;
	cout << "Enter the Number of cities" << endl;
	cin >> n;

	vector<string> cities(n);

	string str;
	for (int i=0; i<n; i++){
		cout << i << " City Name -> ";
		cin >> str;
		cities[i] = str;
	}

	int arr[n][n];
	cout << "Enter Distance between cities : "<<"["<<n<<"]"<<"["<<n<<"]" ;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << "\nGiven Graph is" << endl;

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cout << arr[i][j] << " ";
		}cout << endl;
	}cout << endl;
	
	bool flag = true;

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if (i != j && arr[i][j] == arr[j][i]){
				continue;
			}
			if (arr[i][j] != arr[j][i]){
				flag = false;
			}
		}
	}

	if (flag == true){
		cout << "Graph is connected" << endl;
	}
	else cout << "Graph is not connected" << endl;
}



