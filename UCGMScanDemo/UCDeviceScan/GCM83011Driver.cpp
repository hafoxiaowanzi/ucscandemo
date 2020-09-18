#include "stdafx.h"
#include "GCM83011Driver.h"


GCM83011Driver::GCM83011Driver()
{
}

GCM83011Driver::~GCM83011Driver()
{

}

CString GCM83011Driver::GetErrorMsg()
{
	return m_strError;
}

BOOL GCM83011Driver::GetDeviceInfo(char *pstrDevice, int nLength)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ASSERT(pstrDevice);

	if (nLength > 1024)
	{
		m_strError.Format("内存定义长度大于1024字节");
		return FALSE;
	}
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "*IDN?\n");
	DWORD dwlength = strlen(szSend);
	if(!WriteBuffer(szSend, dwlength))
	{ 
		m_strError.Format("发送指令%s存在错误", szSend);
		return FALSE;
	}
	Sleep(20);
	ZeroMemory(szBuffer, sizeof(char) * 1024);
	if (!ReadBuffer(szBuffer, 1024))
	{
		m_strError.Format("读取指令%s存在错误", szSend);
		return FALSE;
	}
	dwlength = strlen(szBuffer);
	memcpy(pstrDevice, szBuffer, dwlength);

	return TRUE;
}
BOOL GCM83011Driver::ReadPower(double *pdbPower)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "METER:POW1?\n");
	DWORD dwlength = strlen(szSend);
	if (!WriteBuffer(szSend, dwlength))
	{
		m_strError.Format("发送指令%s存在错误", szSend);
		return FALSE;
	}
	Sleep(20);
	ZeroMemory(szBuffer, sizeof(char) * 1024);
	if (!ReadBuffer(szBuffer, 1024))
	{
		m_strError.Format("读取指令%s存在错误", szSend);
		return FALSE;
	}
	*pdbPower = atof(szBuffer);
	return TRUE;
}
BOOL GCM83011Driver::PMZero()
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "METER:ZERO?\n");
	DWORD dwlength = strlen(szSend);
	if (!WriteBuffer(szSend, dwlength))
	{
		m_strError.Format("发送指令%s存在错误", szSend);
		return FALSE;
	}
	Sleep(20);
	ZeroMemory(szBuffer, sizeof(char) * 1024);
	if (!ReadBuffer(szBuffer, 1024))
	{
		m_strError.Format("读取指令%s存在错误", szSend);
		return FALSE;
	}
	if (strcmp(szBuffer, "Zero OK!>") == -1)
	{
		m_strError.Format("读取指令%s存在错误:%s", szSend, szBuffer);
		return FALSE;
	}
	return TRUE;
}
BOOL GCM83011Driver::ReadPMRef(double*pdbRef)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "METER:POW1:REF?\n");
	DWORD dwlength = strlen(szSend);
	if (!WriteBuffer(szSend, dwlength))
	{
		m_strError.Format("发送指令%s存在错误", szSend);
		return FALSE;
	}
	Sleep(20);
	ZeroMemory(szBuffer, sizeof(char) * 1024);
	if (!ReadBuffer(szBuffer, 1024))
	{
		m_strError.Format("读取指令%s存在错误", szSend);
		return FALSE;
	}
	*pdbRef = atof(szBuffer);

	return TRUE;

}
BOOL GCM83011Driver::PMRef()
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "METER:POW1:REF\n");
	DWORD dwlength = strlen(szSend);
	if (!WriteBuffer(szSend, dwlength))
	{
		m_strError.Format("发送指令%s存在错误", szSend);
		return FALSE;
	}
	Sleep(20);
	ZeroMemory(szBuffer, sizeof(char) * 1024);
	if (!ReadBuffer(szBuffer, 1024))
	{
		m_strError.Format("读取指令%s存在错误", szSend);
		return FALSE;
	}
	if (strcmp(szBuffer, ">") == -1)
	{
		m_strError.Format("读取指令%s存在错误:%s", szSend, szBuffer);
		return FALSE;
	}
	return TRUE;
}
BOOL GCM83011Driver::ReadPMWavelength(double *pdbWav)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "METER:POW1:WAVE?\n");
	DWORD dwlength = strlen(szSend);
	if (!WriteBuffer(szSend, dwlength))
	{
		m_strError.Format("发送指令%s存在错误", szSend);
		return FALSE;
	}
	Sleep(20);
	ZeroMemory(szBuffer, sizeof(char) * 1024);
	if (!ReadBuffer(szBuffer, 1024))
	{
		m_strError.Format("读取指令%s存在错误", szSend);
		return FALSE;
	}
	*pdbWav = atof(szBuffer);

	return TRUE;
}
BOOL GCM83011Driver::SetPMWavelength(double dbWav)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "METER:POW1:WAVE %.3fnm\n", dbWav);
	DWORD dwlength = strlen(szSend);
	if (!WriteBuffer(szSend, dwlength))
	{
		m_strError.Format("发送指令%s存在错误", szSend);
		return FALSE;
	}
	Sleep(20);
	ZeroMemory(szBuffer, sizeof(char) * 1024);
	if (!ReadBuffer(szBuffer, 1024))
	{
		m_strError.Format("读取指令%s存在错误", szSend);
		return FALSE;
	}
	if (strcmp(szBuffer, ">") == -1)
	{
		m_strError.Format("读取指令%s存在错误:%s", szSend, szBuffer);
		return FALSE;
	}
	return TRUE;
}
BOOL GCM83011Driver::ReadPMUint(int * nUint)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "METER:POW1:UNIT?\n");
	DWORD dwlength = strlen(szSend);
	if (!WriteBuffer(szSend, dwlength))
	{
		m_strError.Format("发送指令%s存在错误", szSend);
		return FALSE;
	}
	Sleep(20);
	ZeroMemory(szBuffer, sizeof(char) * 1024);
	if (!ReadBuffer(szBuffer, 1024))
	{
		m_strError.Format("读取指令%s存在错误", szSend);
		return FALSE;
	}
	if (strcmp(szBuffer, "dBm>") == 0)
	{
		*nUint = 0;
	}
	else if (strcmp(szBuffer, "W>") == 0)
	{
		*nUint = 1;
	}
	else if (strcmp(szBuffer, "dB>") == 0)
	{
		*nUint = 2;
	}
	return TRUE;
}
BOOL GCM83011Driver::SetPMUinit(int nUint)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	if (nUint == 0)
	{
		sprintf(szSend, "METER:POW1:UNIT dBm\n");
	}
	else if (nUint == 1)
	{
		sprintf(szSend, "METER:POW1:UNIT W\n");
	}
	else if (nUint == 2)
	{
	    sprintf(szSend, "METER:POW1:UNIT dB\n");
	}
	
	DWORD dwlength = strlen(szSend);
	if (!WriteBuffer(szSend, dwlength))
	{
		m_strError.Format("发送指令%s存在错误", szSend);
		return FALSE;
	}
	Sleep(20);
	ZeroMemory(szBuffer, sizeof(char) * 1024);
	if (!ReadBuffer(szBuffer, 1024))
	{
		m_strError.Format("读取指令%s存在错误", szSend);
		return FALSE;
	}
	if (strcmp(szBuffer, ">") == -1)
	{
		m_strError.Format("读取指令%s存在错误:%s", szSend, szBuffer);
		return FALSE;
	}
	return TRUE;
}
BOOL GCM83011Driver::ReadPMRange(int *nRange)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "METER:POW1:RANGE?\n");
	DWORD dwlength = strlen(szSend);
	if (!WriteBuffer(szSend, dwlength))
	{
		m_strError.Format("发送指令%s存在错误", szSend);
		return FALSE;
	}
	Sleep(20);
	ZeroMemory(szBuffer, sizeof(char) * 1024);
	if (!ReadBuffer(szBuffer, 1024))
	{
		m_strError.Format("读取指令%s存在错误", szSend);
		return FALSE;
	}
	*nRange = atoi(szBuffer);

	return TRUE;
}
BOOL GCM83011Driver::SetPMRange(int nRange)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "METER:POW1:RANGE %d\n", nRange);
	DWORD dwlength = strlen(szSend);
	if (!WriteBuffer(szSend, dwlength))
	{
		m_strError.Format("发送指令%s存在错误", szSend);
		return FALSE;
	}
	Sleep(20);
	ZeroMemory(szBuffer, sizeof(char) * 1024);
	if (!ReadBuffer(szBuffer, 1024))
	{
		m_strError.Format("读取指令%s存在错误", szSend);
		return FALSE;
	}
	if (strcmp(szBuffer, ">") == -1)
	{
		m_strError.Format("读取指令%s存在错误:%s", szSend, szBuffer);
		return FALSE;
	}
	return TRUE;
}
BOOL GCM83011Driver::ReadPMRangeAuto(int *nAuto)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "METER:POW1:AUTO?\n");
	DWORD dwlength = strlen(szSend);
	if (!WriteBuffer(szSend, dwlength))
	{
		m_strError.Format("发送指令%s存在错误", szSend);
		return FALSE;
	}
	Sleep(20);
	ZeroMemory(szBuffer, sizeof(char) * 1024);
	if (!ReadBuffer(szBuffer, 1024))
	{
		m_strError.Format("读取指令%s存在错误", szSend);
		return FALSE;
	}
	*nAuto = atoi(szBuffer);
	return TRUE;
}
BOOL GCM83011Driver::SetPMRangeAuto(int nAuto)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "METER:POW1:AUTO %d\n", nAuto);
	DWORD dwlength = strlen(szSend);
	if (!WriteBuffer(szSend, dwlength))
	{
		m_strError.Format("发送指令%s存在错误", szSend);
		return FALSE;
	}
	Sleep(20);
	ZeroMemory(szBuffer, sizeof(char) * 1024);
	if (!ReadBuffer(szBuffer, 1024))
	{
		m_strError.Format("读取指令%s存在错误", szSend);
		return FALSE;
	}
	if (strcmp(szBuffer, ">") == -1)
	{
		m_strError.Format("读取指令%s存在错误:%s", szSend, szBuffer);
		return FALSE;
	}
	return TRUE;
}

