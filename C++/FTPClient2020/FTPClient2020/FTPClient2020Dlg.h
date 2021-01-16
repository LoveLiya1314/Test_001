
// FTPClient2020Dlg.h: 头文件
//

#pragma once


// CFTPClient2020Dlg 对话框
class CFTPClient2020Dlg : public CDialogEx
{
// 构造
public:
	CFTPClient2020Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FTPCLIENT2020_DIALOG };
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
