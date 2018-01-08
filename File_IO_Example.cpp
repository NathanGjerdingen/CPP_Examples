#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//Size of all arrarys used.
const int SIZE = 4;

//Structure for students.
struct studentInfo {
	char name[15];
	int age;
	double gpa;
	char grade;
};

//Displays any array passed.
void displayData(studentInfo sI[]) {
	for (int i = 0; i < SIZE; i++)
	{
		cout << sI[i].name << endl;
		cout << sI[i].age << endl;
		cout << sI[i].gpa << endl;
		cout << sI[i].grade << endl;
		cout << endl;
	}
}

//Displays single file of array.
void displayFile(studentInfo sI[], int n) {
	cout << sI[n].name << endl;
	cout << sI[n].age << endl;
	cout << sI[n].gpa << endl;
	cout << sI[n].grade << endl;
	cout << endl;
}

int main() {
	//Initializing all variables.
	ofstream oFile1, oFile2;
	ifstream iFile1, iFile2;
	studentInfo students[SIZE] = { { "Ann Annson", 10, 1.10, 'D' },
	{ "Bill Billson", 20, 2.20, 'C' },
	{ "Carl Carlson", 30, 3.30, 'B' },
	{ "Don Donson", 40, 4.00, 'A' } };

	studentInfo studentsText[SIZE];
	studentInfo studentsBinary[SIZE];
	studentInfo temp[SIZE];
	int studentFile;

	//Open files for output.
	oFile1.open("student.txt");
	oFile2.open("student.bin", ios::binary);

	//Loop assigning contents of students[] to oFile1. TEXT MODE.
	for (int a = 0; a < SIZE; a++) {
		oFile1 << students[a].name << endl;
		oFile1 << students[a].age << endl;
		oFile1 << students[a].gpa << endl;
		oFile1 << students[a].grade << endl;
	}

	//Assigning the contents of students[] to oFile2. BINARY MODE.
	oFile2.write(reinterpret_cast<char *>(&students), sizeof(students));

	//Close files for output.
	oFile1.close();
	oFile2.close();

	//Open files for input
	iFile1.open("student.txt");
	iFile2.open("student.bin", ios::binary);

	//Assing contents to studentsText from student.bin.
	for (int b = 0; b < SIZE; b++) {
		iFile1.getline(studentsText[b].name, sizeof(studentsText[b].name));
		iFile1 >> studentsText[b].age;
		iFile1 >> studentsText[b].gpa;
		iFile1 >> studentsText[b].grade;
		iFile1.ignore();
	}

	//Assign contents of student.bin to students[]
	iFile2.read(reinterpret_cast<char *>(&studentsBinary), sizeof(studentsBinary));

	//Display data.
	cout << "Displaying data from studentText[]..." << endl;
	displayData(studentsText);
	cout << "Displaying data from studentBinary[]..." << endl;
	displayData(studentsBinary);

	//Close files for input.
	iFile1.close();
	iFile2.close();

	//Open student.bin and assign contents to temp.
	iFile2.open("student.bin", ios::in | ios::out | ios::binary);
	iFile2.seekg(0, ios::beg);
	iFile2.read(reinterpret_cast<char *>(&temp), sizeof(temp));
	iFile2.close();

	//Prompt user for the file they wish to view.
	cout << "Please enter the number of any student file you wish to veiw...\n"
		<< "1: Ann\n"
		<< "2: Bill\n"
		<< "3: Carl\n"
		<< "4: Don\n";

	//Display it.
	cin >> studentFile;
	displayFile(temp, --studentFile);

	//Close students.bin.
	iFile2.close();

	return 0;
}
