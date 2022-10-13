#include <iostream>
using namespace std;

class Stack
{
private:
	int _count;
	int _size;

	short* m_data;

public :

	// ������
	Stack()
	{
		_size = 0;
		_count = 0;
		m_data = NULL;
	}

	// �Ҹ���
	~Stack()
	{
		if (m_data == NULL)
			delete[] m_data;
	}

	void Create(short m_size)
	{
		// ũ�� üũ
		if (m_size > 0 && m_size != _size)
		{
			if (m_data != NULL)
				delete[] m_data;

			// ��ũ�� ���� �� �޸� �Ҵ�
			_size = m_size;
			m_data = new short[_size];
		}
	}

	void Push(short m_num)
	{
		// ����������
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
		// ���ÿ� ����� ������ �������
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

			cout << "�� " << _count << "���� ���� ����" << "\n";
		}
	}
};

int main()
{
	Stack stack;

	int select_index = 0;
	int size = 0;

	cout << "Stack�� ũ�⸦ �Է��ϼ���." << "\n";
	cin >> size;

	stack.Create(size);

	while (select_index != 9)
	{
		cout << "\n\n1. Stack�� �� �ֱ�" << endl;
		cout << "2. Stack���� �� ������" << endl;
		cout << "3. Stack ����� �� Ȯ��" << endl;

		cout << "9. ����" << endl;
		cin >> select_index;

		switch (select_index)
		{
		case 1:
			cout << "������ �� �Է� : ";
			cin >> size;
			stack.Push(size);
			break;
		case 2:
			if (stack.Pop(&size))
				cout << "������ �� : " << size << endl;
			break;

		case 3:
			stack.Show();
			break;
		}
	}
}