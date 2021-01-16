
// FTP_TestDlg.h : ͷ�ļ�
//

#pragma once


// CFTP_TestDlg �Ի���
class CFTP_TestDlg : public CDialogEx
{
// ����
public:
	CFTP_TestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FTP_TEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
