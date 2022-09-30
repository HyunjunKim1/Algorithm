#include <iostream>

using namespace std;

int main() {

	int arr[] = { 3, 4, 2, 5, 1 };
	int arrSize = 5;
	for (int i = 0; i < arrSize - 1; i++) {
		//0부터 (마지막 원소-i)값까지 인접 원소들을 비교하여 교환한다 
		for (int j = 0; j < arrSize - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) { //더 큰 값을 뒤로
				//swap
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		for (int a = 0; a < arrSize; a++)
			cout << arr[a] << ' ';
		cout << i + 1 << "회전\n";
	}

}