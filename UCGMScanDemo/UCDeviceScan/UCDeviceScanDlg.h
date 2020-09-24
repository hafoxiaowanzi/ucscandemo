
// MFCApplication1Dlg.h : 头文件
//

#pragma once
#include "ntgraphctrl.h"
#include "afxwin.h"
#include "LedButton.h"
#include <objbase.h>
#include <initguid.h>
#include <setupapi.h>
#include "GM82009.h"
#include "GCM83011Driver.h"


// CMFCApplication1Dlg 对话框
class CUCDeviceScanDlg : public CDialogEx
{
// 构造
public:
	CUCDeviceScanDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UC_DEVICE_SCAN_DLG};
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
	CNtgraphctrl1 m_NTGraph;
	// TLS Led
	CLedButton m_ctrlTLSLed;
	afx_msg void OnBnClickedBtnOpentls();
	void GetSysComPort();
	CComboBox m_ctrlTLSComPort;
	CComboBox m_ctrlPMComPort;
	CComboBox m_ctrlTLSBaund;
	CComboBox m_ctrlPMBaund;
	CComboBox m_ctrlPMUnitList;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedRadioTlsOn();
	afx_msg void OnBnClickedRadioTlsOff();
	void SetTLSStateLed(int nType);


	CGM82009Driver m_GM82009TLS;
	GCM83011Driver m_GM83011PM;
	BOOL m_bTLSOpened;
	BOOL m_bPMOpened;
	CButton m_ctrlRadioTLSON;
	CButton m_ctrlRadioTLSOFF;
	afx_msg void OnBnClickedBtnTlsFreqSet();
	afx_msg void OnBnClickedBtnTlsWavSet();
	afx_msg void OnBnClickedBtnTlsFreqMaxSet();
	afx_msg void OnBnClickedBtnTlsFreqMinSet();
	afx_msg void OnBnClickedBtnTlsWavSetMax();
	afx_msg void OnBnClickedBtnTlsWavSetMin();
	CStatic m_ctrlTLSFreqMin;
	CStatic m_ctrlTLSFreqMax;
	CStatic m_ctrlTLSWavMin;
	CStatic m_ctrlTLSWavMax;
	CEdit m_ctrlTLSSetFreq;
	CEdit m_ctrlTLSSetWav;
	CStatic m_ctrlTLSPower;

	BOOL InitialTLSUI();
	afx_msg void OnBnClickedBtnOpenpm();
	afx_msg void OnBnClickedBtnPmMinmax();
	afx_msg void OnBnClickedBtnResetPmMinmax();
	afx_msg void OnBnClickedBtnPmAvgSet();
	afx_msg void OnBnClickedBtnPmWavSet();
	afx_msg void OnBnClickedBtnPmUnitSet();
	afx_msg void OnBnClickedBtnPmRead();
	CEdit m_ctrlPMAvgTime;
	afx_msg void OnBnClickedBtnAdjustZero();
	CEdit m_ctrlPMRefValue;
	afx_msg void OnBnClickedBtnPm();
	afx_msg void OnBnClickedBtnPmRefSet();
	CButton m_ctrlCheckPMPowContinue;
	CEdit m_ctrlScanWLStart;
	CEdit m_ctrlScanWLStop;
	CEdit m_ctrlScanStep;
	afx_msg void OnBnClickedButtonScanRef();
	afx_msg void OnBnClickedButtonScan();
	afx_msg void OnBnClickedButtonAbort();
	CEdit m_ctrlScanSynch;
	CEdit m_ctrlScanDwell;
	CEdit m_ctrlPMWavValue;
	CStatic m_ctrlPMPowerShow;
	afx_msg void OnBnClickedCheckPmContinue();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	BOOL PreparePMScan();
	BOOL PrepareTLSScan();
	BOOL ExceuteScan(double *pdbWavArry, double *pdbPMArry, int nChIndex);


	double m_dbStartWL;
	double m_dbStopWL;
	double m_dbStepWL;
	double m_dbSynchdelay;
	double m_dbDwell;
	CEdit m_ctrlPMScanAve;
};
