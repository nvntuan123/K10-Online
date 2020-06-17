#include <iostream>
#include <string>
#include <functional>

using namespace std;

// 1. Khai báo cấu trúc dữ liệu cho danh sách liên kết đơn - nhân viên.
struct Employee
{
	int IID; // Mã nhân viên.
	string StrFullName; // Họ tên nhân viên.
	int IAge; // Tuổi.
	double DSalary; // Lương.
};

struct Node
{
	Employee Data; //int IData;
	Node* PtrNext;
};

struct List
{
	Node* PtrHead;
	Node* PtrTail;
};

// 2. Khởi tạo DSLKĐ.
void _init(List& l);

// 3. Tạo node cho DSLKĐ.
void _employeeInputInfo(Employee& Emp);
void _employeeOutputInfo(Employee Emp);

Node* _createNode(Employee Data); //int _IData)

// 4. Add head/ add tail.
void _addHead(List& l, Node* PtrNode);
void _addTail(List& l, Node* PtrNode);

// 5. Input/Output.
void _input(List& l);
void _output(List l);

// 6. Xử lý yêu cầu.
double _employeeListSumOfSalary(List l); // Tính tổng lương của tất cả nhân viên trong danh sách.
bool _ascending(Employee _EmpA, Employee _EmpB); // Lương A nhỏ hơn B.
bool _descending(Employee _EmpA, Employee _EmpB); // Lương A lớn hơn B.
void _employeeListSortSalaryAscDesc(List l, function<bool(Employee, Employee)> _FuncCompar);

// 7. Giải phóng.
void _freeList(List& l);

int main()
{
	List _Lst;
	_input(_Lst);
	cout << "==========================DANH SACH THONG TIN NHAN VIEN VUA NHAP==========================" << endl;
	_output(_Lst);

	cout << endl;
	double _DSum = _employeeListSumOfSalary(_Lst);
	if (_DSum == -1)
	{
		cout << "Danh sach rong." << endl;
	}
	else
	{
		cout << "Tong luong tat ca nhan vien: " << _DSum << endl;
	}

	//_employeeListSortSalaryAscDesc(_Lst, _ascending);
	_employeeListSortSalaryAscDesc(_Lst, _descending);
	cout << "==========================DANH SACH THONG TIN NHAN VIEN==========================" << endl;
	_output(_Lst);

	_freeList(_Lst);

	system("pause");
	return 0;
}

void _init(List& l)
{
	l.PtrHead = l.PtrTail = nullptr;
}

void _employeeInputInfo(Employee& Emp)
{
	cout << "Nhap ma so: ";
	cin >> Emp.IID;
	cin.ignore(256, '\n');

	cout << "Nhap ho ten: ";
	getline(cin, Emp.StrFullName);

	cout << "Nhap tuoi: ";
	cin >> Emp.IAge;

	cout << "Nhap luong: ";
	cin >> Emp.DSalary;
}

void _employeeOutputInfo(Employee Emp)
{
	cout << "Ma so: " << Emp.IID << endl;
	cout << "Ho ten: " << Emp.StrFullName << endl;
	cout << "Tuoi: " << Emp.IAge << endl;
	cout << "Luong: " << Emp.DSalary << endl;
}

Node* _createNode(Employee Data)
{
	Node* Temp = new Node;
	if (Temp == nullptr)
	{
		return nullptr;
	}
	Temp->Data = Data;
	Temp->PtrNext = nullptr;

	return Temp;
}

void _addHead(List& l, Node* PtrNode)
{
	if (l.PtrHead)
	{
		PtrNode->PtrNext = l.PtrHead;
		l.PtrHead = PtrNode;
	}
	else
	{
		l.PtrHead = l.PtrTail = PtrNode;
	}
}

void _addTail(List& l, Node* PtrNode)
{
	if (l.PtrHead)
	{
		l.PtrTail->PtrNext = PtrNode;
		l.PtrTail = PtrNode;
	}
	else
	{
		l.PtrHead = l.PtrTail = PtrNode;
	}
}

void _input(List& l)
{
	_init(l);
	
	int _ILength;
	cout << "Nhap vao so luong nhan vien: ";
	cin >> _ILength;

	// Nhập thông cho các nhân viên.
	for (size_t i = 0; i < _ILength; i++)
	{
		/*int _IData;
		cout << "Nhap gia tri nut " << i + 1 << ": ";
		cin >> _IData;*/

		Employee _Emp;
		cout << "----------------Nhap Thong Tin Nhan Vien " << i + 1 << "----------------" << endl;
		_employeeInputInfo(_Emp);

		_addHead(l, _createNode(_Emp));
		//_addTail(l, _createNode(_Emp));
	}
}

void _output(List l)
{
	if (l.PtrHead == nullptr)
	{
		return;
	}

	/*int _ICount = 1;
	for (Node* i = l.PtrHead; i != nullptr; i = i->PtrNext)
	{
		cout << "-------------------Nhan Vien " << _ICount << "-------------------" << endl;
		_employeeOutputInfo(i->Data);
		++_ICount;
	}*/

	int _ICount = 1;
	Node* i = l.PtrHead; // i = l.PtrHead.
	while (i) // (i != nullptr)
	{
		cout << "-------------------Nhan Vien " << _ICount << "-------------------" << endl;
		_employeeOutputInfo(i->Data);
		++_ICount;
		i = i->PtrNext; // i++
	}
}

double _employeeListSumOfSalary(List l)
{
	if (l.PtrHead)
	{
		double _DSumSaraly = 0;
		Node* i = l.PtrHead;
		while (i)
		{
			_DSumSaraly += i->Data.DSalary;
			i = i->PtrNext;
		}

		return _DSumSaraly;
	}
	return -1;
}

bool _ascending(Employee _EmpA, Employee _EmpB)
{
	return (_EmpA.DSalary < _EmpB.DSalary);
}

bool _descending(Employee _EmpA, Employee _EmpB)
{
	return (_EmpA.DSalary > _EmpB.DSalary);
}

void _employeeListSortSalaryAscDesc(List l, function<bool(Employee, Employee)> _FuncCompar)
{
	if (l.PtrHead)
	{
		for (Node* i = l.PtrHead; i != l.PtrTail; i = i->PtrNext)
		{
			for (Node* j = i->PtrNext; j != nullptr; j = j->PtrNext)
			{
				if (_FuncCompar(i->Data, j->Data))
				{
					swap(i->Data, j->Data);
				}
			}
		}
	}
}

void _freeList(List& l)
{
	if (!l.PtrHead)
	{
		return;
	}

	Node* i = l.PtrHead; // i = l.PtrHead.
	while (l.PtrHead) // (i != nullptr)
	{
		i = l.PtrHead; // Cho nút ảo trỏ tới đầu danh sách.
		l.PtrHead = l.PtrHead->PtrNext; // Cho pHead trỏ vào phần tử kế tiếp.
		delete i;
	}
}
