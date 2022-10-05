#include <iostream>

using namespace std;

void quickSort(int arr[], int start, int end) {

	int pivot = start; 
	int left = pivot + 1; 
	int right = end; 

	cout << '\t';
	for (int i = 0; i < 9; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
	//�� �̻� ����Ʈ�� ������ �� ������ ����
	if (start >= end)
		return;
	//left�� right�� ������ ������ �ݺ�
	while (left <= right) {
		for (; left <= end; left++) {
			// �ǹ� ���� ���Һ���(���ʺ���) ū�� �ϳ��� ã��
			if (arr[left] > arr[pivot]) 
				break;
		}
		for (; right > pivot; right--) {
			// �����ʺ��� �����ؼ� �ǹ����� ���� �� ã��
			if (arr[right] < arr[pivot]) 
				break;
		}
		// �������� �ʾҴٸ� left���� right�� ��ü
		if (left < right) {
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
		// �����ȴٸ� right���� pivot��ü
		else {
			int temp = arr[pivot];
			arr[pivot] = arr[right];
			arr[right] = temp;
		}
	}
	/*
	* �������� �ΰ��� ���� ����Ʈ ���� ��������� �˻��ϸ� ����
	*/
	quickSort(arr, start, right - 1);
	quickSort(arr, right + 1, end);



}


int main() {

	int arr[9] = { 54, 26, 93, 17, 77, 31, 44, 55, 20 };
	int arrSize = 9;

	cout << "\tresult" << '\n';
	quickSort(arr, 0, arrSize - 1);



	return 0;
}