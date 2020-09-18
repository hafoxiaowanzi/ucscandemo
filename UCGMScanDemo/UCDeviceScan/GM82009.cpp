#include "stdafx.h"
#include "GM82009.h"


CGM82009Driver::CGM82009Driver()
{
}


CGM82009Driver::~CGM82009Driver()
{
}

CString CGM82009Driver::GetErrorMsg()
{
	return m_strError;
}

BOOL CGM82009Driver::GetDeviceInfo(char *pstrDevice, int nLength)
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
	dwlength = strlen(szBuffer);
	memcpy(pstrDevice, szBuffer, dwlength);

	return TRUE;
}
BOOL CGM82009Driver::ReadSourceState(int *nState)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "SOURCE:STATE?\n");
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
	if (strcmp(szBuffer, "ON") != -1)
	{
		*nState = 1;
	}
	else if (strcmp(szBuffer, "OFF") != -1)
	{
		*nState = 0;
	}
	else
	{
		*nState = -1;
	}
	return TRUE;

}
BOOL CGM82009Driver::SetSourceState(int nState)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "SOURCE:STATE %d\n", nState);
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

BOOL CGM82009Driver::ReadSourceFreq(double *pdbFreq)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "SOURCE:FREQUENCY?\n");
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
	*pdbFreq = atof(szBuffer);
	return TRUE;
}
BOOL CGM82009Driver::SetSourceFreq(double dbFreq)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "SOURCE:FREQUENCY %.0f\n", dbFreq);
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
BOOL CGM82009Driver::ReadSourceFreqMinMax(double *pdbMinFreq, double *pdbMaxFreq)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "SOURCE:FREQUENCY?MIN\n");
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
	*pdbMinFreq = atof(szBuffer);

	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "SOURCE:FREQUENCY?MAX\n");
	dwlength = strlen(szSend);
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
	*pdbMaxFreq = atof(szBuffer);
	return TRUE;
}
BOOL CGM82009Driver::SetSourceCurFreqMax()
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "SOURCE:FREQUENCY MAX\n");
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
BOOL CGM82009Driver::SetSourceCurFreqMin()
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "SOURCE:FREQUENCY MIN\n");
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

BOOL CGM82009Driver::ReadSourceFreqOffset(double *pdbOffset)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "SOURCE:FREQUENCY:OFFSET?\n");
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
	*pdbOffset = atof(szBuffer);
	return TRUE;
}
BOOL CGM82009Driver::SetSourceFreqOffset(double dbOffset)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "SOURCE:FREQUENCY:OFFSET %.0f\n", dbOffset);
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

BOOL CGM82009Driver::ReadSourceWavelength(double *pdbWavelength)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "SOURCE:WAVELENGTH?\n");
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
	*pdbWavelength = atof(szBuffer);
	return TRUE;
}
BOOL CGM82009Driver::SetSourceWavelength(double dbWavelength)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "SOURCE:WAVELENGTH %.3f\n", dbWavelength);
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

BOOL CGM82009Driver::ReadSourceWavelengthMinMax(double *pdbMaxWav, double*pdbMinWave)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "SOURCE:WAVELENGTH?MIN\n");
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
	*pdbMaxWav = atof(szBuffer);

	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "SOURCE:WAVELENGTH?MAX\n");
	dwlength = strlen(szSend);
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
	*pdbMinWave = atof(szBuffer);
	return TRUE;
}
BOOL CGM82009Driver::SetSourceWavelengthMin()
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "SOURCE:WAVELENGTH MIN\n");
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
BOOL CGM82009Driver::SetSourceWavelengthMax()
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "SOURCE:WAVELENGTH MAX\n");
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

BOOL CGM82009Driver::ReadSourceWavelengthOffset(double*pdbWavOffset)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "SOURCE:WAVELENGTH:OFFSET?\n");
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
	*pdbWavOffset = atof(szBuffer);
	return TRUE;
}
BOOL CGM82009Driver::SetSourceWavelengthOffset(double dbWavOffset)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "SOURCE:WAVELENGTH:OFFSET %.0f\n", dbWavOffset);
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

