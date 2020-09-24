
// MFCApplication1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "UCDeviceScan.h"
#include "UCDeviceScanDlg.h"
#include "afxdialogex.h"

#ifndef GUID_CLASS_COMPORT
DEFINE_GUID(GUID_CLASS_COMPORT, 0x86e0d1e0L, 0x8089, 0x11d0, 0x9c, 0xe4, \
	0x08, 0x00, 0x3e, 0x30, 0x1f, 0x73);
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma comment(lib, "Setupapi.lib")

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


// CMFCApplication1Dlg �Ի���

CUCDeviceScanDlg::CUCDeviceScanDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_UC_DEVICE_SCAN_DLG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUCDeviceScanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_NTGRAPHCTRL1, m_NTGraph);
	DDX_Control(pDX, IDC_CHECK_TLS_LED, m_ctrlTLSLed);
	DDX_Control(pDX, IDC_COMBO_TLS_PORT, m_ctrlTLSComPort);
	DDX_Control(pDX, IDC_COMBO_PM_PORT, m_ctrlPMComPort);
	DDX_Control(pDX, IDC_COMBO_TLS_BAUND, m_ctrlTLSBaund);
	DDX_Control(pDX, IDC_COMBO_PM_BAUND, m_ctrlPMBaund);
	DDX_Control(pDX, IDC_COMBO1, m_ctrlPMUnitList);
	DDX_Control(pDX, IDC_RADIO_TLS_ON, m_ctrlRadioTLSON);
	DDX_Control(pDX, IDC_RADIO_TLS_OFF, m_ctrlRadioTLSOFF);
	DDX_Control(pDX, IDC_STATIC_TLS_FREQ_MIN, m_ctrlTLSFreqMin);
	DDX_Control(pDX, IDC_STATIC_TLS_FREQ_MAX, m_ctrlTLSFreqMax);
	DDX_Control(pDX, IDC_STATIC_TLS_WAV_MIN, m_ctrlTLSWavMin);
	DDX_Control(pDX, IDC_STATIC_TLS_WAV_MAX, m_ctrlTLSWavMax);
	DDX_Control(pDX, IDC_EDIT_FREQ, m_ctrlTLSSetFreq);
	DDX_Control(pDX, IDC_EDIT_TLS_WAV, m_ctrlTLSSetWav);
	DDX_Control(pDX, IDC_STATIC_TLS_POWER, m_ctrlTLSPower);
	DDX_Control(pDX, IDC_EDIT1, m_ctrlPMAvgTime);
	DDX_Control(pDX, IDC_EDIT_PM_REF, m_ctrlPMRefValue);
	DDX_Control(pDX, IDC_CHECK_PM_CONTINUE, m_ctrlCheckPMPowContinue);
	DDX_Control(pDX, IDC_EDIT_STARTWL, m_ctrlScanWLStart);
	DDX_Control(pDX, IDC_EDIT_STOPWL, m_ctrlScanWLStop);
	DDX_Control(pDX, IDC_EDIT_STEP, m_ctrlScanStep);
	DDX_Control(pDX, IDC_EDIT_SYNCH, m_ctrlScanSynch);
	DDX_Control(pDX, IDC_EDIT_DWELL, m_ctrlScanDwell);
	DDX_Control(pDX, IDC_EDIT_PM_WAV, m_ctrlPMWavValue);
	DDX_Control(pDX, IDC_STATIC_PM_POWER_SHOW, m_ctrlPMPowerShow);
	DDX_Control(pDX, IDC_EDIT_PMAVE, m_ctrlPMScanAve);
}

