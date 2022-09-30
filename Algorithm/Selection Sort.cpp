#include <iostream>
using namespace std;

//초기값을 배열에서 나올 수 없는 큰 수로 초기화하여 배열 내의 초기값을 찾는다.
#define INF 987654321

int main() {

	int arr[5] = { 3,1,5,2,4 };
	int arrSize = 5;
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