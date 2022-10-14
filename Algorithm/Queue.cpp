#include <iostream>
using namespace std;

class Queue
{
private:
	int _count;
	int _size;

	short* m_data;
public:
	// ������
	Queue()
	{
		_count = 0;
		_size = 0;
		m_data = NULL;
	}

	// �Ҹ���
	~Queue()
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

			cout << "�� " << _count << "���� ���� ����" << "\n";
		}
	}
};

int main()
{
	Queue queue;

	int select_index = 0;
	int size = 0;

	cout << "Queue�� ũ�⸦ �Է��ϼ���." << "\n";
	cin >> size;

	queue.Create(size);

	while (select_index != 9)
	{
		cout << "\n\n1. Queue�� �� �ֱ�" << endl;
		cout << "2. Queue���� �� ������" << endl;
		cout << "3. Queue ����� �� Ȯ��" << endl;

		cout << "9. ����" << endl;
		cin >> select_index;

		switch (select_index)
		{
		case 1:
			cout << "������ �� �Է� : ";
			cin >> size;
			queue.Push(size);
			break;
		case 2:
			if (queue.Pop(&size))
				cout << "������ �� : " << size << endl;
			break;

		case 3:
			queue.Show();
			break;
		}
	}
}