BEGIN_MESSAGE_MAP(CUCDeviceScanDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_OPENTLS, &CUCDeviceScanDlg::OnBnClickedBtnOpentls)
	ON_BN_CLICKED(IDOK, &CUCDeviceScanDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CUCDeviceScanDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_RADIO_TLS_ON, &CUCDeviceScanDlg::OnBnClickedRadioTlsOn)
	ON_BN_CLICKED(IDC_RADIO_TLS_OFF, &CUCDeviceScanDlg::OnBnClickedRadioTlsOff)
	ON_BN_CLICKED(IDC_BTN_TLS_FREQ_SET, &CUCDeviceScanDlg::OnBnClickedBtnTlsFreqSet)
	ON_BN_CLICKED(IDC_BTN_TLS_WAV_SET, &CUCDeviceScanDlg::OnBnClickedBtnTlsWavSet)
	ON_BN_CLICKED(IDC_BTN_TLS_FREQ_MAX_SET, &CUCDeviceScanDlg::OnBnClickedBtnTlsFreqMaxSet)
	ON_BN_CLICKED(IDC_BTN_TLS_FREQ_MIN_SET, &CUCDeviceScanDlg::OnBnClickedBtnTlsFreqMinSet)
	ON_BN_CLICKED(IDC_BTN_TLS_WAV_SET_MAX, &CUCDeviceScanDlg::OnBnClickedBtnTlsWavSetMax)
	ON_BN_CLICKED(IDC_BTN_TLS_WAV_SET_MIN, &CUCDeviceScanDlg::OnBnClickedBtnTlsWavSetMin)
	ON_BN_CLICKED(IDC_BTN_OPENPM, &CUCDeviceScanDlg::OnBnClickedBtnOpenpm)
	ON_BN_CLICKED(IDC_BTN_PM_MINMAX, &CUCDeviceScanDlg::OnBnClickedBtnPmMinmax)
	ON_BN_CLICKED(IDC_BTN_RESET_PM_MINMAX, &CUCDeviceScanDlg::OnBnClickedBtnResetPmMinmax)
	ON_BN_CLICKED(IDC_BTN_PM_AVG_SET, &CUCDeviceScanDlg::OnBnClickedBtnPmAvgSet)
	ON_BN_CLICKED(IDC_BTN_PM_WAV_SET, &CUCDeviceScanDlg::OnBnClickedBtnPmWavSet)
	ON_BN_CLICKED(IDC_BTN_PM_UNIT_SET, &CUCDeviceScanDlg::OnBnClickedBtnPmUnitSet)
	ON_BN_CLICKED(IDC_BTN_PM_READ, &CUCDeviceScanDlg::OnBnClickedBtnPmRead)
	ON_BN_CLICKED(IDC_BTN_ADJUST_ZERO, &CUCDeviceScanDlg::OnBnClickedBtnAdjustZero)
	ON_BN_CLICKED(IDC_BTN_PM__DISP_REF, &CUCDeviceScanDlg::OnBnClickedBtnPm)
	ON_BN_CLICKED(IDC_BTN_PM_REF_SET, &CUCDeviceScanDlg::OnBnClickedBtnPmRefSet)
	ON_BN_CLICKED(IDC_BUTTON_SCAN_REF, &CUCDeviceScanDlg::OnBnClickedButtonScanRef)
	ON_BN_CLICKED(IDC_BUTTON_SCAN, &CUCDeviceScanDlg::OnBnClickedButtonScan)
	ON_BN_CLICKED(IDC_BUTTON_ABORT, &CUCDeviceScanDlg::OnBnClickedButtonAbort)
	ON_BN_CLICKED(IDC_CHECK_PM_CONTINUE, &CUCDeviceScanDlg::OnBnClickedCheckPmContinue)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CMFCApplication1Dlg ��Ϣ�������

