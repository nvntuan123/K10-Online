// Buổi 46
#include <iostream>

using namespace std;

/*
7 thao tác chính khi nhắc tới danh sách liên kết đơn(DSLKĐ).
1. Khai báo cấu trúc cho QUEUE.
2. Khởi tạo cho QUEUE.
3. Tạo nút(Node) cho QUEUE.
4. Thêm 1 nút(Node) cho QUEUE - thêm vào đầu và cuối danh sách. Cái này thêm 1 phần tử.
5. Thiết kế hàm input - tức là thêm nhiều phần tử.
6. Xử lý những yêu cầu cho QUEUE - sắp xếp, tìm kiếm, tính tổng,...
7. Giải phóng QUEUE - delete tất cả các nút(Node) trong danh sách là giải phóng bộ nhớ cho từng nút.
*/

//1. Khai báo cấu trúc cho DSLKĐ.
struct Date
{
	int _IDay;
	int _IMonth;
	int _IYear;
};

struct Student
{
	int _IID; // MSSV.
	string _STRFullName; // Họ tên.
	Date _DTBirthDay;
	// ...
};

struct Employee
{
	int _IID; // MSSV.
	string _STRFullName; // Họ tên.
	Date _DTBirthDay;
	string _STREmail;
	string _STRAddress;
	// ...
};

struct Node
{
	// 1. Dữ liệu của nút - dữ liệu có thể là kiểu dữ liệu căn bản trong C++ hoặc là kiểu struct ta tự định nghĩa.
	int IData;
	//Student IData;
	//Employee IData;

	// 2. Link: tức là con tỏ pNext để liên kết đến nút(Node) tiếp theo.
	Node* PtrNext;
};

// QUEUE: danh sách hàng đợi.
struct QUEUE
{
	Node* PtrHead; // Con trỏ trỏ vào đầu danh sách.
	Node* PtrTail; // Con trỏ trỏ vào cuối danh sách.
};

//2. Khởi tạo cho QUEUE.
void _queueInit(QUEUE& q);

//3. Tạo nút(Node) cho QUEUE.
Node* _queueCreateNode(int _IData);

//4. Thêm 1 nút(Node) cho QUEUE - thêm vào đầu và cuối danh sách.Cái này thêm 1 phần tử.
// void _linkedListAddTail(LinkedList& q, Node* _Ptr); // Thêm cuối.
void _queuePush(QUEUE& q, Node* PtrNode);

//5. Thiết kế hàm input/output - tức là thêm nhiều phần tử.
void _queueInput(QUEUE& q);
void _queueOutput(QUEUE& q);

//6. Xử lý những yêu cầu cho QUEUE - sắp xếp, tìm kiếm, tính tổng, ...
bool _queueEmpty(QUEUE q);
int _queueFront(QUEUE q);
int _queueBack(QUEUE q);

//7. Xóa phần tử đầu trong danh sách ngăn xếp QUEUE - xóa 1.
void _queuePop(QUEUE& q);

int main()
{
	QUEUE q;
	_queueInput(q);

	if (_queueEmpty(q))
	{
		cout << "QUEUE(Hang doi) rong." << endl;
	}
	else
	{
		cout << "Phan tu dau(pHead): " << _queueFront(q) << endl;
		cout << "Phan tu cuoi(pTail): " << _queueBack(q) << endl;
		cout << "QUEUE(Hang doi) vua nhap vao la: ";
		_queueOutput(q);
		//cout << endl << "Vung nho cua pHead: " << q.PtrHead << endl;
		//cout << endl << "Vung nho cua pTail: " << q.PtrTail << endl;
	}

	system("pause");
	return 0;
}

void _queueInit(QUEUE& q)
{
	q.PtrHead = q.PtrTail = nullptr;
}

Node* _queueCreateNode(int _IData)
{
	Node* _PtrTemp = new Node;
	if (_PtrTemp == nullptr)
	{
		return nullptr;
	}
	_PtrTemp->IData = _IData;
	_PtrTemp->PtrNext = nullptr;

	return _PtrTemp;
}

void _queuePush(QUEUE& q, Node* PtrNode) // Add Tail.
{
	if (q.PtrHead == nullptr) // Danh sách rỗng.
	{
		q.PtrHead = q.PtrTail = PtrNode; // _Ptr vừa là đầu vừa là cuối.
	}
	else
	{
		q.PtrTail->PtrNext = PtrNode;
		q.PtrTail = PtrNode;
	}
}

void _queueInput(QUEUE& q)
{
	_queueInit(q); // Khởi tạo hàng đợi.

	int _ILength;
	cout << "Nhap vao so luong phan tu: ";
	cin >> _ILength;

	for (size_t i = 0; i < _ILength; i++)
	{
		int _IData;
		cout << "Nhap vao phan tu thu " << i + 1 << ": ";
		cin >> _IData;

		_queuePush(q, _queueCreateNode(_IData));
	}
}

void _queueOutput(QUEUE& q)
{
	if (_queueEmpty(q))
	{
		cout << "Queue(hang doi) rong." << endl;
		return;
	}

	while (!_queueEmpty(q))
	{
		cout << _queueFront(q) << " "; // Lấy ra phần tử đầu.
		_queuePop(q); // Loại bỏ phần tử vừa lấy ra.
	}
}

bool _queueEmpty(QUEUE q)
{
	return (q.PtrHead == nullptr ? true : false);
}

int _queueFront(QUEUE q)
{
	return q.PtrHead->IData;
}

int _queueBack(QUEUE q)
{
	return q.PtrTail->IData;
}

void _queuePop(QUEUE& q)
{
	if (q.PtrHead)
	{
		Node* Temp = q.PtrHead;
		if (q.PtrHead == q.PtrTail) // Trường hợp danh sách chỉ có 1 nút.
		{
			q.PtrTail = nullptr;
		}
		q.PtrHead = q.PtrHead->PtrNext;
		delete Temp;
	}
	return;
}
