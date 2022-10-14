#include <iostream>
using namespace std;

class Queue
{
private:

public:
	// 생성자
	Queue()
	{
	}

	// 소멸자
	~Queue()
	{
	}

	void Create(short m_size)
	{
	}

	void Push(short m_num)
	{
	}

	int Pop(int* p_num)
	{
	}

	void Show()
	{
	}
};

int main()
{
	Queue queue;

	int select_index = 0;
	int size = 0;

	cout << "Queue의 크기를 입력하세요." << "\n";
	cin >> size;

	Queue.Create(size);

	while (select_index != 9)
	{
		cout << "\n\n1. Queue에 값 넣기" << endl;
		cout << "2. Queue에서 값 꺼내기" << endl;
		cout << "3. Queue 저장된 값 확인" << endl;

		cout << "9. 종료" << endl;
		cin >> select_index;

		switch (select_index)
		{
		case 1:
			cout << "저장할 값 입력 : ";
			cin >> size;
			queue.Push(size);
			break;
		case 2:
			if (queue.Pop(&size))
				cout << "가져온 값 : " << size << endl;
			break;

		case 3:
			queue.Show();
			break;
		}
	}
}