BOOL CUCDeviceScanDlg::OnInitDialog()
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
	//m_ctrlTLSLed.SetTextBackground(GRAY_LIGHT);
	SetTLSStateLed(0);
	GetSysComPort();
	m_ctrlTLSComPort.SetCurSel(0);
	m_ctrlTLSBaund.SetCurSel(1);
	m_ctrlPMComPort.SetCurSel(1);
	m_ctrlPMBaund.SetCurSel(1);
	m_ctrlPMUnitList.SetCurSel(0);
	m_ctrlRadioTLSOFF.SetCheck(TRUE);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CUCDeviceScanDlg::SetTLSStateLed(int nType)
{
	if (nType == 0)
	{
		m_ctrlTLSLed.SetLedStatesNumber(LIGHT_STATE_SENTINEL);
		m_ctrlTLSLed.SetLedState(GRAY_LIGHT);
		m_ctrlTLSLed.SetIcon(GRAY_LIGHT, IDI_ICON_NONE, 16, 16);
	}
	else if (nType == 1)
	{
		m_ctrlTLSLed.SetLedStatesNumber(LIGHT_STATE_SENTINEL);
		m_ctrlTLSLed.SetLedState(GREEN_LIGHT);
		m_ctrlTLSLed.SetIcon(GREEN_LIGHT, IDI_ICON_GREEN, 16, 16);
	}
}
void CUCDeviceScanDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CUCDeviceScanDlg::OnPaint()
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
HCURSOR CUCDeviceScanDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CUCDeviceScanDlg::GetSysComPort()
{
	GUID *guidDev = (GUID*)&GUID_CLASS_COMPORT;
	HDEVINFO hDevInfo = SetupDiGetClassDevs(guidDev, NULL, NULL, DIGCF_PRESENT | DIGCF_DEVICEINTERFACE);
	//HANDLE hCom;
	m_ctrlTLSComPort.Clear();
	m_ctrlPMComPort.Clear();
	if (hDevInfo)
	{
		int iy = 0;
		SP_DEVINFO_DATA SpDevInfo = { sizeof(SP_DEVINFO_DATA) };
		//bOk = SetupDiEnumDeviceInterfaces(hDevInfo,
		//	NULL, guidDev, ii, &ifcData);
		for (DWORD iDevIndex = 0; SetupDiEnumDeviceInfo(hDevInfo, iDevIndex, &SpDevInfo); iDevIndex++)
		{
			TCHAR szName[512] = { 0 };
			if (SetupDiGetDeviceRegistryProperty(hDevInfo, &SpDevInfo, SPDRP_FRIENDLYNAME,
				NULL, (PBYTE)szName, sizeof(szName), NULL))
			{
				_tprintf(_T("%s\n"), szName);
				CString com, str, strComOpen;
				str.Format(_T("%s"), szName);//��ȡ���ڵ�����COM2

				int posBeg = str.ReverseFind('(');
				int posEnd = str.ReverseFind(')');
				com = str.Mid(posBeg + 1, posEnd - posBeg - 1);//��ȡ���ڵ�����COM2
				m_ctrlTLSComPort.AddString(com);
				m_ctrlPMComPort.AddString(com);
				//strComOpen = _T("\\\\.\\") + com;
				//hCom = CreateFile(strComOpen, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, 0);//������ز�Ϊ����˴��ڿ���
				//if (INVALID_HANDLE_VALUE == hCom || ComYanzheng == com)
				//{
				//	DWORD error = ::GetLastError();//ȡ�ô�����Ϣ 
				//}
				//else
				//{
				//	ComYanzheng = com;
				//	ComY[iy] = str;
				//	iy++;
				//}
				//CloseHandle(hCom);

			}
		}
		SetupDiDestroyDeviceInfoList(hDevInfo);
	}
}

BOOL CUCDeviceScanDlg::InitialTLSUI()
{
	CString strMsg;
	CString strTemp;
	//��ȡ����������
	double dbMaxPower;
	if (m_GM82009TLS.ReadSourcePower(&dbMaxPower))
	{
		strMsg = m_GM82009TLS.GetErrorMsg();
		MessageBox(strMsg, "������ʾ");
		return FALSE;
	}
	strTemp.Format("Power: %.4f dBm", dbMaxPower);
	m_ctrlTLSPower.SetWindowText(strTemp);
	//��ȡ��ǰ��Ƶ�ʺͲ���
	double dbCurFreq, dbCurWave;
	if (m_GM82009TLS.ReadSourceFreq(&dbCurFreq))
	{
		strMsg = m_GM82009TLS.GetErrorMsg();
		MessageBox(strMsg, "������ʾ");
		return FALSE;
	}
	strTemp.Format("%.4f", dbCurFreq);
	m_ctrlTLSSetFreq.SetWindowText(strTemp);

	if (m_GM82009TLS.ReadSourceWavelength(&dbCurWave))
	{
		strMsg = m_GM82009TLS.GetErrorMsg();
		MessageBox(strMsg, "������ʾ");
		return FALSE;
	}
	strTemp.Format("%.4f", dbCurWave);
	m_ctrlTLSSetWav.SetWindowText(strTemp);
	//��ȡ��ǰ���Ƶ�ʺ�ǰ��СƵ��
	double dbMaxFreq,dbMinFreq;
	if (m_GM82009TLS.ReadSourceFreqMinMax(&dbMinFreq, &dbMaxFreq))
	{
		strMsg = m_GM82009TLS.GetErrorMsg();
		MessageBox(strMsg, "������ʾ");
		return FALSE; 
	}
	strTemp.Format("Min: %.4f", dbMinFreq);
	m_ctrlTLSFreqMin.SetWindowText(strTemp);
	strTemp.Format("Max': %.4f", dbMaxFreq);
	m_ctrlTLSFreqMax.SetWindowText(strTemp);

	//��ȡ��ǰ��󲨳�����С����
	double dbMaxWav, dbMinWav;
	if (m_GM82009TLS.ReadSourceWavelengthMinMax(&dbMinWav, &dbMaxWav))
	{
		strMsg = m_GM82009TLS.GetErrorMsg();
		MessageBox(strMsg, "������ʾ");
		return FALSE;
	}
	strTemp.Format("Min: %.4f", dbMinWav);
	m_ctrlTLSWavMin.SetWindowText(strTemp);
	strTemp.Format("Max': %.4f", dbMaxWav);
	m_ctrlTLSWavMax.SetWindowText(strTemp);
	
	return TRUE;
}

