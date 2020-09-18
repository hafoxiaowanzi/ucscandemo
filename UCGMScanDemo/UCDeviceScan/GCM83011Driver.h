#pragma once
#include "OpComm.h"

class GCM83011Driver:COpComm
{
public:
	GCM83011Driver();
	~GCM83011Driver();
	BOOL GetDeviceInfo(char *pstrDevice, int nLength);
	BOOL ReadPower(double *pdbPower);
	BOOL PMZero();
	BOOL ReadPMRef(double*pdbRef);
	BOOL PMRef();
	BOOL ReadPMWavelength(double *pdbWav);
	BOOL SetPMWavelength(double dbWav);
	BOOL ReadPMUint(int * nUint);
	BOOL SetPMUinit(int nUint);

	BOOL ReadPMRange(int *nRange);
	BOOL SetPMRange(int nRange);
	BOOL ReadPMRangeAuto(int *nAuto);
	BOOL SetPMRangeAuto(int nAuto);

	BOOL ReadPMAve(double *pdbAve);
	BOOL SetPMAve(double dbAve);

	BOOL ReadPMScanMode(int *nMode);
	BOOL SetPMScanMode(int nMode);

	BOOL ReadPMScanPoint(int *nPointCount);
	BOOL SetPMScanPoint(int nPointCount);

	BOOL SetPMScanStart();
	BOOL SetPMScanStop();

	BOOL ReadPMADValue(int *nADValue);





	CString GetErrorMsg();

private:
	CString m_strError;

};

