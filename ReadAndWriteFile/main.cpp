#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int main()
{
	//if (cin){
	//	cout << "cin is ok";
	//}
	ifstream infile("C:\\Cpp_Projects\\cpp_primer_practises\\Debug\\abc.txt");
	string str;
	char AChar;
	//infile.clear();
	//infile.open("C:\Cpp_Projects\cpp_primer_practises\Debug\abc.txt", ios::in | ios::out);
	//
	if (!infile){
		cout << "error when openning file!" << endl;
	}
	cout << infile.get() << endl;
	while (((AChar = infile.get()) != EOF)){
		cout << AChar;
		
	}
	
	getchar();

}
//static  istream& streamParser(istream&)
//{	
//}

////使用get(char *,int n,char delim='\n')一次读多个字符----方案二
////巧妙利用文本文件中不会有字符'\0'的特点进行读取
//#include <fstream>
//#include <iostream>
//using namespace std;
//
//void main()
//{
//	ifstream fin("d:\\简介.txt", ios::nocreate);
//	if (!fin){
//		cout << "File open error!\n";
//		return;
//	}
//	char c[80];
//	while (fin.get(c, 80, '\0') != NULL)cout << c; //注意结束条件的判断
//	fin.close();
//}