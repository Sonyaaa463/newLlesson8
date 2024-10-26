#include <iostream>
using namespace std;
//  ДИНАМІЧНА СТРУКТУРА ДАНИХ - ЧЕРГА QUEUE
// в звичайній пам'ятає попередній . але треба пам'ятати хто після вас в реалізації
template<typename T>
struct Element
{
	T data;
	Element<T>* next;
	Element(T value)
	{
		data = value;
		next = nullptr;
	}
};
template<typename T>
class Queue
{
private:
	Element<T>* head;
	Element<T>* tail;
public:
	Queue()
	{
		head = tail = nullptr;
	}
	//додавання елемента до черги
	void enqueue(T value)
	{
		Element<T>* newElement = new Element<T>(value);
		if (tail == nullptr)
		{
			head = tail = newElement;
			return;

		}
		tail->next = newElement;
		tail = newElement;
	}
	//видалити елемент з черги
	T dequeue()
	{
		Element<T>* tmp = head;
		head = head->next;
		if (head == nullptr)
		{
			tail = nullptr;
		}
		T val = tmp->data;
		delete tmp;
		tmp = nullptr;
		return val;
	}
	//перевірка черги на порожність
	bool isEmpty() const
	{
		return head == nullptr;
	}
	// повертання вершини
	Element<T>* getHead() const
	{
		return head;
	}
	// отримати елемент з початку чверги
	int peek()
	{
		return head->data;
	}
	// деструктор
	~Queue()
	{
		while (this->isEmpty() == false)
		{
			this -> dequeue();
		}
		head = tail = nullptr;
	}
	
};
template<typename T>
// допоміжна ф-ія рекурсивна для руку
void printreverse(Element<T>* element)
{
	if (element == nullptr)
	{
		return;
	}
	printreverse(element->next);
	cout << element->data << endl;
}
template<typename T>
// роздруковуєм в зворотнюму порядку безвидалення
void reverse(const Queue<T> & q)
{
	Element<T>* head = q.getHead();
	printreverse(head);

}

int main()
{
	Queue<double> q;
	q.enqueue(1.77);
	q.enqueue(2.33);
	q.enqueue(3.11);
	q.isEmpty();

	//while (q.isEmpty()==false)
	//{
	//	cout << q.dequeue() << endl;
	//}

	reverse(q);
}
