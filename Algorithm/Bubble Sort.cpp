#include <iostream>

using namespace std;

int main() {

	/* Worst Case
	int arr[] = { 54, 26, 93, 17, 77, 31, 44, 55, 20 };
	int arrSize = 9;
	for (int i = 0; i < arrSize - 1; i++) {
		for (int j = 0; j < arrSize - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) { 
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		for (int a = 0; a < arrSize; a++)
			cout << arr[a] << ' ';
		cout << i + 1 << " Exchange\n";
	}
	*/

	/* Best Case*/

	int arr[] = { 54, 26, 93, 17, 77, 31, 44, 55, 20 };
	int arrSize = 9;
	for (int i = 0; i < arrSize - 1; i++) {

		bool isSwap = false;
		for (int j = 0; j < arrSize - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) 
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				isSwap = true;
			}
		}

		if (isSwap == false)
			break;

		for (int a = 0; a < arrSize; a++)
			cout << arr[a] << ' ';
		cout << i + 1 << " Exchange\n";
	}
}