#include <iostream>

using namespace std;

int main() {

	int arr[] = { 3, 4, 2, 5, 1 };
	int arrSize = 5;

	//배열의 시작점부터 끝까지 탐색한다.
	for (int i = 0; i < arrSize - 1; i++) {
		//배열의 두 번째 원소부터, 해당 원소의 왼쪽에 있는 값들을 비교하고, 원소보다 작은 값을
		//만나면 그 뒤에 해당 원소를 삽입한다.
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