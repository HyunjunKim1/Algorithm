#include <iostream>

using namespace std;

int main() {

	int arr[] = { 3, 4, 2, 5, 1 };
	int arrSize = 5;
	for (int i = 0; i < arrSize - 1; i++) {
		//0���� (������ ����-i)������ ���� ���ҵ��� ���Ͽ� ��ȯ�Ѵ� 
		for (int j = 0; j < arrSize - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) { //�� ū ���� �ڷ�
				//swap
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		for (int a = 0; a < arrSize; a++)
			cout << arr[a] << ' ';
		cout << i + 1 << "ȸ��\n";
	}

}