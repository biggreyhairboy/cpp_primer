
//#include <stdio.h>
#include <iostream>
#include <cstring>
#include "atlstr.h"
#include <string>
//#include "stdafx.h"
//#include "Windows.h"
//#include <icrsint.h>
#import "E:\Program Files\Common Files\System\ado\msado15.dll"  rename("EOF","adoEOF")
using namespace std;
using namespace ADODB;

int main()
{
	_ConnectionPtr myConnect = NULL;
	CoInitialize(NULL);
	HRESULT hr = myConnect.CreateInstance(__uuidof(Connection));
	if (FAILED(hr)) 
		return 0;

	_bstr_t strConnect = "Provider=SQLOLEDB; Server=THINKPAD_T420\\SQLEXPRESS; Database=omsdata_maxrich_3; uid=ebs; pwd=ebroker;";
	try{
		myConnect->Open(strConnect, "", "", NULL);
	}
	catch (_com_error &e){
		//cout << "DB connection error" << e.Description;
	}

	_RecordsetPtr myRecordSet;
	if (FAILED(myRecordSet.CreateInstance(__uuidof(Recordset)))) 
		return 0;
	try{
		myRecordSet->Open(_variant_t("userinfo"), _variant_t((IDispatch*)myConnect), adOpenKeyset, adLockOptimistic, adCmdTable);
	}
	catch (_com_error &e){
		//cout << "RecordSetError " << e.Description;
	}

	myConnect.CreateInstance(__uuidof(Connection));
	myRecordSet.CreateInstance(__uuidof(Recordset));

	_bstr_t strSQL = "select * from user_file";
	myRecordSet = myConnect->Executee(strSQL, NULL, adCmdText);

	while (!myRecordSet->adoEOF){
		CString temp =(TCHAR *)(_bstr_t)myRecordSet->GetFields()->GetItem("User_No")->Value;
		
	}

	getchar();
	return 0;
}

//#include <windows.h>
//#include <stdio.h>
//#include <iostream>
//#import "E:\Program Files\Common Files\System\ADO\msado15.dll"  rename("EOF", "adoEOF")
//using namespace std;
//using namespace ADODB;
//
//int main(int argc, char* argv[])
//{
//
//	HRESULT hr = S_OK;
//	try
//	{
//		CoInitialize(NULL);
//		// Define string variables.
//		_bstr_t strCnn("Provider=SQLOLEDB.1;Persist Security Info=False;UserID=ebs;Password=ebroker;Initial Catalog=omsdata_maxrich_3; Data Source=(local);Integrated Security=SSPI;");
//
//		_RecordsetPtr pRstAuthors = NULL;
//
//		// Call Create instance to instantiate the Record set
//		hr = pRstAuthors.CreateInstance(__uuidof(Recordset));
//
//		if (FAILED(hr))
//		{
//			printf("Failed creating record set instance\n");
//			return 0;
//		}
//
//		//Open the Record set for getting records from Author table
//		pRstAuthors->Open("SELECT Author_ID,username FROM Author", strCnn, adOpenStatic, adLockReadOnly, adCmdText);
//
//		//Declare a variable of type _bstr_t
//		//_bstr_t valField1;
//		//int valField2;
//
//		//pRstAuthors->MoveFirst();
//
//		//Loop through the Record set
//		//if (!pRstAuthors->EndOfFile)
//		//{
//		//	while (!pRstAuthors->EndOfFile)
//		//	{
//		//		valField1 = pRstAuthors->Fields->GetItem("username")->Value;
//		//		valField2 = pRstAuthors->Fields->GetItem("Author_ID")->Value.intVal;
//		//		printf("%d - %s\n", valField2, (LPCSTR)valField1);
//		//		pRstAuthors->MoveNext();
//		//	}
//		//}
//
//	}
//	catch (exception ex)
//	{
//		//printf("Error:%s\n", ce.Description);
//	}
//
//	CoUninitialize();
//	return 0;
//}