#include <iostream>
#include <fstream>
using namespace std;

//char probil = ' ';
//struct Coord
//{
//	int x;
//	int y;
//};
//
//class Rectangle
//{
//private:
//
//	int width;
//	int height;
//	char symb;
//	Coord coord;
//
//	bool IsCorrectSize(int size) const
//	{
//		return size > 0;
//	}
//
//public:
//
//
//	Rectangle()
//	{
//		cout << "Construktor -default-" << endl;
//		width = 6;
//		height = 3;
//		symb = '@';
//		coord = { 0, 0 };
//
//	}
//	Rectangle(int size)
//	{
//		cout << "Construktor -parametrized(1)-" << endl;
//		symb = '#';
//		width = (IsCorrectSize(size) ? size : 1);
//		height = (IsCorrectSize(size) ? size : 1);
//		coord = { 0, 0 };
//	}
//	Rectangle(int _width, int _height) {
//		cout << "Construktor -parametrized(2)-" << endl;
//		width = (IsCorrectSize(_width) ? _width : 1);
//		height = (IsCorrectSize(_height) ? _height : 1);
//	}
//	void SetSymbol(char _symbol)
//	{
//		if (_symbol != ' ')
//		{
//			symb = _symbol;
//		}
//	}
//	void AddOptions() {
//
//		cout << "Enter width:" << endl;
//		cin >> width;
//		cout << "Enter height:" << endl;
//		cin >> height;
//		cout << "Enter symbol:" << endl;
//		cin >> symb;
//		cout << "Enter coordinate x:" << endl;
//		cin >> coord.x;
//		cout << "Enter coordinate y:" << endl;
//		cin >> coord.y;
//	}
//
//	void ChangeSize(int _width, int _height) {
//
//		if (IsCorrectSize( _width)) {
//			width = _width;
//		}
//		if (IsCorrectSize(_height)) {
//			height = _height;
//		}
//	}
//	void ChangeCoord(int _koordX, int _koordY) {
//
//		if (IsCorrectSize(_koordX)) {
//			coord.x = _koordX;
//		}
//		if (IsCorrectSize(_koordY)) {
//			coord.y = _koordY;
//		}
//	}
//	void Print() const
//	{
//		system("cls");
//		for (int a = 0; a < coord.y; a++) {
//			cout << endl;
//		}
//		for (int i = 0; i < width; i++) {
//			for (int b = 0; b < coord.x; b++) {
//				cout << probil;
//			}
//			for (int j = 0; j < height; j++) {
//				cout << symb;
//			}
//			cout << endl;
//		}
//
//	}
//};
class Student
{
private:
	char* name;
	int age;
	int* marks;
	int countMarks;
	float avgMark;

	
	bool IsValidAge(int age) const
	{
		return age >= 0 && age <= 100;
	}

	void SetAverageMark() {
		int suma = 0;
		for (int i = 0; i < countMarks; i++) {
			suma += marks[i];
		}
		avgMark = suma / countMarks;
	}
public:
	Student() 
	{
		cout << "Constructor -default-" << endl;
		name = nullptr;
		SetName("No name");
		age = 0;
		countMarks = 0;
		avgMark = 0;
	}
	
	Student(const char* _name, int _age)
	{
		cout << "Constructor -parametrized-"<<endl;
		name = nullptr;
		SetName(_name);
		if (IsValidAge(_age))
			age = _age;
		else
			age = 0;
		marks = 0;
		countMarks = 0;
		avgMark = 0;
	}

	~Student()
	{
		cout << "-Desctructor- "<<endl;
		if (name != nullptr) {
			delete[] name;
			delete[] marks;
		}
	}

	const char* GetName() const
	{
		return name;
	}

	void SetName(const char* _name)
	{
		if (name != nullptr)
			delete[] name;

		int size = strlen(_name) + 1;
		name = new char[size];
		strcpy_s(name, size, _name);
	}
	
	void AddMark(int _mark)
	{
		if (_mark <= 0 || _mark>12) {
			cout << "Error: incorrect mark!" << endl;
		}
		int* temp = new int[countMarks + 1];

		for (int i = 0; i < countMarks; i++) {
			temp[i] = marks[i];
		}

		temp[countMarks] = _mark;
		countMarks++;
		delete[] marks;
		marks = temp;
		SetAverageMark();
	}
	
	void Print() const
	{
		cout << "\t\t\t-STUDENT -\n";
		if (name != nullptr) {
			cout << "NAME: " << name << endl;
		}
		cout << "Age: " << age << endl;
		cout << "Marks: ";
		for (int i = 0; i < countMarks; i++) {
			cout << marks[i] << ", ";
		}
		cout << endl;
		cout << "Average mark: " << avgMark << endl;
		cout << "Count marks: " << countMarks << endl;

		cout << "------------------------------\n";
	}

	void Save() {
		ofstream fout;
		fout.open("Students.txt", fstream::app);
		bool isOpen = fout.is_open();
		if (isOpen == true) {
			fout << name << endl;
			fout << age << endl;
			for (int i = 0; i < countMarks; i++) {
				fout << marks[i] << endl;
			}
			fout << avgMark << endl;
			fout << countMarks << endl;
			fout.close();
		}
		else {
			cout << "Error: Application can't open data file!" << endl;
		}
	}

	void Load() {
		ifstream fin;
		fin.open("Students.txt");
		bool isOpen = fin.is_open();
		if (isOpen == true)
		{
			while (!fin.eof())
			{
				fin >> name;
				fin >> age;
				marks = new int[countMarks];
				for (int i = 0; i < countMarks; i++) {
					fin >> marks[i];
				}
				fin >> avgMark;
				fin >> countMarks;
			}
		}
		else {
			cout << "Error: Application can't open data file!" << endl;
		}
		fin.close();
	}
};

int main() {

	/*Rectangle One;
	Rectangle Two(5);
	Rectangle Three(3,5);

	One.ChangeSize(5,9);
	One.ChangeCoord(10,10);
	One.SetSymbol('%');
	One.Print();

	Two.AddOptions();
	Two.Print();*/

	Student St1;
	St1.Print();

	Student St2("Natasha",20);
	St2.Print();
	Student St3("Liza",18);
	St3.AddMark(11);
	St3.AddMark(10);
	St3.AddMark(12);
	St3.Print();

	St3.Save();
	St3.Load();

	system("pause");
	return 0;
}