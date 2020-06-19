// Buổi 46

#include <iostream>

using namespace std;

/*
7 thao tác chính khi nhắc tới danh sách liên kết đơn(DSLKĐ). Vì STACK cũng từ bài danh sách liên kết mà ra.
1. Khai báo cấu trúc cho STACK.
2. Khởi tạo cho STACK.
3. Tạo nút(Node) cho STACK.
4. Thêm 1 nút(Node) cho STACK - thêm vào đầu và cuối danh sách. Cái này thêm 1 phần tử.
5. Thiết kế hàm input - tức là thêm nhiều phần tử.
6. Xử lý những yêu cầu cho STACK - sắp xếp, tìm kiếm, tính tổng,...
7. Giải phóng STACK - delete tất cả các nút(Node) trong danh sách là giải phóng bộ nhớ cho từng nút.
*/

// 1. Khai báo cấu trúc cho STACK.
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

// STACK: danh sách ngăn xếp.
struct STACK
{
	Node* PtrTop; // Con trỏ trỏ vào đầu danh sách.
};

//2. Khởi tạo cho STACK.
void _stackInit(STACK& s);

//3. Tạo nút(Node) cho STACK.
Node* _stackCreateNode(int _IData);

//4. Thêm 1 nút(Node) cho STACK - thêm vào đầu và cuối danh sách.Cái này thêm 1 phần tử.
// void _linkedListAddHead(LinkedList& l, Node* _Ptr); // Thêm đầu.
void _stackPush(STACK& s, Node* PtrNode); // Tương đường hàm addHead bên danh sách liên kết đơn.

//5. Thiết kế hàm input/output - tức là thêm nhiều phần tử.
void _stackInput(STACK& s);
void _stackOutput(STACK s);

//6. Xử lý những yêu cầu cho STACK - sắp xếp, tìm kiếm, tính tổng, ...
bool _stackEmpty(STACK s); // Kiểm tra STACK có rỗng hay không.
int _stackTop(STACK s); // Lấy ra phần tử đầu trong STACK.

//7. Xóa phần tử đầu trong danh sách ngăn xếp STACK - xóa 1.
void _stackPop(STACK& s); // Delete head bên danh sách liên kết đơn.

int main()
{
	

	system("pause");
	return 0;
}

void _stackInit(STACK& s) // Init linked list
{
	s.PtrTop = nullptr;
}

Node* _stackCreateNode(int _IData) // Create Node in single linked list
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

void _stackPush(STACK& s, Node* PtrNode) // Add head.
{
	if (s.PtrTop == nullptr) // Danh sách rỗng.
	{
		s.PtrTop = PtrNode; // _Ptr vừa là đầu vừa là cuối.
	}
	else
	{
		PtrNode->PtrNext = s.PtrTop; // Cho PtrNode trỏ tới đầu danh sách.
		s.PtrTop = PtrNode; // Cập nhật lại PtrTop.
	}
}

void _stackInput(STACK& s)
{
	_stackInit(s);

	int _ILength = 0;
	cout << "Nhap vao so luong phan tu: ";
	cin >> _ILength;

	for (size_t i = 0; i < _ILength; i++)
	{
		int _IData;
		cout << "Nhap vao phan tu thu " << i + 1 << ": ";
		cin >> _IData;

		_stackPush(s, _stackCreateNode(_IData));
	}
}

void _stackOutput(STACK s)
{
	if (_stackEmpty(s))
	{
		cout << "Stack(ngan xep) rong." << endl;
		return;
	}

	while (!_stackEmpty(s))
	{
		cout << _stackTop(s) << " "; // Lấy ra phần tử đầu.
		_stackPop(s); // Loại bỏ phần tử vừa lấy ra.
	}
}

bool _stackEmpty(STACK s) // _singleLinkedListEmpty(LinkedList);
{
	//if (s.PtrTop == nullptr)
	//{
	//	return true; // Danh sách rỗng.
	//}
	//return false; // Danh sách không rỗng.

	return (s.PtrTop == nullptr ? true : false);
}

int _stackTop(STACK s)
{
	return s.PtrTop->IData;
}

void _stackPop(STACK& s) // Delete head.
{
	if (!_stackEmpty(s))
	{
		Node* Temp = s.PtrTop;
		s.PtrTop = s.PtrTop->PtrNext;
		delete Temp;
	}
}