BOOL CGM82009Driver::ReadSourcePower(double*pdbPower)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "SOURCE:POWER?\n");
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
BOOL CGM82009Driver::ReadSourceUnit(int *nUnit)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "SOURCE:POWER:UNIT?\n");
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

	if (strcmp(szBuffer, "dBm") != -1)
	{
		*nUnit = 0;
	}
	else if (strcmp(szBuffer, "nW") != -1)
	{
		*nUnit = 0;
	}
	else
	{
		*nUnit = -1;
	}
	return TRUE;
}
BOOL CGM82009Driver::SetSourceUnit(int nUnit)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	if (nUnit == 0)
	{
		sprintf(szSend, "SOURCE:POWER:UNIT dBm\n");
	}
	else if (nUnit == 1)
	{
		sprintf(szSend, "SOURCE:POWER:UNIT nW\n");
	}
	else
	{
		m_strError.Format("输入的nUnit参数错误");
		return FALSE;
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

BOOL CGM82009Driver::SetSourceSweep()
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "SWEEP:INITIATE\n");

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
BOOL CGM82009Driver::SetSourceSweepAbort()
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "SWEEP:ABORT\n");

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
BOOL CGM82009Driver::ReadSourceSweepSynchDelay(double*pdbValue)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "SWEEP:SYNCH DELAY?\n");
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
	*pdbValue = atof(szBuffer);
	return TRUE;
}
BOOL CGM82009Driver::SetSourceSweepSynchDelay(double dbSecond)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "SWEEP:SYNCH:DELAY %.4f\n", dbSecond);

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
BOOL CGM82009Driver::ReadSourceSweepDwell(double *pdbValue)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "SWEEP:DWELL?\n");
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
	*pdbValue = atof(szBuffer);
	return TRUE;
}
BOOL CGM82009Driver::SetSourceSweepDwell(double dbSecond)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "SWEEP:DWELL %.4f\n", dbSecond);

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
BOOL CGM82009Driver::ReadSourceSweepPulseLevel(double*pdbValue)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "SWEEP:PULSE LEVEL?\n");
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
	*pdbValue = atof(szBuffer);
	return TRUE;
}
BOOL CGM82009Driver::SetSourceSweepPulseLevel(double pdbValue)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "SWEEP:PULSE LEVEL %.0f\n", pdbValue);

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
BOOL CGM82009Driver::ReadSourceSweepMode(int *nMode)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	char *token = NULL;
	char szSpec[] = ",";
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "SWEEP:MODE?\n");
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

	token = strtok(szBuffer, szSpec);
	token = strtok(NULL, szSpec);

	*nMode = atoi(szBuffer);
	return TRUE;
}
BOOL CGM82009Driver::SetSourceSweepMode(int nMode)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	sprintf(szSend, "SWEEP:MODE 0, %d\n", nMode);

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

BOOL CGM82009Driver::ReadSourceSweepStart(int nType, double *pdbVaule)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	if (nType == 0)
	{
		sprintf(szSend, "SWEEP:WAVE:START?\n");
	}
	else if(nType ==1)
	{
		sprintf(szSend, "SWEEP:FREQ:START?\n");
	}
	else
	{
		m_strError.Format("输入的nType参数错误");
		return FALSE;
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
	*pdbVaule = atof(szBuffer);
	return TRUE;
}
BOOL CGM82009Driver::SetSourceSweepStart(int nType, double dbValue)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	if (nType == 0)
	{
		sprintf(szSend, "SWEEP:WAVE:START %.2f\n", dbValue);
	}
	else if (nType == 1)
	{
		sprintf(szSend, "SWEEP:FREQ:START %.2f\n", dbValue);
	}
	else
	{
		m_strError.Format("输入的nType参数错误");
		return FALSE;
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
BOOL CGM82009Driver::ReadSourceSweepStop(int nType, double *pdbValue)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	if (nType == 0)
	{
		sprintf(szSend, "SWEEP:WAVE:STOP?\n");
	}
	else if (nType == 1)
	{
		sprintf(szSend, "SWEEP:FREQ:STOP?\n");
	}
	else
	{
		m_strError.Format("输入的nType参数错误");
		return FALSE;
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
	*pdbValue = atof(szBuffer);
	return TRUE;
}
BOOL CGM82009Driver::SetSourceSweepStop(int nType, double dbValue)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	if (nType == 0)
	{
		sprintf(szSend, "SWEEP:WAVE:STOP %.2f\n", dbValue);
	}
	else if (nType == 1)
	{
		sprintf(szSend, "SWEEP:FREQ:STOP %.2f\n", dbValue);
	}
	else
	{
		m_strError.Format("输入的nType参数错误");
		return FALSE;
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
BOOL CGM82009Driver::ReadSourceSweepStep(int nType, double*pdbStep)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	if (nType == 0)
	{
		sprintf(szSend, "SWEEP:WAVE:STEP?\n");
	}
	else if (nType == 1)
	{
		sprintf(szSend, "SWEEP:FREQ:STEP?\n");
	}
	else
	{
		m_strError.Format("输入的nType参数错误");
		return FALSE;
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
	*pdbStep = atof(szBuffer);
	return TRUE;
}
BOOL CGM82009Driver::SetSourceSweepStep(int nType, double dbStep)
{
	char szBuffer[1024];
	char szSend[MAX_PATH];
	ZeroMemory(szSend, sizeof(char) * MAX_PATH);
	if (nType == 0)
	{
		sprintf(szSend, "SWEEP:WAVE:STOP %.3f\n", dbStep);
	}
	else if (nType == 1)
	{
		sprintf(szSend, "SWEEP:FREQ:STOP %.0f\n", dbStep);
	}
	else
	{
		m_strError.Format("输入的nType参数错误");
		return FALSE;
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