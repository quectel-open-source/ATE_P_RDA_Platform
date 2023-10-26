#pragma once

class CGeneral_Global
{
public:
	CGeneral_Global();
	virtual ~CGeneral_Global();
protected:
	CStdioFile m_pFile;					//�ļ���������
	BOOL m_bOpen;						//�ļ��Ƿ��
public:
	bool String_To_Bool(CString sTrue_False);
	CString Bool_To_String(bool iFlag);
public:
	void Save_Data_To_File(CString sData);
	void CloseFile();
	CString Int_DataArry_To_String(int DataArray[], int ArraySzie);
	//��ȡ��ǰ������Ŀ¼										
	CStringW CStrA2CStrW(const CStringA &cstrSrcA);
	CStringA CStrW2CStrA(const CStringW &cstrSrcW);
	bool OpenFile(const CString sFileName, UINT iFlag = 0);
	bool WriteFile(const CString sData);
	//���������ļ���·��
	bool Create_Folder_Path(CString sPath, CString &sError);			
	bool IS_W64(__out LPSYSTEM_INFO lpSystemInfo);
	bool ExtractStr_DouHao(CString sData, UINT nIndex, CString &sOutput);
	bool ExtractStr(CString sData, TCHAR cKey, UINT nIndex, CString &sOutput);
	bool IMEI_Number_Check(CString sIMEI);
	bool Find_Data_In_Arrary(int data, int DataArray[], int ArraySzie);
	int Calcu_IMEI_Checksum(CString sIMEI_14_Bits);
	//�ж�IP��ַ�Ƿ�Ϸ�
	bool Judge_IPAddr_Is_Legal(CString sIPAddr);
	int Check_Com_BRate(int iBRate);
	//����Md5
	CString Calc_MD5(const TCHAR * sData);
public:
	CString m_sCurr_Exe_Path;			//��ǰ������Ŀ¼

};