void CUCDeviceScanDlg::OnBnClickedBtnOpentls()
{
	// TODO: Add your control notification handler code here
	CString strCaption;
	CString strComPort, strComOpen;
	CString strMsg;
	CString strTemp;
	DWORD dwBaund;
	m_bTLSOpened = FALSE;
	GetDlgItem(IDC_BTN_OPENTLS)->GetWindowText(strCaption);

	if (strCaption == "��")
	{
		int nPortCursel = m_ctrlTLSComPort.GetCurSel();
		if (nPortCursel != -1)
		{
			m_ctrlTLSComPort.GetLBText(nPortCursel, strComPort);
		}
		int nBaundCursel = m_ctrlTLSBaund.GetCurSel();
		if (nBaundCursel != -1)
		{
			m_ctrlTLSBaund.GetLBText(nBaundCursel, strTemp);
			dwBaund = atoi(strTemp);
		}

		strComOpen = _T("\\\\.\\") + strComPort;
		if(!m_GM82009TLS.OpenPort(strComOpen.GetBuffer(0), dwBaund))
		{
			strMsg.Format("�򿪼���������%s���ڴ���",strComPort);
			MessageBox(strMsg, "������ʾ");
		}
		GetDlgItem(IDC_BTN_OPENTLS)->SetWindowText("�ر�");
		m_bTLSOpened = TRUE;

		//���ݴ򿪶�ȡ�������Ĳ�������ʾ����Ӧ������
	}
	else
	{
		m_GM82009TLS.ClosePort();
		GetDlgItem(IDC_BTN_OPENTLS)->SetWindowText("��");
		m_bTLSOpened = FALSE;
	}
}


void CUCDeviceScanDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void CUCDeviceScanDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void CUCDeviceScanDlg::OnBnClickedRadioTlsOn()
{
	// TODO: Add your control notification handler code here
	CString strMsg;
	if (!m_bTLSOpened)
	{
		MessageBox("���ȴ򿪼���������", "��ʾ");
		return;
	}
	if (!m_GM82009TLS.SetSourceState(1))
	{
		strMsg = m_GM82009TLS.GetErrorMsg();
		MessageBox(strMsg, "������ʾ");
		return;
	}
	SetTLSStateLed(1);
}


void CUCDeviceScanDlg::OnBnClickedRadioTlsOff()
{
	// TODO: Add your control notification handler code here
	CString strMsg;
	if (!m_bTLSOpened)
	{
		MessageBox("���ȴ򿪼���������", "��ʾ");
		return;
	}
	if (!m_GM82009TLS.SetSourceState(0))
	{
		strMsg = m_GM82009TLS.GetErrorMsg();
		MessageBox(strMsg, "������ʾ");
		return;
	}
	SetTLSStateLed(1);
	SetTLSStateLed(0);
}


