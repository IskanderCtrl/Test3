// spisok.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
void createList(node*& head)
{
	head = NULL;
	int i, n;
	cout << "Vvedite kol-vo elementov v spiske" << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		node* q = new node;
		cin >> q->data;
		q->next = head;
		head = q;
	}
}
void showList(node* head)
{
	node* q = head;
	while (q != NULL)
	{
		cout << q->data << " ";
		q = q->next;
	}
	cout << endl;
}
void push1(node*& head)
{
	node* a = new node;
	cin >> a->data;
	a->next = head;
	head = a;
}
void push2(node*& head)
{
	int s;
	cin >> s;
	bool t = false;
	node* q = head;
	node* a = new node;
	cin >> a->data;
	while (q->next != NULL && !t)
	{
		if (q->data == s)
			t = true;
		q = q->next;
	}
	if (t)
	{
		while (q->next->data != s)
			q = q->next;
		a->next = q->next;
		q->next = a;
	}
}
void push3(node* head)
{
	int t;
	cin >> t;
	node* q = head;
	node* a = new node;
	cin >> a->data;
	bool s = true;
	while (q->next != NULL && s)
	{
		if (q->data == t)
		{
			a->next = q->next;
			q->next = a;
			s = false;
		}
		q = q->next;
	}
}
void push4(node* head)
{
	node* q = head;
	node* a = new node;
	cin >> a->data;
	while (q->next != NULL)
	{
		q = q->next;
	}
	a->next = NULL;
	q->next = a;
}
void delete1(node*& head)
{
	node* q = head;
	head = head->next;
	delete q;
}
void delete2(node*& head)
{
	if (head != NULL)
	{
		node* q = head;
		node* a = head;
		if (q->next != NULL)
		{
			q = q->next;
			while (q->next != NULL)
			{
				q = q->next;
				a = a->next;
			}
			delete q;
			a->next = NULL;
		}
		else
		{
			head = NULL;
			delete q;
		}
	}
}
void delete3(node*& head)
{
	node* q = head;
	node* a = head;
	int t;
	cout << "Vvedite element";
	cin >> t;
	if (head != NULL)
	{
		if (head->next == NULL)
		{
			if (head->data < 0)
			{
				head = NULL;
				delete q;
			}
		}
		else
		{
			while (q != NULL)
			{
				if (head->data ==t )
				{
					head = head->next;
					delete q;
					q = head;
					a = head;
				}
				else
				{
					if (q->data !=t)
					{
						if (q == head)
							q = q->next;
						else
						{
							q = q->next;
							a = a->next;
						}
					}
					else
					{
						a->next = q->next;
						delete q;
						q = a->next;
					}
				}
			}
		}
	}
}
void ind4(node*& head)
{
	node* q = head;
	node* a = head;
	if (head != NULL)
	{
		if (head->next == NULL)
		{
			if (head->data < 0)
			{
				head = NULL;
				delete q;
			}
		}
		else
		{
			while (q != NULL)
			{
				if (head->data < 0)
				{
					head = head->next;
					delete q;
					q = head;
					a = head;
				}
				else
				{
					if (q->data >= 0)
					{
						if (q == head)
							q = q->next;
						else
						{
							q = q->next;
							a = a->next;
						}
					}
					else
					{
						a->next = q->next;
						delete q;
						q = a->next;
					}
				}
			}
		}
	}
}
void deleteList(node*& head)
{
	node* a = head;
	while (head != NULL)
	{
		head = head->next;
		delete a;
		a = head;
	}
}
int main()
{
	node* head;
	createList(head);
	showList(head);
	//push1(head);
	//push2(head);
	//push3(head);
	//push4(head);
	//delete1(head);
	//delete2(head);
	//delete3(head);
    //ind4(head);
	//showList(head);
	cout << "1. push1" << endl;
	cout << "2. push2" << endl;
	cout << "3. push3" << endl;
	cout << "4. push4" << endl;
	cout << "5. delete1" << endl;
	cout << "6. delete2" << endl;
	cout << "6. delete3" << endl;
	cout << "6. ind4" << endl;
	cout << endl;
	int c;
	cout << "Enter:";
	cin >> c;
	while (c != 0)
	{
		switch (c)
		{
		case 1: 
		{
			push1(head);
			showList(head);
			cout << endl;
			break;
		}
		case 2: 
		{
			push2(head);
			showList(head);
			cout << endl;
			break;
		}
		case 3:  
		{
			push3(head);
			showList(head);
			cout << endl;
			break;
		}
		case 4: 
		{
			push4(head);
			showList(head);
			cout << endl;
			break;
		}
		case 5:  
		{
			delete1(head);
			showList(head);
			cout << endl;
			break;
		}
		case 6: 
		{
			delete2(head);
			showList(head);
			cout << endl;
			break;
		}
		case 7:
		{
			delete3(head);
			showList(head);
			cout << endl;
			break;
		}
		case 8:
		{
			ind4(head);
			showList(head);
			cout << endl;
			break;
		}
		default:
		{
			cout << "Mistake((" << endl;
			break;
		}
		}
		cout << "Enter:";
		cin >> c;
	}
	deleteList(head);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
