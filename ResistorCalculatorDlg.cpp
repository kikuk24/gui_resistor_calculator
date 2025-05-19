
// ResistorCalculatorDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "ResistorCalculator.h"
#include "ResistorCalculatorDlg.h"
#include "afxdialogex.h"
#include <vector>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
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


// CResistorCalculatorDlg dialog



CResistorCalculatorDlg::CResistorCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RESISTORCALCULATOR_DIALOG, pParent)
	, m_comboBand1() 
	, m_comboBand2() 
	, m_comboBand3() 
	, m_comboBand4() 
	, m_strBand1(_T("")) 
	, m_strBand2(_T("")) 
	, m_strBand3(_T("")) 
	, m_strBand4(_T("")) // CString initialization remains
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CResistorCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, calculateByColor);
	DDX_Control(pDX, IDC_COMBO1, m_comboBand1);
	DDX_Control(pDX, IDC_COMBO2, m_comboBand2);
	DDX_Control(pDX, IDC_COMBO3, m_comboBand3);
	DDX_Control(pDX, IDC_COMBO4, m_comboBand4);

	// Bind CString variables to combo boxes
	DDX_CBString(pDX, IDC_COMBO1, m_strBand1);
	DDX_CBString(pDX, IDC_COMBO2, m_strBand2);
	DDX_CBString(pDX, IDC_COMBO3, m_strBand3);
	DDX_CBString(pDX, IDC_COMBO4, m_strBand4);
	DDX_Control(pDX, IDC_EDIT1, m_editInputNilai);
	DDX_Control(pDX, IDC_EDIT3, serialResult);
}

