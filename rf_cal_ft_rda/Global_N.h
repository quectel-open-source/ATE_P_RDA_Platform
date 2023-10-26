#pragma once

class CGeneral_Global
{
public:
	CGeneral_Global();
	virtual ~CGeneral_Global();
protected:
	CStdioFile m_pFile;					//文件操作对象
	BOOL m_bOpen;						//文件是否打开
public:
	bool String_To_Bool(CString sTrue_False);
	CString Bool_To_String(bool iFlag);
public:
	void Save_Data_To_File(CString sData);
	void CloseFile();
	CString Int_DataArry_To_String(int DataArray[], int ArraySzie);
	//获取当前程序工作目录										
	CStringW CStrA2CStrW(const CStringA &cstrSrcA);
	CStringA CStrW2CStrA(const CStringW &cstrSrcW);
	bool OpenFile(const CString sFileName, UINT iFlag = 0);
	bool WriteFile(const CString sData);
	//创建本地文件夹路径
	bool Create_Folder_Path(CString sPath, CString &sError);			
	bool IS_W64(__out LPSYSTEM_INFO lpSystemInfo);
	bool ExtractStr_DouHao(CString sData, UINT nIndex, CString &sOutput);
	bool ExtractStr(CString sData, TCHAR cKey, UINT nIndex, CString &sOutput);
	bool IMEI_Number_Check(CString sIMEI);
	bool Find_Data_In_Arrary(int data, int DataArray[], int ArraySzie);
	int Calcu_IMEI_Checksum(CString sIMEI_14_Bits);
	//判断IP地址是否合法
	bool Judge_IPAddr_Is_Legal(CString sIPAddr);
	int Check_Com_BRate(int iBRate);
	//计算Md5
	CString Calc_MD5(const TCHAR * sData);
public:
	CString m_sCurr_Exe_Path;			//当前程序工作目录

};

