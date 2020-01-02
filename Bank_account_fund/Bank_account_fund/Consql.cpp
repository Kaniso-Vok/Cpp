#define _CRT_SECURE_NO_WARNINGS 1


























//#include "stdafx.h"
//#include <tchar.h>
//#include<iostream>
//#include <string>
//#import "C:/Program Files/Common Files/System/ado/msado15.dll" no_namespace rename("EOF","adoEOF")
//using namespace std;
//class ADOConn
//{
//public:
//	_ConnectionPtr m_pConnection;
//	_RecordsetPtr m_pRecordset;
//public:
//	ADOConn();
//	virtual ~ADOConn();
//	void OnInitADOConn();//初始化连接
//	void ExecuteSQL(_bstr_t bstrSQL);
//};
//ADOConn::ADOConn()
//{
//	CoInitialize(NULL); //初始化必不可少
//	HRESULT hr = m_pConnection.CreateInstance(_uuidof(Connection));
//	if (FAILED(hr))
//		cout << "_ConnectionPtr对象指针实例化失败！！！" << endl;
//}
//
//void ADOConn::OnInitADOConn()
//{
//	try
//	{	//在COM接口中，参数若为字符串， 一定要用BSTR  
//		_bstr_t con_bstr = "Driver={sql server};server=127.0.0.1,1433;uid=mysa;pwd=11;database=CTXSYS;";
//		m_pConnection->Open(con_bstr, "", "", adModeUnknown);// adModeUnknown 缺省，当前的许可权未设置
//	}
//	catch (_com_error &e)
//	{
//		cout << e.Description() << endl;
//	}
//}
//void ADOConn::ExecuteSQL(_bstr_t bstrSQL)
//{
//	m_pRecordset = m_pConnection->Execute(bstrSQL, NULL, adCmdText);
//}
//
//int main(int argc, _TCHAR* argv[])
//{
//	_bstr_t strSql = "select * from  TB_SHANGPIN";//选择表的SQL语句 
//	ADOConn con;
//	con.OnInitADOConn();
//	con.ExecuteSQL(strSql);
//	string res;
//	while (!con.m_pRecordset->adoEOF)
//	{
//		res = (_bstr_t)con.m_pRecordset->GetFields()->GetItem("SPBH")->Value;
//		res += "\t";
//		res += (_bstr_t)con.m_pRecordset->GetFields()->GetItem("SPMC")->Value;
//		res += "\t";
//		res += (_bstr_t)con.m_pRecordset->GetFields()->GetItem("SPJM")->Value;
//		res += "\t";
//		res += (_bstr_t)con.m_pRecordset->GetFields()->GetItem("SPLB")->Value;
//		cout << res << endl;;
//		con.m_pRecordset->MoveNext();
//	}
//	return 0;
//}
