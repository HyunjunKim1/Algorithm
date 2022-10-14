#include <iostream>
using namespace std;

class Queue
{
private:
	int _count;
	int _size;

	short* m_data;
public:
	// 생성자
	Queue()
	{
		_count = 0;
		_size = 0;
		m_data = NULL;
	}

	// 소멸자
	~Queue()
	{
		if (m_data == NULL)
			delete[] m_data;
	}

	void Create(short m_size)
	{
		// 크기 체크
		if (m_size > 0 && m_size != _size)
		{
			if (m_data != NULL)
				delete[] m_data;

			// 새크기 저장 및 메모리 할당
			_size = m_size;
			m_data = new short[_size];
		}
	}

	void Push(short m_num)
	{
		// 비어있을경우
		if (_count < _size)
		{
			*(m_data + _count) = m_num;
			_count++;
		}
		else
			cout << "Queue is full" << "\n";
	}

	int Pop(int* p_num)
	{
		if (_count == 0)
		{
			cout << "Queue is empty" << "\n";
			return 0;
		}

		_count--;
		*p_num = *(m_data);
		return 1;
	}

	void Show()
	{
		if (_count == 0)
			cout << "Queue is empty" << "\n";

		else
		{
			cout << "Queue ob" << "\n";
			for (int i = 0; i < _count; i++)
			{
				cout << i + 1 << " : " << *(m_data + i) << "\n";
			}

			cout << "층 " << _count << "개의 값이 저장" << "\n";
		}
	}
};

int main()
{
	Queue queue;

	int select_index = 0;
	int size = 0;

	cout << "Queue의 크기를 입력하세요." << "\n";
	cin >> size;

	queue.Create(size);

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