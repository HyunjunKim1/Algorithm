#include <iostream>

using namespace std;

int main() {

	int arr[] = { 3, 4, 2, 5, 1 };
	int arrSize = 5;

	//�迭�� ���������� ������ Ž���Ѵ�.
	for (int i = 0; i < arrSize - 1; i++) {
		//�迭�� �� ��° ���Һ���, �ش� ������ ���ʿ� �ִ� ������ ���ϰ�, ���Һ��� ���� ����
		//������ �� �ڿ� �ش� ���Ҹ� �����Ѵ�.
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