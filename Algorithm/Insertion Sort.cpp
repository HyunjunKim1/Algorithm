#include <iostream>

using namespace std;

int main() {

	int arr[] = { 26, 54, 93, 17, 77, 31, 44, 55, 20 };
	int arrSize = 9;

	for (int i = 0; i < arrSize - 1; i++) 
	{
	
		for (int j = i + 1; j > 0 && arr[j - 1] > arr[j]; j--) {
			int temp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = temp;
		}
		for (int a = 0; a < arrSize; a++)
			cout << arr[a] << ' ';
		cout << '\n';
	}

}