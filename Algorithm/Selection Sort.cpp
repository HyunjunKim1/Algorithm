#include <iostream>
using namespace std;

#define INF 987654321

int main() {

	int arr[] = { 26, 54, 93, 17, 77, 31, 44, 55, 20 };
	int arrSize = 9;
	for (int i = 0; i < arrSize; i++) {
		int min_num = INF; 
		int temp, min_index;
		for (int j = i; j < arrSize; j++) {
			if (arr[j] < min_num) {
				min_num = arr[j]; 
				min_index = j; 
			}
		}
		
		temp = arr[i];
		arr[i] = min_num;
		arr[min_index] = temp;
		for (int j = 0; j < arrSize; j++) {
			cout << arr[j] << ' ';
		}
		cout << '\n';
	}
}