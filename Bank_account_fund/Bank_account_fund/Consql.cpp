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
//	void OnInitADOConn();//��ʼ������
//	void ExecuteSQL(_bstr_t bstrSQL);
//};
//ADOConn::ADOConn()
//{
//	CoInitialize(NULL); //��ʼ���ز�����
//	HRESULT hr = m_pConnection.CreateInstance(_uuidof(Connection));
//	if (FAILED(hr))
//		cout << "_ConnectionPtr����ָ��ʵ����ʧ�ܣ�����" << endl;
//}
//
//void ADOConn::OnInitADOConn()
//{
//	try
//	{	//��COM�ӿ��У�������Ϊ�ַ����� һ��Ҫ��BSTR  
//		_bstr_t con_bstr = "Driver={sql server};server=127.0.0.1,1433;uid=mysa;pwd=11;database=CTXSYS;";
//		m_pConnection->Open(con_bstr, "", "", adModeUnknown);// adModeUnknown ȱʡ����ǰ�����Ȩδ����
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
//	_bstr_t strSql = "select * from  TB_SHANGPIN";//ѡ����SQL��� 
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
