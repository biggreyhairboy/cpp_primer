#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int main()
{
	//if (cin){
	//	cout << "cin is ok";
	//}
	ifstream infile;
	string str;
	char AChar;
	infile.open("abc.txt", ifstream::in);
	while ((AChar = infile.get() != EOF)){
		cout << AChar;
		
	}
	
	getchar();

}
static  istream& streamParser(istream&)
{	
}