BOOL GCM83011Driver::ReadPMAve(double *pdbAve)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "METER:AVE?\n");
	DWORD dwlength = strlen(szSend);
	if (!WriteBuffer(szSend, dwlength))
	{
		m_strError.Format("发送指令%s存在错误", szSend);
		return FALSE;
	}
	Sleep(20);
	ZeroMemory(szBuffer, sizeof(char) * 1024);
	if (!ReadBuffer(szBuffer, 1024))
	{
		m_strError.Format("读取指令%s存在错误", szSend);
		return FALSE;
	}
	*pdbAve = atof(szBuffer);
	return TRUE;
}
BOOL GCM83011Driver::SetPMAve(double dbAve)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "METER:AVE %.2f\n", dbAve);
	DWORD dwlength = strlen(szSend);
	if (!WriteBuffer(szSend, dwlength))
	{
		m_strError.Format("发送指令%s存在错误", szSend);
		return FALSE;
	}
	Sleep(20);
	ZeroMemory(szBuffer, sizeof(char) * 1024);
	if (!ReadBuffer(szBuffer, 1024))
	{
		m_strError.Format("读取指令%s存在错误", szSend);
		return FALSE;
	}
	if (strcmp(szBuffer, ">") == -1)
	{
		m_strError.Format("读取指令%s存在错误:%s", szSend, szBuffer);
		return FALSE;
	}
	return TRUE;
}