void CUCDeviceScanDlg::OnBnClickedBtnTlsFreqSet()
{
	// TODO: Add your control notification handler code here
	CString strValue;
	CString strMsg;
	UpdateData();
	if (!m_bTLSOpened)
	{
		MessageBox("���ȴ򿪼���������", "��ʾ");
		return;
	}
	m_ctrlTLSSetFreq.GetWindowText(strValue);
	if (strValue.IsEmpty())
	{
		MessageBox("��������ȷ��Ƶ��ֵ", "��ʾ");
		return;
	}
	double dbFreq = atof(strValue);

	if (dbFreq > 197000 || dbFreq < 191000)
	{
		MessageBox("��д��Ƶ��ֵ�����˼�������Χ,����ȷ����", "��ʾ");
		return;
	}

	if (!m_GM82009TLS.SetSourceFreq(dbFreq))
	{
		strMsg = m_GM82009TLS.GetErrorMsg();
		MessageBox(strMsg, "������ʾ");
		return;
	}
}


void CUCDeviceScanDlg::OnBnClickedBtnTlsWavSet()
{
	// TODO: Add your control notification handler code here
	CString strValue;
	CString strMsg;
	UpdateData();
	if (!m_bTLSOpened)
	{
		MessageBox("���ȴ򿪼���������", "��ʾ");
		return;
	}
	m_ctrlTLSSetFreq.GetWindowText(strValue);
	if (strValue.IsEmpty())
	{
		MessageBox("��������ȷ�Ĳ���", "��ʾ");
		return;
	}
	double dbWav = atof(strValue);

	if (dbWav > 1575 || dbWav < 1520)
	{
		MessageBox("��д�Ĳ���ֵ�����˼�������Χ,����ȷ����", "��ʾ");
		return;
	}

	if (!m_GM82009TLS.SetSourceWavelength(dbWav))
	{
		strMsg = m_GM82009TLS.GetErrorMsg();
		MessageBox(strMsg, "������ʾ");
		return;
	}
}


void CUCDeviceScanDlg::OnBnClickedBtnTlsFreqMaxSet()
{
	// TODO: Add your control notification handler code here
	CString strValue;
	CString strMsg;
	UpdateData();
	if (!m_bTLSOpened)
	{
		MessageBox("���ȴ򿪼���������", "��ʾ");
		return;
	}
	if (!m_GM82009TLS.SetSourceCurFreqMax())
	{
		strMsg = m_GM82009TLS.GetErrorMsg();
		MessageBox(strMsg, "������ʾ");
		return;
	}
}


void CUCDeviceScanDlg::OnBnClickedBtnTlsFreqMinSet()
{
	// TODO: Add your control notification handler code here
	CString strValue;
	CString strMsg;
	UpdateData();
	if (!m_bTLSOpened)
	{
		MessageBox("���ȴ򿪼���������", "��ʾ");
		return;
	}
	if (!m_GM82009TLS.SetSourceCurFreqMin())
	{
		strMsg = m_GM82009TLS.GetErrorMsg();
		MessageBox(strMsg, "������ʾ");
		return;
	}
}


void CUCDeviceScanDlg::OnBnClickedBtnTlsWavSetMax()
{
	// TODO: Add your control notification handler code here
	CString strValue;
	CString strMsg;
	UpdateData();
	if (!m_bTLSOpened)
	{
		MessageBox("���ȴ򿪼���������", "��ʾ");
		return;
	}
	if (!m_GM82009TLS.SetSourceWavelengthMax())
	{
		strMsg = m_GM82009TLS.GetErrorMsg();
		MessageBox(strMsg, "������ʾ");
		return;
	}
}


void CUCDeviceScanDlg::OnBnClickedBtnTlsWavSetMin()
{
	// TODO: Add your control notification handler code here
	CString strValue;
	CString strMsg;
	UpdateData();
	if (!m_bTLSOpened)
	{
		MessageBox("���ȴ򿪼���������", "��ʾ");
		return;
	}
	if (!m_GM82009TLS.SetSourceWavelengthMin())
	{
		strMsg = m_GM82009TLS.GetErrorMsg();
		MessageBox(strMsg, "������ʾ");
		return;
	}
}


