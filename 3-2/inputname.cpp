#include <iostream>
using namespace std;

int main()
{
	int age;
	char name[100];

	//Input your name and age
	cout << "What's your name? ";
	cin >> name;
	cout << "How old are you? ";
	cin >> age;

	//Output the name and age
	cout << "Name: " << name << " ; Age: " << age << endl;

	//More examples
	int a,b;
	cout << "Input two integers:";
	cin >> a >> b;
	char buffer[200];
	cout << "Please type some characters:";
	cin >> buffer;
	
	cout << "Two integers: (" << a << "," << b << ")\n";
	cout << "Some characters: " << buffer << endl;
	return 0;
}
