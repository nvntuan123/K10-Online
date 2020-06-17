#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// 5. Input/Output.
// stack
//void _inputS(stack<int>& s, int n);
//void _outputS(stack<int> s);

// queue.
void _inputQ(queue<int>& q, int n);
void _outputQ(queue<int> q);

int main()
{
	/*stack<int> s;

	int _ILength;
	cout << "Nhap vao so luong phan tu: ";
	cin >> _ILength;

	_inputS(s, _ILength);
	cout << "Ngan xep(stack) vua nhap la: ";
	_outputS(s);
	cout << endl;*/

	queue<int> q;

	int _ILength;
	cout << "Nhap vao so luong phan tu: ";
	cin >> _ILength;

	_inputQ(q, _ILength);
	cout << "Hang doi(queue) vua nhap la: ";
	_outputQ(q);
	cout << endl;

	cout << "pHead: " << q.front() << endl; // _Lst.PtrHead->IData;
	cout << "pTail: " << q.back(); // _Lst.PtrTail->_IData;

	system("pause");
	return 0;
}

//void _inputS(stack<int>& s, int n)
//{
//	for (size_t i = 0; i < n; i++)
//	{
//		int _IData;
//		cout << "Nhap vao phan tu thu " << i + 1 << ": ";
//		cin >> _IData;
//
//		s.push(_IData);
//	}
//}
//
//void _outputS(stack<int> s)
//{
//	if (s.empty())
//	{
//		cout << "Stack(ngan xep) rong." << endl;
//		return;
//	}
//	int _IN = s.size(); // _Lst.Size();
//	for (size_t i = 0; i < _IN; i++)
//	{
//		cout << s.top() << " "; // Lấy ra 1 phần tử.
//		s.pop(); // Loại bỏ phần tử vừa lấy ra.
//	}
//}

void _inputQ(queue<int>& q, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		int _IData;
		cout << "Nhap vao phan tu thu " << i + 1 << ": ";
		cin >> _IData;

		q.push(_IData);
	}
}

void _outputQ(queue<int> q)
{
	if (q.empty())
	{
		cout << "Queue(hang doi) rong." << endl;
		return;
	}
	int _IN = q.size(); // _Lst.Size();
	for (size_t i = 0; i < _IN; i++)
	{
		cout << q.front() << " "; // Lấy ra phần tử đầu.
		q.pop(); // Loại bỏ phần tử vừa lấy ra.
	}
}