void CUCDeviceScanDlg::OnBnClickedBtnOpenpm()
{
	// TODO: Add your control notification handler code here
	CString strCaption;
	CString strComPort, strComOpen;
	CString strMsg;
	CString strTemp;
	DWORD dwBaund;
	m_bPMOpened = FALSE;
	GetDlgItem(IDC_BTN_OPENPM)->GetWindowText(strCaption);

	if (strCaption == "��")
	{
		int nPortCursel = m_ctrlPMComPort.GetCurSel();
		if (nPortCursel != -1)
		{
			m_ctrlPMComPort.GetLBText(nPortCursel, strComPort);
		}
		int nBaundCursel = m_ctrlPMBaund.GetCurSel();
		if (nBaundCursel != -1)
		{
			m_ctrlPMBaund.GetLBText(nBaundCursel, strTemp);
			dwBaund = atoi(strTemp);
		}

		strComOpen = _T("\\\\.\\") + strComPort;
		if (!m_GM83011PM.OpenPort(strComOpen.GetBuffer(0), dwBaund))
		{
			strMsg.Format("�򿪼���������%s���ڴ���", strComPort);
			MessageBox(strMsg, "������ʾ");
		}
		GetDlgItem(IDC_BTN_OPENPM)->SetWindowText("�ر�");
		m_bPMOpened = TRUE;

		//���ݴ򿪶�ȡ�������Ĳ�������ʾ����Ӧ������
	}
	else
	{
		m_GM83011PM.ClosePort();
		GetDlgItem(IDC_BTN_OPENPM)->SetWindowText("��");
		m_bPMOpened = FALSE;
	}
}


void CUCDeviceScanDlg::OnBnClickedBtnPmMinmax()
{
	// TODO: Add your control notification handler code here
	if (!m_bPMOpened)
	{
		MessageBox("���ȴ򿪹��ʼƴ���", "��ʾ");
		return;
	}
	
	//if(m_GM83011PM.setpmmo)
}


void CUCDeviceScanDlg::OnBnClickedBtnResetPmMinmax()
{
	// TODO: Add your control notification handler code here
}


void CUCDeviceScanDlg::OnBnClickedBtnPmAvgSet()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CString strTemp;
	double dbAvgTime;
	if (!m_bPMOpened)
	{
		MessageBox("���ȴ򿪹��ʼƴ���", "��ʾ");
		return;
	}
	m_ctrlPMAvgTime.GetWindowText(strTemp);
	dbAvgTime = atof(strTemp);

	if (dbAvgTime > 999 && dbAvgTime < 0.01)
	{
		strTemp.Format("ƽ������ʱ��ֻ����0.01ms-999ms֮��");
		MessageBox(strTemp, "������ʾ");
		return;
	}

	if (!m_GM83011PM.SetPMAve(dbAvgTime))
	{
		strTemp = m_GM83011PM.GetErrorMsg();
		MessageBox(strTemp, "������ʾ");
	}
}


void CUCDeviceScanDlg::OnBnClickedBtnPmWavSet()
{
	// TODO: Add your control notification handler code here

	UpdateData();
	CString strTemp;
	double dbPMWav;
	if (!m_bPMOpened)
	{
		MessageBox("���ȴ򿪹��ʼƴ���", "��ʾ");
		return;
	}
	m_ctrlPMWavValue.GetWindowText(strTemp);
	dbPMWav = atof(strTemp);

	if (dbPMWav > 1700 && dbPMWav < 1200)
	{
		strTemp.Format("���ʼƲ������ó�����Χ������ȷ���벨��ֵ");
		MessageBox(strTemp, "������ʾ");
		return;
	}

	if (!m_GM83011PM.SetPMWavelength(dbPMWav))
	{
		strTemp = m_GM83011PM.GetErrorMsg();
		MessageBox(strTemp, "������ʾ");
	}
}


void CUCDeviceScanDlg::OnBnClickedBtnPmUnitSet()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CString strTemp;
	double dbPMWav;
	if (!m_bPMOpened)
	{
		MessageBox("���ȴ򿪹��ʼƴ���", "��ʾ");
		return;
	}
	int nCursel = m_ctrlPMUnitList.GetCurSel();
	if (nCursel == -1)
	{
		strTemp.Format("����ȷѡ���ʼƵĵ�λ����");
		MessageBox(strTemp, "������ʾ");
		return;
	}

	if (!m_GM83011PM.SetPMUinit(nCursel))
	{
		strTemp = m_GM83011PM.GetErrorMsg();
		MessageBox(strTemp, "������ʾ");
	}
}


void CUCDeviceScanDlg::OnBnClickedBtnPmRead()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CString strTemp;
	double dbReadPower;
	if (!m_bPMOpened)
	{
		MessageBox("���ȴ򿪹��ʼƴ���", "��ʾ");
		return;
	}

	if (!m_GM83011PM.ReadPower(&dbReadPower))
	{
		strTemp = m_GM83011PM.GetErrorMsg();
		MessageBox(strTemp, "������ʾ");
		return;
	}
	strTemp.Format("%.4f dBm", dbReadPower);
	m_ctrlPMPowerShow.SetWindowText(strTemp);
	UpdateData(FALSE);
}


