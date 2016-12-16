#include <iostream>
#include "classy.h" 

using namespace std;

int main()
{
	string name;
	cout << "Enter the course name:" << endl;
	cin >> name;
	GradeBook myGradeBook(name);
	cout << "The final name of the course is:" << myGradeBook.getCourseName();
	
}



