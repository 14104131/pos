
// MFCApplication3Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "MFCApplication3Dlg.h"
#include "afxdialogex.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include "huiyuan.h"
#include "cd.h"
#include <time.h> 
using namespace std;
#ifdef _DEBUG
#define num 10
#define new DEBUG_NEW
#endif
int i = 0;
int products[num];
int no[num];
int success=0;

class seqlist
{
public:
	seqlist();
	~seqlist();
	int locate(int x, double  &aPrice, string &aName, double &aDiscount);
	int locate(int x, int &Apromotion);
private:
	string name[10];
	double  price[10];
	double discount[10];
	int promotion[11];
	
};
int seqlist::locate(int x, int &Apromotion){
	if (x <= -1 || x>num - 1){
		Apromotion = 0;
	}
	else{
		Apromotion = promotion[x];
	}
	return 0;
}

seqlist::seqlist()
{
	ifstream fin("E:\\storage.txt", ios::in);
	if (!fin)
	{
		cout << "cant open";

	}
	for (int i = 0; i < num; i++)
	{

		fin >> name[i] >> price[i] >> discount[i] >> promotion[i];
		cout << "name" << i << ":" << name[i] << " price" << i << ":" << price[i] << " discount" << i << ":" << discount[i] << endl;

	}
	fin.close();
}

seqlist::~seqlist()
{
}

int seqlist::locate(int x, double  &aPrice, string &aName, double &aDiscount){
	if (x <= -1 || x>num - 1){
		aName = "no";
		aPrice = 0;
		aDiscount = 0;
		return 1;
	}
	else{
		aName = name[x];
		aPrice = price[x];
		aDiscount = discount[x];
	}
	return 0;
}

class poscontrol
{
public:
	poscontrol();
	~poscontrol();
	int distotal(seqlist a, double&jieyues, double&totos,huiyuan hui);
	int disprice(seqlist a, int n, double&totaldisprice);
	int search(int n, seqlist a, double &price, string &name, double &discount);
	int unit_price(seqlist a, int n, double&price);
private:
	double sdddddddddd[20];
};

int poscontrol::search(int n, seqlist a, double &price, string &name, double &discount){
	a.locate(n, price, name, discount);
	return 0;
}

int poscontrol::disprice(seqlist a, int n, double &disprice){
	string name; double price, discount;
	search(n, a, price, name, discount);
	disprice = price*discount;
	return 0;
}
int poscontrol::unit_price(seqlist a, int n, double &price){
	string name; double discount;
	search(n, a, price, name, discount);
	return 0;
}

int poscontrol::distotal(seqlist a, double &jieyues, double &totos,huiyuan hui){
	int n, b;
	ifstream fin("E:\\chuandi.txt", ios::in);
	fin >> n >> b;
	
	if (n == 1){
		if (hui.hui_(b)){
			double toto = 0, price=0, jieyue = 0, prices=0;

			for (int j = 0; j < i; j++){
				disprice(a, products[j], price);
				unit_price(a, products[j], prices);
				toto = toto + price*no[j];
				jieyue = jieyue + (prices - price)*no[j];
				totos = toto;
				jieyues = jieyue;

			}
			string shangpinmingzi;
			double pricess=0, discount=0;
			ofstream myfile("E:\\output.txt", ios::out);
			if (!myfile)
			{
				return 1;
			}
			else{

				myfile << "**********购物信息***********" << endl;
				myfile << "       user:" << b << endl;
				myfile << "____________________________________________________" << endl;

				time_t t = time(0);
				char tmp[64];
				strftime(tmp, sizeof(tmp), "%Y/%m/%d %X %A", localtime(&t));
				myfile << tmp << endl;
				myfile << "___________________________________________________________________" << endl;
				for (int j = 0; j < i; j++){
					search(products[j], a, pricess, shangpinmingzi, discount);
					disprice(a, products[j], pricess);

					myfile << "商品编号:" << products[j] << "    " << "名称：" << shangpinmingzi << "    " << "数量:" << no[j] << "    " << "单价" << prices << "    " << "小计" << no[j] * pricess << endl;
					myfile << "-------------------------------------------------------------------" << endl;
				}
				int ms;
				for (int j = 0; j < i; j++){
					a.locate(products[j], ms);
					search(products[j], a, pricess, shangpinmingzi, discount);
					if (ms == 1 && no[j] >= 2){
						
						myfile << "挥泪赠送" << shangpinmingzi << "一个" << endl;
					}
				}
				int c = hui.jifen_(b);
				int jifenb=0;
				if (c <= 200){
					hui.gaijifen_(b, jifenb=(int)totos / 5);
				}
				else if (c > 200 && 500){
					hui.gaijifen_(b, jifenb=(int) 3 * totos / 5);
				}
				else {
					hui.gaijifen_(b, jifenb=(int)totos);
				}
				myfile << "总计" << totos << "    " << "节约：" << jieyue << endl;
				myfile << "您的积分增加了" <<jifenb << "分" << endl;
				myfile << "*********谢谢惠顾*************" << endl;

			}
			myfile.close();
		}
	}
	else{
		double tototototo = 0;
		ofstream myfile("E:\\output.txt", ios::out);
		string shangpinmingzi;
		double pricess, discount;
		myfile << "*********商品信息**********" << endl;
		for (int j = 0; j < i; j++)
		{
			search(products[j], a, pricess, shangpinmingzi, discount);
			unit_price(a, products[j], pricess);
			tototototo = tototototo + no[j] * pricess;
			myfile << "商品编号:" << products[j] << "    " << "名称：" << shangpinmingzi << "    " << "数量:" << no[j] << "    " << "单价" << pricess << "    " << "小计" << no[j] * pricess << endl;
			myfile << "-------------------------------------------------------------------" << endl;
			
			myfile << "*********谢谢惠顾*************" << endl;

		}
		myfile << "总计：" << tototototo << endl;

	}
	return 0;
}


