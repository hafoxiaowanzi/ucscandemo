#pragma once
#include "OpComm.h"
class CGM82009Driver :
	public COpComm
{
public:
	CGM82009Driver();
	~CGM82009Driver();
	BOOL GetDeviceInfo(char *pstrDevice, int nLength);
	BOOL ReadSourceState(int *nState);
	BOOL SetSourceState(int nState);

	BOOL ReadSourceFreq(double *pdbFreq);
	BOOL SetSourceFreq(double dbFreq);
	BOOL ReadSourceFreqMinMax(double *pdbMinFreq, double *pdbMaxFreq);

	BOOL SetSourceCurFreqMax();
	BOOL SetSourceCurFreqMin();

	BOOL ReadSourceFreqOffset(double *pdbOffset);
	BOOL SetSourceFreqOffset(double dbOffset);

	BOOL ReadSourceWavelength(double *pdbWavelength);
	BOOL SetSourceWavelength(double dbWavelength);

	BOOL ReadSourceWavelengthMinMax(double *pdbMaxWav, double*pdbMinWave);
	BOOL SetSourceWavelengthMin();
	BOOL SetSourceWavelengthMax();

	BOOL ReadSourceWavelengthOffset(double*pdbWavOffset);
	BOOL SetSourceWavelengthOffset(double dbWavOffset);

	BOOL ReadSourcePower(double*pdbPower);
	BOOL ReadSourceUnit(int *nUnit);
	BOOL SetSourceUnit(int nUnit);

	CString GetErrorMsg();

	BOOL SetSourceSweep();
	BOOL SetSourceSweepAbort();
	BOOL ReadSourceSweepSynchDelay(double*pdbValue);
	BOOL SetSourceSweepSynchDelay(double dbSecond);
	BOOL ReadSourceSweepDwell(double *pdbValue);
	BOOL SetSourceSweepDwell(double dbSecond);
	BOOL ReadSourceSweepPulseLevel(double*pdbValue);
	BOOL SetSourceSweepPulseLevel(double pdbValue);
	BOOL ReadSourceSweepMode(int *nMode);
	BOOL SetSourceSweepMode(int nMode);

	BOOL ReadSourceSweepStart(int nType, double *pdbVaule);
	BOOL SetSourceSweepStart(int nType, double dbValue);
	BOOL ReadSourceSweepStop(int nType, double *pdbValue);
	BOOL SetSourceSweepStop(int nType, double dbValue);
	BOOL ReadSourceSweepStep(int nType, double*pdbStep);
	BOOL SetSourceSweepStep(int nType, double dbStep);


	




private:
	CString m_strError;


};

