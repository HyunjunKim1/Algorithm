#include <iostream>

using namespace std;

// �����ϴ� ����Ʈ�� ���� ���������ʰ� �ϳ��� ����
int sorted[8];

// �պ� �Լ�
void merge(int arr[], int start, int end) {
	int mid = (start + end) / 2;
	int i = start;
	int j = mid + 1;
	int k = start;

	//���� ����Ʈ�� ������ ����Ʈ�� ���� ��(����)�ϸ鼭 sorted�� �迭�� ��ģ��.
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

//�־��� ������ �� �̻� ���� �� ���� �� ���� �ɰ� ��, ũ�Ⱑ 1�� �迭���� ���������� ��ġ�� �����Ѵ�.
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