void CUCDeviceScanDlg::OnBnClickedBtnAdjustZero()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CString strTemp;
	if (!m_bPMOpened)
	{
		MessageBox("���ȴ򿪹��ʼƴ���", "��ʾ");
		return;
	}

	if (!m_GM83011PM.PMZero())
	{
		strTemp = m_GM83011PM.GetErrorMsg();
		MessageBox(strTemp, "������ʾ");
	}
}


void CUCDeviceScanDlg::OnBnClickedBtnPm()
{
	// TODO: Add your control notification handler code here
	CString strTemp;
	double dbRefValue;
	UpdateData();
	if (!m_bPMOpened)
	{
		MessageBox("���ȴ򿪹��ʼƴ���", "��ʾ");
		return;
	}

	if (!m_GM83011PM.ReadPMRef(&dbRefValue))
	{
		strTemp = m_GM83011PM.GetErrorMsg();
		MessageBox(strTemp, "������ʾ");
	}
	strTemp.Format("%.4f", dbRefValue);
	m_ctrlPMRefValue.SetWindowText(strTemp);
}


void CUCDeviceScanDlg::OnBnClickedBtnPmRefSet()
{
	// TODO: Add your control notification handler code here

	UpdateData();
	CString strTemp;
	if (!m_bPMOpened)
	{
		MessageBox("���ȴ򿪹��ʼƴ���", "��ʾ");
		return;
	}

	if (!m_GM83011PM.PMRef())
	{
		strTemp = m_GM83011PM.GetErrorMsg();
		MessageBox(strTemp, "������ʾ");
	}
}
/////////////////////////////////////////////
//����˵����
//    PM׼��ɨ���ʼ��
//Add by wanxin
//Time:20200921
////////////////////////////////////////////
BOOL CUCDeviceScanDlg::PreparePMScan()
{
	//���ù��ʼƴ���ģʽ��������trigger����
	CString strTemp;
	if (!m_GM83011PM.SetPMScanMode(1))
	{
		strTemp = m_GM83011PM.GetErrorMsg();
		MessageBox(strTemp, "������ʾ");
		return FALSE;
	}

	if (!m_GM83011PM.SetPMScanStart())
	{
		strTemp = m_GM83011PM.GetErrorMsg();
		MessageBox(strTemp, "������ʾ");
		return FALSE;
	}

	return TRUE;
}

