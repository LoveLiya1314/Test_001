
// FTP_TestDlg.h : 头文件
//

#pragma once


// CFTP_TestDlg 对话框
class CFTP_TestDlg : public CDialogEx
{
// 构造
public:
	CFTP_TestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FTP_TEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton Connect;
	CButton Update;
	CButton Download;
	CButton Delete;
	CEdit IP_INPUT;
	CListBox ListBox;
	afx_msg void OnClickedConnect();
	afx_msg void OnClickedDelete();
	afx_msg void OnClickedDownload();
	afx_msg void OnSelchangeListbox();
	afx_msg void OnClickedUpdate();
	void OnConnect(CString);
	void OnDownload();
	void OnUpdate();
	void OnDelete();
	void UpdateList();
};
