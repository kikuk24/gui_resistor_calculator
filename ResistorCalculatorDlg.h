// ResistorCalculatorDlg.h : header file
//

#pragma once

// CResistorCalculatorDlg dialog
class CResistorCalculatorDlg : public CDialogEx
{
	// Construction
public:
	CResistorCalculatorDlg(CWnd* pParent = nullptr);	// standard constructor

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RESISTORCALCULATOR_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	CButton calculateByColor;
	CComboBox m_comboBand1; // Changed from CString to CComboBox
	CComboBox m_comboBand2; // Changed from CString to CComboBox
	CComboBox m_comboBand3; // Changed from CString to CComboBox
	CComboBox m_comboBand4; // Changed from CString to CComboBox
	// Add CString variables for data exchange
	CString m_strBand1; // String for Band 1
	CString m_strBand2; // String for Band 2
	CString m_strBand3; // String for Band 3
	CString m_strBand4; // Str
	afx_msg void OnBnClickedButton1();
	CEdit m_editInputNilai;
	afx_msg void OnBnClickedCombo3();
	afx_msg void OnBnClickedButton3();
	CEdit serialResult;
	afx_msg void OnBnClickedButton4();
};
