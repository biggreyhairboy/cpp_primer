
//#include <stdio.h>
#include <iostream>
#include <cstring>
#include "atlstr.h"
//#include "stdafx.h"
//#include "Windows.h"
//#include <icrsint.h>
#import "E:\Program Files\Common Files\System\ado\msado15.dll"  rename("EOF","adoEOF")
using namespace std;
using namespace ADODB;

int main()
{
	_ConnectionPtr myConnect = NULL;
	HRESULT hr = myConnect.CreateInstance(__uuidof(Connection));
	if (FAILED(hr)) 
		return 0;

	_bstr_t strConnect = "Provider=SQLOLEDB; Server=THINKPAD_T420\SQLEXPRESS; Database=omsdata_maxrich_3; uid=ebs; pwd=ebroker;";
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

	CString strSQL = "select * from user_file";
	myRecordSet = myConnect->Execute(_bstr_t(strSQL), NULL, adCmdText);


	getchar();
	return 0;
}