poscontrol::poscontrol()
{
}

poscontrol::~poscontrol()
{
}

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication3Dlg 对话框



CMFCApplication3Dlg::CMFCApplication3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication3Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication3Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication3Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication3Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication3Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication3Dlg::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCApplication3Dlg::OnEnChangeEdit2)
END_MESSAGE_MAP()


// CMFCApplication3Dlg 消息处理程序

BOOL CMFCApplication3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication3Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCApplication3Dlg::OnBnClickedButton1()
{
	
	
	CEdit*edit1, *edit2,*edit3;
	edit1 = (CEdit*)GetDlgItem(IDC_EDIT1);
	edit2 = (CEdit*)GetDlgItem(IDC_EDIT2);
	edit3 = (CEdit*)GetDlgItem(IDC_EDIT3);
	CString pro, prono, clears(""),wrotext("输入错误，请重新输入！");
	int pros, pronos;
	edit1->GetWindowText(pro);
	edit2->GetWindowText(prono);
	CString chengg("输入成功，请继续输入或打印！");



	pros = _ttoi(pro);
	pronos = _ttoi(prono);
	if (pros <= 0) {
		edit3->SetWindowText(wrotext);
	}

	else if (pros<0 || pros>num)
	{
		edit3->SetWindowText(wrotext);
	}
	else if (pronos<=0)
		edit3->SetWindowText(wrotext);
	else{
		products[i] = pros;
		no[i] = pronos;
		i++;
		edit3->SetWindowText(clears);
		edit3->SetWindowText(chengg);
		success++;
	}
	edit1->SetWindowText(clears);
	edit2->SetWindowText(clears);
	


}


void CMFCApplication3Dlg::OnBnClickedButton2()
{
		CEdit*edit1, *edit2, *edit3;
		edit1 = (CEdit*)GetDlgItem(IDC_EDIT1);
		edit2 = (CEdit*)GetDlgItem(IDC_EDIT2);
		edit3 = (CEdit*)GetDlgItem(IDC_EDIT3);
		poscontrol m;
		seqlist a;
		huiyuan hui;
		double jieyue, totos;
		m.distotal(a, jieyue, totos, hui);
		CString str("打印成功");
		CString strw("打印错误");
	if (success == 0){

		edit3->SetWindowText(strw);
	}
	else
	{

		edit3->SetWindowText(str);
		if (m.distotal(a, jieyue, totos, hui))
			edit3->SetWindowText(strw);
	}

}




void CMFCApplication3Dlg::OnBnClickedButton4()
{
	ofstream myfile("E:\\chuandi.txt", ios::out);

	myfile << 0<<" " << 0 << endl;

	myfile.close();
	dlg = new cd();
	dlg->Create(IDD_DIALOG1, this);
	dlg->ShowWindow(SW_SHOWNORMAL);
}


void CMFCApplication3Dlg::OnBnClickedButton3()
{
	
	CDialogEx::OnOK();
}


void CMFCApplication3Dlg::OnEnChangeEdit2()
{

}