BOOL GCM83011Driver::ReadPMScanMode(int *nMode)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "METER:SCANMODE?\n");
	DWORD dwlength = strlen(szSend);
	if (!WriteBuffer(szSend, dwlength))
	{
		m_strError.Format("发送指令%s存在错误", szSend);
		return FALSE;
	}
	Sleep(20);
	ZeroMemory(szBuffer, sizeof(char) * 1024);
	if (!ReadBuffer(szBuffer, 1024))
	{
		m_strError.Format("读取指令%s存在错误", szSend);
		return FALSE;
	}
	if (strcmp(szBuffer, "OFF>") == 0)
	{
		*nMode = 0;
	}
	else if (strcmp(szBuffer, "Trigger>") == 0)
	{
		*nMode = 1;
	}
	else if (strcmp(szBuffer, "Startup>") == 0)
	{
		*nMode = 2;
	}
	return TRUE;
}
BOOL GCM83011Driver::SetPMScanMode(int nMode)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "METER:SCANMODE %d\n", nMode);
	DWORD dwlength = strlen(szSend);
	if (!WriteBuffer(szSend, dwlength))
	{
		m_strError.Format("发送指令%s存在错误", szSend);
		return FALSE;
	}
	Sleep(20);
	ZeroMemory(szBuffer, sizeof(char) * 1024);
	if (!ReadBuffer(szBuffer, 1024))
	{
		m_strError.Format("读取指令%s存在错误", szSend);
		return FALSE;
	}
	if (strcmp(szBuffer, ">") == -1)
	{
		m_strError.Format("读取指令%s存在错误:%s", szSend, szBuffer);
		return FALSE;
	}
	return TRUE;
}

