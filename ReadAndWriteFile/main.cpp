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

////ʹ��get(char *,int n,char delim='\n')һ�ζ�����ַ�----������
////���������ı��ļ��в������ַ�'\0'���ص���ж�ȡ
//#include <fstream>
//#include <iostream>
//using namespace std;
//
//void main()
//{
//	ifstream fin("d:\\���.txt", ios::nocreate);
//	if (!fin){
//		cout << "File open error!\n";
//		return;
//	}
//	char c[80];
//	while (fin.get(c, 80, '\0') != NULL)cout << c; //ע������������ж�
//	fin.close();
//}