/////////////////////////////////////////////
//����˵����
//   TLS׼��ɨ���ʼ��
//Add by wanxin
//Time:20200921
/////////////////////////////////////////////
BOOL CUCDeviceScanDlg::PrepareTLSScan()
{
	CString strTemp;
	double dbMaxWL;
	double dbMinWL;
	UpdateData();
	if (!m_GM82009TLS.ReadSourceWavelengthMinMax(&dbMaxWL, &dbMinWL))
	{
		strTemp = m_GM82009TLS.GetErrorMsg();
		MessageBox(strTemp, "������ʾ");
		return FALSE;
	}

	m_ctrlScanWLStart.GetWindowTextA(strTemp); 
	m_dbStartWL = atof(strTemp);
	if (m_dbStartWL < dbMinWL)
	{
		strTemp.Format("����ɨ����ʼ����%.3fС�ڼ�������С����%.3f", m_dbStartWL, dbMinWL);
		MessageBox(strTemp, "������ʾ");
		return FALSE;
	}
	if (!m_GM82009TLS.SetSourceSweepStart(0, m_dbStartWL))
	{
		strTemp = m_GM82009TLS.GetErrorMsg();
		MessageBox(strTemp, "������ʾ");
		return FALSE;
	}

	m_ctrlScanWLStop.GetWindowTextA(strTemp);
	m_dbStopWL = atof(strTemp);
	if (m_dbStopWL > dbMaxWL)
	{
		strTemp.Format("����ɨ��ֹͣ����%.3f���ڼ�������󲨳�%.3f", m_dbStopWL, dbMaxWL);
		MessageBox(strTemp, "������ʾ");
		return FALSE;
	}

	if (!m_GM82009TLS.SetSourceSweepStop(0, m_dbStopWL))
	{
		strTemp = m_GM82009TLS.GetErrorMsg();
		MessageBox(strTemp, "������ʾ");
		return FALSE;
	}

	m_ctrlScanStep.GetWindowTextA(strTemp);
	m_dbStepWL = atof(strTemp);
	if (m_dbStepWL < 0.01)
	{
		strTemp.Format("ɨ�貽����С���ò���С��0.01nm");
		MessageBox(strTemp, "������ʾ");
		return FALSE;
	}

	if (!m_GM82009TLS.SetSourceSweepStep(0, m_dbStepWL))
	{
		strTemp = m_GM82009TLS.GetErrorMsg();
		MessageBox(strTemp, "������ʾ");
		return FALSE;
	}

	m_ctrlScanSynch.GetWindowTextA(strTemp);
	m_dbSynchdelay = atof(strTemp);
	if (m_dbSynchdelay < 0.0001 || m_dbSynchdelay > 6)
	{
		strTemp.Format("ɨ����������֮����ʱ��ֻ������0.0001-6��֮��");
		MessageBox(strTemp, "������ʾ");
		return FALSE;
	}
	if (!m_GM82009TLS.SetSourceSweepSynchDelay(m_dbSynchdelay))
	{
		strTemp = m_GM82009TLS.GetErrorMsg();
		MessageBox(strTemp, "������ʾ");
		return FALSE;
	}

	m_ctrlScanDwell.GetWindowTextA(strTemp);
	m_dbDwell = atof(strTemp);
	if (m_dbDwell < 0.0001 || m_dbDwell >6)
	{
		strTemp.Format("Dwellֵ����ֻ������0.0001�� - 6��֮��");
		MessageBox(strTemp, "������ʾ");
		return FALSE;
	}

	if (!m_GM82009TLS.SetSourceSweepDwell(m_dbDwell))
	{
		strTemp = m_GM82009TLS.GetErrorMsg();
		MessageBox(strTemp, "������ʾ");
		return FALSE;
	}

	if (m_GM82009TLS.SetSourceSweepMode(1))
	{
		strTemp = m_GM82009TLS.GetErrorMsg();
		MessageBox(strTemp, "������ʾ");
		return FALSE;
	}

	if (!m_GM82009TLS.SetSourceSweepPulseLevel(1.0))
	{
		strTemp = m_GM82009TLS.GetErrorMsg();
		MessageBox(strTemp, "������ʾ");
		return FALSE;
	}

	return TRUE;
}
/////////////////////////////////////////////
//����˵����
//   ִ��ɨ�躯��
//Add by wanxin
//Time:20200921
/////////////////////////////////////////////
BOOL CUCDeviceScanDlg::ExceuteScan(double *pdbWavArry, double *pdbPMArry,int nChIndex)
{



}


void CUCDeviceScanDlg::OnBnClickedButtonScanRef()
{
	// TODO: Add your control notification handler code here


}


void CUCDeviceScanDlg::OnBnClickedButtonScan()
{
	// TODO: Add your control notification handler code here


}


void CUCDeviceScanDlg::OnBnClickedButtonAbort()
{
	// TODO: Add your control notification handler code here
}


void CUCDeviceScanDlg::OnBnClickedCheckPmContinue()
{
	// TODO: Add your control notification handler code here
	if (!m_bPMOpened)
	{
		MessageBox("���ȴ򿪹��ʼƴ���", "��ʾ");
		return;
	}
	if (m_ctrlCheckPMPowContinue.GetCheck() == TRUE)
	{
		SetTimer(1, 500, NULL);
	}
	else
	{
		KillTimer(1);
	}

}


void CUCDeviceScanDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if (nIDEvent == 1)
	{
		UpdateData();
		CString strTemp;
		double dbReadPower;
		if (!m_GM83011PM.ReadPower(&dbReadPower))
		{
			strTemp = m_GM83011PM.GetErrorMsg();
			MessageBox(strTemp, "������ʾ");
			return;
		}
		strTemp.Format("%.4f dBm", dbReadPower);
		m_ctrlPMPowerShow.SetWindowText(strTemp);
	}
	CDialogEx::OnTimer(nIDEvent);
}