BOOL GCM83011Driver::ReadPMScanPoint(int *nPointCount)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "METER:SCANPINT?\n");
	DWORD dwlength = strlen(szSend);
	if (!WriteBuffer(szSend, dwlength))
	{
		m_strError.Format("发送指令%s存在错误", szSend);
		return FALSE;
	}
	Sleep(20);
	ZeroMemory(szBuffer, sizeof(char) * 1024);
	if (!ReadBuffer(szBuffer, 1024))
	{
		m_strError.Format("读取指令%s存在错误", szSend);
		return FALSE;
	}
	*nPointCount = atoi(szBuffer);
	return TRUE;
}
BOOL GCM83011Driver::SetPMScanPoint(int nPointCount)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "METER:SCANPOINT %d\n", nPointCount);
	DWORD dwlength = strlen(szSend);
	if (!WriteBuffer(szSend, dwlength))
	{
		m_strError.Format("发送指令%s存在错误", szSend);
		return FALSE;
	}
	Sleep(20);
	ZeroMemory(szBuffer, sizeof(char) * 1024);
	if (!ReadBuffer(szBuffer, 1024))
	{
		m_strError.Format("读取指令%s存在错误", szSend);
		return FALSE;
	}
	if (strcmp(szBuffer, ">") == -1)
	{
		m_strError.Format("读取指令%s存在错误:%s", szSend, szBuffer);
		return FALSE;
	}
	return TRUE;
}

BOOL GCM83011Driver::SetPMScanStart()
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "METER:SCAN START\n");
	DWORD dwlength = strlen(szSend);
	if (!WriteBuffer(szSend, dwlength))
	{
		m_strError.Format("发送指令%s存在错误", szSend);
		return FALSE;
	}
	Sleep(20);
	ZeroMemory(szBuffer, sizeof(char) * 1024);
	if (!ReadBuffer(szBuffer, 1024))
	{
		m_strError.Format("读取指令%s存在错误", szSend);
		return FALSE;
	}
	if (strcmp(szBuffer, ">") == -1)
	{
		m_strError.Format("读取指令%s存在错误:%s", szSend, szBuffer);
		return FALSE;
	}
	return TRUE;
}
BOOL GCM83011Driver::SetPMScanStop()
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "METER:SCAN STOP\n");
	DWORD dwlength = strlen(szSend);
	if (!WriteBuffer(szSend, dwlength))
	{
		m_strError.Format("发送指令%s存在错误", szSend);
		return FALSE;
	}
	Sleep(20);
	ZeroMemory(szBuffer, sizeof(char) * 1024);
	if (!ReadBuffer(szBuffer, 1024))
	{
		m_strError.Format("读取指令%s存在错误", szSend);
		return FALSE;
	}
	if (strcmp(szBuffer, ">") == -1)
	{
		m_strError.Format("读取指令%s存在错误:%s", szSend, szBuffer);
		return FALSE;
	}
	return TRUE;
}

BOOL GCM83011Driver::ReadPMADValue(int *nADValue)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "METER:AD?\n");
	DWORD dwlength = strlen(szSend);
	if (!WriteBuffer(szSend, dwlength))
	{
		m_strError.Format("发送指令%s存在错误", szSend);
		return FALSE;
	}
	Sleep(20);
	ZeroMemory(szBuffer, sizeof(char) * 1024);
	if (!ReadBuffer(szBuffer, 1024))
	{
		m_strError.Format("读取指令%s存在错误", szSend);
		return FALSE;
	}
	*nADValue = atoi(szBuffer);
	return TRUE;
}