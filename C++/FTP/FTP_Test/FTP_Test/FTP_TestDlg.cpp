
// FTP_TestDlg.cpp : ʵ���ļ�
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
//����FTP�׼��йصĺ�����������ʹ��


CInternetSession* m_pInetSession;
CFtpConnection* m_pFtpConnection;
CFtpFileFind* m_pRemoteFile;
CString m_pRemoteFileName, m_LocateFileName;



// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CFTP_TestDlg �Ի���



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


// CFTP_TestDlg ��Ϣ�������

BOOL CFTP_TestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CFTP_TestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CFTP_TestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFTP_TestDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CFTP_TestDlg::OnClickedConnect()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CFTP_TestDlg::OnClickedUpload()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CFTP_TestDlg::OnClickedDelete()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CFTP_TestDlg::OnClickedDownload()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CFTP_TestDlg::OnSelchangeListBox()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
