#include <iostream>
using namespace std;

class Queue
{
private:

public:
	// ������
	Queue()
	{
	}

	// �Ҹ���
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

	cout << "Queue�� ũ�⸦ �Է��ϼ���." << "\n";
	cin >> size;

	Queue.Create(size);

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