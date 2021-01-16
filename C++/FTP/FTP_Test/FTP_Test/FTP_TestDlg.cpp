
// FTP_TestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "FTP_Test.h"
#include "FTP_TestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
//声明FTP套件有关的函数，方便今后使用


CInternetSession* m_pInetSession;
CFtpConnection* m_pFtpConnection;
CFtpFileFind* m_pRemoteFile;
CString m_pRemoteFileName, m_LocateFileName;



// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFTP_TestDlg 对话框



CFTP_TestDlg::CFTP_TestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FTP_TEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFTP_TestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFTP_TestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CFTP_TestDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_Connect, &CFTP_TestDlg::OnClickedConnect)
	ON_BN_CLICKED(IDC_Upload, &CFTP_TestDlg::OnClickedUpload)
	ON_BN_CLICKED(IDC_Delete, &CFTP_TestDlg::OnClickedDelete)
	ON_BN_CLICKED(IDC_Download, &CFTP_TestDlg::OnClickedDownload)
	ON_LBN_SELCHANGE(IDC_List_Box, &CFTP_TestDlg::OnSelchangeListBox)
END_MESSAGE_MAP()


// CFTP_TestDlg 消息处理程序

BOOL CFTP_TestDlg::OnInitDialog()
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

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CFTP_TestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFTP_TestDlg::OnPaint()
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
HCURSOR CFTP_TestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFTP_TestDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CFTP_TestDlg::OnClickedConnect()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CFTP_TestDlg::OnClickedUpload()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CFTP_TestDlg::OnClickedDelete()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CFTP_TestDlg::OnClickedDownload()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CFTP_TestDlg::OnSelchangeListBox()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CFTP_TestDlg::OnConnect(CString m_IPadress)
{
	m_pInetSession = new CInternetSession(AfxGetAppName(), 1, PRE_CONFIG_INTERNET_ACCESS);
	m_pFtpConnection = m_pInetSession->GetFtpConnection(m_IPaddress);
	m_pRemoteFile = new CFtpFileFind(m_pFtpConnection);

}


void CFTP_TestDlg::OnDelete()
{
}


void CFTP_TestDlg::OnDownload()
{
}


void CFTP_TestDlg::OnUpload()
{
}


void CFTP_TestDlg::UpdateList()
{
}
