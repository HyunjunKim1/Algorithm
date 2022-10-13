#include <iostream>
using namespace std;

class Stack
{
private:
	int _count;
	int _size;

	short* m_data;

public :

	// 생성자
	Stack()
	{
		_size = 0;
		_count = 0;
		m_data = NULL;
	}

	// 소멸자
	~Stack()
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
			cout << "Stack is full" << "\n";
	}

	int Pop(int* p_num)
	{
		// 스택에 저장된 개수가 없을경우
		if (_count == 0)
		{
			cout << "Stack is empty" << "\n";
			return 0;
		}

		_count--;
		*p_num = *(m_data + _count);
		return 1;
	}

	void Show()
	{
		if (_count == 0)
			cout << "Stack is empty" << "\n";

		else
		{
			cout << "Stack ob" << "\n";
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
	Stack stack;

	int select_index = 0;
	int size = 0;

	cout << "Stack의 크기를 입력하세요." << "\n";
	cin >> size;

	stack.Create(size);

	while (select_index != 9)
	{
		cout << "\n\n1. Stack에 값 넣기" << endl;
		cout << "2. Stack에서 값 꺼내기" << endl;
		cout << "3. Stack 저장된 값 확인" << endl;

		cout << "9. 종료" << endl;
		cin >> select_index;

		switch (select_index)
		{
		case 1:
			cout << "저장할 값 입력 : ";
			cin >> size;
			stack.Push(size);
			break;
		case 2:
			if (stack.Pop(&size))
				cout << "가져온 값 : " << size << endl;
			break;

		case 3:
			stack.Show();
			break;
		}
	}
}