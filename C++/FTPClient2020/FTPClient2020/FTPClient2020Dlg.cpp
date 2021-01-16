
// FTPClient2020Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "FTPClient2020.h"
#include "FTPClient2020Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



//------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
CInternetSession* m_pInetSession;					//声明FTP套件有关的函数，方便今后使用
CFtpConnection* m_pFtpConnection;					//声明FTP套件有关的函数，方便今后使用
CFtpFileFind* m_pRemoteFile;						//声明FTP套件有关的函数，方便今后使用
CString m_pRemoteFileName, m_LocateFileName;		//声明FTP套件有关的函数，方便今后使用

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


// CFTPClient2020Dlg 对话框



CFTPClient2020Dlg::CFTPClient2020Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FTPCLIENT2020_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFTPClient2020Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Connect, Connect);
	DDX_Control(pDX, IDC_Update, Update);
	DDX_Control(pDX, IDC_Download, Download);
	DDX_Control(pDX, IDC_Delete, Delete);
	DDX_Control(pDX, IDC_IP_INPUT, IP_INPUT);
	DDX_Control(pDX, IDC_ListBox, ListBox);
}

BEGIN_MESSAGE_MAP(CFTPClient2020Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Connect, &CFTPClient2020Dlg::OnClickedConnect)
	ON_BN_CLICKED(IDC_Delete, &CFTPClient2020Dlg::OnClickedDelete)
	ON_BN_CLICKED(IDC_Download, &CFTPClient2020Dlg::OnClickedDownload)
	ON_LBN_SELCHANGE(IDC_ListBox, &CFTPClient2020Dlg::OnSelchangeListbox)
	ON_BN_CLICKED(IDC_Update, &CFTPClient2020Dlg::OnClickedUpdate)
END_MESSAGE_MAP()


// CFTPClient2020Dlg 消息处理程序

BOOL CFTPClient2020Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

void CFTPClient2020Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFTPClient2020Dlg::OnPaint()
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
HCURSOR CFTPClient2020Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFTPClient2020Dlg::OnClickedConnect()
{
	// TODO: 在此添加控件通知处理程序代码
	CString Address;//声明变量
	GetDlgItemText(IDC_IP_INPUT, Address);//获得输入框所输入的地址 复制给Address
	OnConnect(Address);//调用OnConnect函数 把IP地址赋值
	this->UpdateList();//更新列表
}


void CFTPClient2020Dlg::OnClickedDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	this->OnDelete();
	this->UpdateList();

}


void CFTPClient2020Dlg::OnClickedDownload()
{
	// TODO: 在此添加控件通知处理程序代码
	this->OnDownload();
	this->UpdateList();
}


void CFTPClient2020Dlg::OnSelchangeListbox()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CFTPClient2020Dlg::OnClickedUpdate()
{
	// TODO: 在此添加控件通知处理程序代码
	this->OnUpdate();
	this->UpdateList();
}


void CFTPClient2020Dlg::OnConnect(CString m_IPaddress)
{
	// TODO: 在此处添加实现代码.
	m_pInetSession = new CInternetSession(AfxGetAppName(), 1, PRE_CONFIG_INTERNET_ACCESS);
	m_pFtpConnection = m_pInetSession->GetFtpConnection(m_IPaddress);
	m_pRemoteFile = new CFtpFileFind(m_pFtpConnection);
}


void CFTPClient2020Dlg::OnDownload()
{
	// TODO: 在此处添加实现代码.
	CString selfile;
	ListBox.GetText(ListBox.GetCurSel(), selfile);//获得想要下载资源名
	if (!selfile.IsEmpty())
	{
		//弹出另存为对话框
		CFileDialog file(FALSE, NULL, selfile, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, L"所有文件(*.*)|*.*|", this);
		if (file.DoModal() == IDOK)
		{
			CString strname;
			strname = file.GetFileName();
			CString strdir;
			m_pFtpConnection->GetCurrentDirectory(strdir);
			m_pFtpConnection->GetFile(selfile, strname);//下载文件到的本地位置
			m_pInetSession->Close();
			this->OnClickedConnect();
			m_pFtpConnection->SetCurrentDirectory(strdir);
			this->UpdateList();
			AfxMessageBox(_T("下载成功！"));
		}


	}
}


void CFTPClient2020Dlg::OnUpdate()
{
	// TODO: 在此处添加实现代码.
	CString str;
	CString strname;
	//弹出“打开”对话框
	CFileDialog file(true, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, L"所有文件(*.*)|*.*|", this);
	if (file.DoModal() == IDOK)
	{
		str = file.GetPathName();
		strname = file.GetFileName();
	}
	
		CString strdir;
		m_pFtpConnection->GetCurrentDirectory(strdir);
		//上传文件
		BOOL bput = m_pFtpConnection->PutFile((LPCTSTR)str, (LPCTSTR)strname);
		if (bput)
		{
			m_pInetSession->Close();//关闭会话
			this->OnClickedConnect();//重新连接保持持续会话
			m_pFtpConnection->SetCurrentDirectory(strdir);
			this->UpdateList();//更新目录列表
			AfxMessageBox(_T("上传成功！"));
		}
	
}


void CFTPClient2020Dlg::OnDelete()
{
	// TODO: 在此处添加实现代码.
	CString selfile;
	ListBox.GetText(ListBox.GetCurSel(), selfile);//获取用户要删除的资源名
	if (!selfile.IsEmpty())
	{
		if (AfxMessageBox(L"确定要删除这个文件？", 4 + 48) == 6)
		{
			m_pFtpConnection->Remove(selfile);
		}
		CString strdir;
		m_pFtpConnection->GetCurrentDirectory(strdir);
		m_pInetSession->Close();
		this->OnClickedConnect();
		m_pFtpConnection->SetCurrentDirectory(strdir);
		this->UpdateList();
	}
}


void CFTPClient2020Dlg::UpdateList()
{
	// TODO: 在此处添加实现代码.
	ListBox.ResetContent();//自己声明的列表的变量名
	//创建一个CFtpFileFind实例
	CFtpFileFind ftpfind(m_pFtpConnection);//建立连接的实例
	CString strdirpath;
	m_pFtpConnection->GetCurrentDirectory(strdirpath);
	//找到第一个文件或者文件夹
	BOOL bfind = ftpfind.FindFile(strdirpath);
	while (bfind)
	{
		bfind = ftpfind.FindNextFile();
		CString strpath;
		if (ftpfind.IsDots())
			continue;
		if (!ftpfind.IsDirectory())  //判断是目录还是文件
		{
			strpath = ftpfind.GetFileName(); //文件则读取文件名
			ListBox.AddString(strpath);
		}
		else
		{
			strpath = ftpfind.GetFilePath();
			ListBox.AddString(strpath);
		}
	}
}