BEGIN_MESSAGE_MAP(CResistorCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CResistorCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_COMBO3, &CResistorCalculatorDlg::OnBnClickedCombo3)
	ON_BN_CLICKED(IDC_BUTTON3, &CResistorCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CResistorCalculatorDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CResistorCalculatorDlg message handlers

BOOL CResistorCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	// Daftar warna resistor
    CString colors[] = {
        _T("Black"), _T("Brown"), _T("Red"), _T("Orange"),
        _T("Yellow"), _T("Green"), _T("Blue"), _T("Violet"),
        _T("Gray"), _T("White")
    };

    CString multipliers[] = {
        _T("Black (x1)"), _T("Brown (x10)"), _T("Red (x100)"), _T("Orange (x1k)"),
        _T("Yellow (x10k)"), _T("Green (x100k)"), _T("Blue (x1M)"), _T("Violet (x10M)"),
        _T("Gray (x100M)"), _T("White (x1G)"), _T("Gold (x0.1)"), _T("Silver (x0.01)")
    };

    CString tolerances[] = {
        _T("Brown (±1%)"), _T("Red (±2%)"), _T("Green (±0.5%)"), _T("Blue (±0.25%)"),
        _T("Violet (±0.1%)"), _T("Gray (±0.05%)"), _T("Gold (±5%)"), _T("Silver (±10%)")
    };

    // Isi band 1 dan 2 dengan warna 0–9
    for (int i = 0; i < 10; i++) {
        m_comboBand1.AddString(colors[i]);
        m_comboBand2.AddString(colors[i]);
    }

    // Isi multiplier
    for (int i = 0; i < 12; i++) {
		m_comboBand3.AddString(multipliers[i]);
    }

    // Isi tolerance
    for (int i = 0; i < 8; i++) {
		m_comboBand4.AddString(tolerances[i]);
    }

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CResistorCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CResistorCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CResistorCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//calculate by color
void CResistorCalculatorDlg::OnBnClickedButton1()
{
	int band1 = m_comboBand1.GetCurSel();     // Digit pertama (0–9)
	int band2 = m_comboBand2.GetCurSel();     // Digit kedua (0–9)
	int multiplier = m_comboBand3.GetCurSel();// Multiplier (0–11)
	int tolerance = m_comboBand4.GetCurSel(); // Tolerance (0–7)

	// Validasi input
	if (band1 < 0 || band2 < 0 || multiplier < 0 || tolerance < 0) {
		AfxMessageBox(_T("Pilih semua warna terlebih dahulu."));
		return;
	}

	// Daftar nilai multiplier sesuai urutan multipliers[]
	double multiplierValues[] = {
		1,         // Black
		10,        // Brown
		100,       // Red
		1000,      // Orange
		10000,     // Yellow
		100000,    // Green
		1000000,   // Blue
		10000000,  // Violet
		100000000, // Gray
		1000000000,// White
		0.1,       // Gold
		0.01       // Silver
	};

	// Daftar toleransi sesuai urutan tolerances[]
	CString toleranceText[] = {
		_T("±1%"),    // Brown
		_T("±2%"),    // Red
		_T("±0.5%"),  // Green
		_T("±0.25%"), // Blue
		_T("±0.1%"),  // Violet
		_T("±0.05%"), // Gray
		_T("±5%"),    // Gold
		_T("±10%")    // Silver
	};

	// Hitung nilai resistor
	int baseValue = band1 * 10 + band2;
	double resistance = baseValue * multiplierValues[multiplier];

	// Format hasil
	CString result;
	if (resistance == (int)resistance) {
		result.Format(_T("%d"), (int)resistance);
	}
	else {
		result.Format(_T("Nilai Resistor: %.2f Ohm %s"), resistance, toleranceText[tolerance].GetString());
	}
	m_editInputNilai.SetWindowText(result);

	//this->MessageBox(result, _T("Resistor Calculator"), MB_OK | MB_ICONINFORMATION);
	this->MessageBox(
		_T("Perhitungan resistor berhasil!"),
		_T("Sukses"),
		MB_OK | MB_ICONINFORMATION
	);

}

// Count By Number
void CResistorCalculatorDlg::OnBnClickedCombo3()
{
	// TODO: Add your control notification handler code here
	CString input;
	m_editInputNilai.GetWindowText(input); // ambil dari edit box

	input.Trim();
	input.MakeLower();

	// Ubah ke nilai numerik
	double value = 0.0;
	if (input.Find(_T("k")) >= 0) {
		input.Replace(_T("k"), _T(""));
		value = _tstof(input) * 1000;
	}
	else if (input.Find(_T("m")) >= 0) {
		input.Replace(_T("m"), _T(""));
		value = _tstof(input) * 1000000;
	}
	else {
		value = _tstof(input);
	}

	if (value < 1) {
		AfxMessageBox(_T("Masukkan nilai lebih dari 1 Ohm."));
		return;
	}

	// Hitung digit pertama dan kedua + multiplier
	int exponent = 0;
	while (value >= 100) {
		value /= 10;
		exponent++;
	}

	int intVal = (int)(value + 0.5); // dibulatkan
	if (intVal >= 100) {
		intVal /= 10;
		exponent++;
	}

	int digit1 = intVal / 10;
	int digit2 = intVal % 10;

	// Validasi batas
	if (digit1 > 9 || digit2 > 9 || exponent > 11) {
		AfxMessageBox(_T("Nilai tidak bisa dikonversi ke warna resistor."));
		return;
	}

	// Default toleransi: Gold (±5%)
	int defaultToleranceIndex = 6;

	// Set combo ke posisi
	m_comboBand1.SetCurSel(digit1);
	m_comboBand2.SetCurSel(digit2);
	m_comboBand3.SetCurSel(exponent);
	m_comboBand4.SetCurSel(defaultToleranceIndex);

	CString result;
	this->MessageBox(
		_T("Perhitungan resistor berhasil!"),
		_T("Sukses"),
		MB_OK | MB_ICONINFORMATION
	);

}
static double HitungResistorParalel(const std::vector<double>& resistorList)
{
	double total = 0.0;
	for (double r : resistorList)
	{
		if (r != 0.0)
			total += 1.0 / r;
	}
	if (total == 0.0)
		return 0.0;
	return 1.0 / total;
}
static double HitungResistorSeri(const std::vector<double>& resistorList)
{
	double total = 0.0;
	for (double r : resistorList)
	{
		total += r;
	}
	return total;
}
//serial fucntion
void CResistorCalculatorDlg::OnBnClickedButton3()
{
	// Contoh input dari user: 100,220,330
	CString inputText;
	GetDlgItemText(IDC_EDIT2, inputText); // Ambil dari textbox

	std::vector<double> resistors;
	CString token;
	int curPos = 0;

	while ((token = inputText.Tokenize(_T(","), curPos)) != _T(""))
	{
		resistors.push_back(_tstof(token)); // convert ke double
	}

	double hasilSeri = HitungResistorSeri(resistors);

	CString output;
	output.Format(_T("Total Seri: %.0f Ohm"), hasilSeri);
	serialResult.SetWindowText(output);
}

void CResistorCalculatorDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	CString inputText;
	GetDlgItemText(IDC_EDIT2, inputText);

	std::vector<double> resistors;
	CString token;
	int curPos = 0;

	while ((token = inputText.Tokenize(_T(","), curPos)) != _T(""))
	{
		resistors.push_back(_tstof(token));
	}

	double hasilParalel = HitungResistorParalel(resistors);

	CString output;
	output.Format(_T("Total Paralel: %.f Ohm"), hasilParalel);
	serialResult.SetWindowText(output);

}
