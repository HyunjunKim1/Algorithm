#include <iostream>

using namespace std;

// 분할하는 리스트를 따로 설정하지않고 하나만 설정
int sorted[8];

// 합병 함수
void merge(int arr[], int start, int end) {
	int mid = (start + end) / 2;
	int i = start;
	int j = mid + 1;
	int k = start;

	//왼쪽 리스트와 오른쪽 리스트의 값을 비교(정렬)하면서 sorted란 배열에 합친다.
	while (i <= mid && j <= end) {
		if (arr[i] < arr[j]) {
			sorted[k++] = arr[i++];
		}
		else {
			sorted[k++] = arr[j++];
		}
	}
	if (i > mid) {
		while (j <= end) {
			sorted[k++] = arr[j++];
		}
	}
	if (j > end) {
		while (i <= mid) {
			sorted[k++] = arr[i++];
		}
	}


	for (int i = 0; i <= end; i++) {
		arr[i] = sorted[i];
		cout << arr[i] << ' ';
	}
	cout << '\n';

}

//주어진 정렬을 더 이상 나눌 수 없을 때 까지 쪼갠 후, 크기가 1인 배열들을 순차적으로 합치며 정렬한다.
void mergeSort(int arr[], int start, int end) {

	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, start, end);
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int arr[9] = { 54, 26, 93, 17, 77, 31, 44, 55, 20 };

	mergeSort(arr, 0, 7);

}