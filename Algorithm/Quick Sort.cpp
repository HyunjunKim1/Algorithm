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
	//더 이상 리스트를 분할할 수 없으면 종료
	if (start >= end)
		return;
	//left와 right가 엇갈릴 때까지 반복
	while (left <= right) {
		for (; left <= end; left++) {
			// 피벗 다음 원소부터(왼쪽부터) 큰값 하나씩 찾기
			if (arr[left] > arr[pivot]) 
				break;
		}
		for (; right > pivot; right--) {
			// 오른쪽부터 시작해서 피벗보다 작은 값 찾기
			if (arr[right] < arr[pivot]) 
				break;
		}
		// 엇갈리지 않았다면 left값과 right값 교체
		if (left < right) {
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
		// 엇갈렸다면 right값과 pivot교체
		else {
			int temp = arr[pivot];
			arr[pivot] = arr[right];
			arr[right] = temp;
		}
	}
	/*
	* 나뉘어진 두개의 분할 리스트 들을 재귀적으로 검색하며 실행
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