#include <iostream>
#include <list>

using namespace std;

// 5. Input/Output.
void _input(list<int>& l, int n);
void _output(list<int> l);

int main()
{
	list<int> _Lst;

	int _ILength;
	cout << "Nhap vao so luong phan tu: ";
	cin >> _ILength;

	_input(_Lst, _ILength);
	cout << "Danh sach lien ket vua nhap: ";
	_output(_Lst);
	cout << endl;

	/*
	_Lst.front() -> Lấy ra phần tử đầu: _Lst.PtrHead->IData.
	_Lst.back() -> Lấy ra phần tử đầu: _Lst.Ptrtail->IData.
	*/
	cout << "pHead: " << _Lst.front() << endl; // _Lst.PtrHead->IData.
	cout << "pTailL " << _Lst.back() << endl; // _Lst.Ptrtail->IData.

	system("pause");
	return 0;
}

void _input(list<int>& l, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		int _IData;
		cout << "Nhap vao phan tu thu " << i + 1 << ": ";
		cin >> _IData;

		//l.push_front(_IData); // add head.
		l.push_back(_IData); // add Tail.
	}
}

void _output(list<int> l)
{
	/*for (Node* i = l.PtrHead; i != nullptr; i = i->PtrNext)
	{
		
	}*/
	if (l.empty())
	{
		cout << "Danh sach rong." << endl;
		return;
	}
	//l.begin(); // l.PtrHead;
	for (list<int>::iterator i = l.begin(); i != l.end(); i++)
	{
		cout << *i << " ";
	}
}
