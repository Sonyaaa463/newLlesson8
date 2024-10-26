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
			this->dequeue();
		}
		head = tail = nullptr;
	}

};

class Document
{
private:
	char* nameAutor;
	char* text;
public:
	Document() :text{ nullptr }, nameAutor{ nullptr }
	{

	}
	Document(const char* nameAutor, const char* text)
	{
		this->text = new char[strlen(text) + 1];
		strcpy_s(this->text, strlen(text) + 1, text);

		this->nameAutor = new char[strlen(nameAutor) + 1];
		strcpy_s(this->nameAutor, strlen(nameAutor) + 1, nameAutor);

	}
	~Document()
	{

		if (this->text != nullptr)
		{
			delete[]this->text;
			this->text = nullptr;
		}
		if (this->nameAutor != nullptr)
		{
			delete[]this->nameAutor;
			this->nameAutor = nullptr;
		}
	}


	 char* getText()
	{
		return this->text;
	}

	 char* getNameAutor()
	{
		return this->nameAutor;
	}
	Document(const Document& other)
	{
		this->text = new char[strlen(other.text) + 1];
		strcpy_s(this->text, strlen(other.text) + 1, other.text);	
		this->nameAutor = new char[strlen(other.nameAutor) + 1];
		strcpy_s(this->nameAutor, strlen(other.nameAutor) + 1, other.nameAutor);
	}
	Document& operator =(const Document& other)
	{
		if (this == &other)
		{
			return *this;
		}
		delete[]text;
		delete[]nameAutor;

		this->text = new char[strlen(other.text) + 1];
		strcpy_s(this->text, strlen(other.text) + 1, other.text);

		this->nameAutor = new char[strlen(other.nameAutor) + 1];
		strcpy_s(this->nameAutor, strlen(other.nameAutor) + 1, other.nameAutor);
		return*this;
	}
};


class Printer
{
private:
	Queue <Document> documents;
public:
	void addDocument(const Document& doc)
	{
		documents.enqueue(doc);
	}
	bool isEmply()const
	{
		return documents.isEmpty();
	}
	void Print()
	{
		if (isEmply())
		{
			return;
		}
		Document doc = documents.dequeue();
		cout << "Print ..." << doc.getText() << " " << doc.getNameAutor() << endl;
	}

};
int main()
{
	Document doc1("text1", "author1");
	Document doc2("text2", "author2");

	Printer printer;
	printer.addDocument(doc1);
	printer.addDocument(doc2);

	while (!printer.isEmply())
	{
		printer.Print();
	}

}
