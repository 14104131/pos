// cd.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "cd.h"
#include <fstream>
#include "afxdialogex.h"
using namespace std;


int a = 0;
// cd 对话框

IMPLEMENT_DYNAMIC(cd, CDialogEx)

cd::cd(CWnd* pParent /*=NULL*/)
	: CDialogEx(cd::IDD, pParent)
{
	
}

cd::~cd()
{
}

void cd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	CButton* radio = (CButton*)GetDlgItem(IDC_RADIO1);

	radio->SetCheck(1);
	CEdit* w;
	w = (CEdit*)GetDlgItem(IDC_EDIT1);
	w->EnableWindow(false);


}


BEGIN_MESSAGE_MAP(cd, CDialogEx)
	ON_BN_CLICKED(IDOK, &cd::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT1, &cd::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_RADIO1, &cd::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &cd::OnBnClickedRadio2)
END_MESSAGE_MAP()


// cd 消息处理程序


void cd::OnBnClickedOk()
{

	if (a==0){
		ofstream myfile("E:\\chuandi.txt", ios::out);

		myfile << 0 << 0 << endl;

		myfile.close();
	}
	else{
		CEdit *w;
		w = (CEdit*)GetDlgItem(IDC_EDIT1);
		
		CString str;
		w->GetWindowText(str);
		int n;
		n = _ttoi(str);
		ofstream myfile("E:\\chuandi.txt", ios::out);

		myfile << 1<<" "<< n << endl;

		myfile.close();

	}
	
	CDialogEx::OnOK();
}


void cd::OnEnChangeEdit1()
{
	

}


void cd::OnBnClickedRadio1()
{
	ofstream myfile("E:\\chuandi.txt", ios::out);

	myfile <<0<<0 <<endl;

	myfile.close();
	CEdit* w;
	w = (CEdit*)GetDlgItem(IDC_EDIT1);
	w->EnableWindow(false);
	a = 0;
}


void cd::OnBnClickedRadio2()
{
	a = 1;
	CEdit* w;
	w = (CEdit*)GetDlgItem(IDC_EDIT1);
	w->EnableWindow(true);
}
