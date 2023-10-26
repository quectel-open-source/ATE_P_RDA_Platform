#include "stdafx.h"
#include "Global_N.h"
#include "md5.h"
CGeneral_Global::CGeneral_Global()
{
	m_bOpen = FALSE;
}

CGeneral_Global::~CGeneral_Global()
{
	CloseFile();
}
int CGeneral_Global::Calcu_IMEI_Checksum(CString sIMEI_14_Bits)
{
	int iSum = 0;
	int irInt_Buff[16], i;
	char crTemp[2];

	memset(crTemp, 0, sizeof(crTemp));
	memset(irInt_Buff, 0, sizeof(irInt_Buff));

	for (i = 0; i < 14; i++)
	{
		crTemp[0] = sIMEI_14_Bits.GetAt(i);
		irInt_Buff[i] = atoi(crTemp);
	}

	for (i = 0; i < 7; i++)
	{
		iSum += irInt_Buff[2 * i + 1] * 2 / 10;
		iSum += irInt_Buff[2 * i + 1] * 2 % 10;
		iSum += irInt_Buff[2 * i];
	}

	iSum = iSum % 10;

	if (iSum != 0)
	{
		iSum = 10 - iSum;
	}

	//返回值
	return iSum;
}
int CGeneral_Global::Check_Com_BRate(int iBRate)
{
	if (iBRate != 9600 && iBRate != 19200 && iBRate != 38400 &&
		iBRate != 115200 && iBRate != 230400 && iBRate != 460800 && iBRate != 921600)
	{
		return 9600;
	}
	return iBRate;
}
void CGeneral_Global::CloseFile()
{
	if (m_pFile)
	{
		m_pFile.Close();
		m_bOpen = FALSE;
	}
}
void CGeneral_Global::Save_Data_To_File(CString sData)
{
	CStdioFile	C_File;
	UINT nOpenFlags;
	CString FileName = "", strFilePath = "", strPathName = "";
	if (sData == "")
	{
		AfxMessageBox("The Data is Empty!");
	}
	else
	{
		//打开另存为对话框 ，需要包含 #include <Afxdlgs.h>
		CFileDialog dlg(FALSE, "", FileName, OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, "txt File(*.txt)|*.txt||");
		dlg.m_ofn.lpstrTitle = "File Save As";

		if (dlg.DoModal() == IDOK)
		{
			//获得文件路径名
			strFilePath = dlg.GetPathName();
			//判断文件是否已经存在
			DWORD dwRe = GetFileAttributes(strFilePath);
			if (dwRe != (DWORD)-1)
			{
				if (AfxMessageBox("The file is already exist!(YES:Cover,NO:Cancel)", MB_YESNO | MB_ICONQUESTION | MB_APPLMODAL) == IDYES)
				{
					DeleteFile(strFilePath);
					//CFile::Remove((LPCTSTR)strFilePath);
					nOpenFlags = CFile::modeReadWrite | CFile::modeCreate;

					if (C_File.Open(strPathName, nOpenFlags))
					{
						C_File.WriteString(sData.GetBuffer(sData.GetLength()));
						sData.ReleaseBuffer();
						C_File.Close();
					}
				}
			}
		}
	}
}
bool CGeneral_Global::Create_Folder_Path(CString sPath, CString &sError)
{
	int nDirIndex = -1;
	CString sDirectory = "";
	if (PathFileExists(sPath))
	{
		return true;
	}
	if (sPath.GetLength() < 3 || sPath.Find("\\") < 0)
	{
		sError = "The sPath is illega";
		return false;
	}
	if (!PathIsDirectory(sPath))
	{
		if (sPath.Right(1) != "\\")
		{
			sPath += "\\";
		}
		for (int i = 0;; i++)
		{
			nDirIndex = sPath.Find("\\");
			if (nDirIndex < 0)
			{
				break;
			}
			sDirectory += sPath.Left(nDirIndex + 1);
			if (!PathFileExists(sDirectory) && !CreateDirectory(sDirectory, NULL))
			{
				sError.Format("CreateDirectory:(%s)Fai", sDirectory);
				return false;
			}
			sPath = sPath.Right(sPath.GetLength() - nDirIndex - 1);
		}
	}
	return true;
}
bool CGeneral_Global::OpenFile(const CString sFileName, UINT iFlag)
{
	CString sOpenFile = "";

	if (sFileName.Find("\\")<0)
	{
		sOpenFile = m_sCurr_Exe_Path + "\\" + sFileName;
	}
	UINT nOpenFlags = CFile::modeReadWrite/*flag? CFile::modeCreate | CFile::modeReadWrite : CFile::modeReadWrite*/;
	switch (iFlag)
	{
	case 0:
		nOpenFlags = nOpenFlags | CFile::modeCreate; //新建文件，删除文件的内容
		break;
	case 1:
		nOpenFlags = nOpenFlags | CFile::modeCreate | CFile::modeNoTruncate; //不删除原来文件里的内容
		break;
	default:
		nOpenFlags = CFile::modeReadWrite; //默认只读写
		break;
	}
	if (!m_pFile.Open(sFileName, nOpenFlags))
	{
		//文件打开或创建失败
		m_bOpen = FALSE;
	}
	m_bOpen = TRUE;
	return true;
}
bool CGeneral_Global::WriteFile(const CString sData)
{
	if (!m_bOpen)
	{
		return false;
	}

	m_pFile.SeekToEnd();
	m_pFile.WriteString(sData);
	return true;
}
bool CGeneral_Global::IS_W64(__out LPSYSTEM_INFO lpSystemInfo)
{
	typedef VOID(WINAPI *LPFN_GetNativeSystemInfo)(LPSYSTEM_INFO lpSystemInfo);
	LPFN_GetNativeSystemInfo fnGetNativeSystemInfo = (LPFN_GetNativeSystemInfo)GetProcAddress(GetModuleHandle(_T("kernel32")), "GetNativeSystemInfo");;
	if (NULL != fnGetNativeSystemInfo)
	{
		fnGetNativeSystemInfo(lpSystemInfo);
	}
	else
	{
		GetSystemInfo(lpSystemInfo);
	}
	if (lpSystemInfo->wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64 ||
		lpSystemInfo->wProcessorArchitecture == PROCESSOR_ARCHITECTURE_IA64)
	{
		return true;
	}
	return false;
}
bool CGeneral_Global::ExtractStr_DouHao(CString sData, UINT nIndex, CString &sOutput)
{
	TCHAR chSplite = ' ';
	CString sTemp = sData;
	int iCount = sTemp.Replace(",", ";");
	if (iCount >= 0)
	{
		chSplite = ',';
	}
	else
	{
		if (nIndex > 1)
		{
			sOutput = "Data not Find";
			return false;
		}
		if (sData.GetLength() > 0)
		{
			sData = sData + ",";
		}
		else
		{
			sOutput = "Data is Empty";
			return false;
		}
	}
	if (iCount < (nIndex - 1))
	{
		sOutput = "Data not Find";
		return false;
	}
	int n = 0;
	sData += chSplite;
	do
	{
		sOutput = sData.Left(sData.Find(chSplite));
		sData = sData.Right(sData.GetLength() - sData.Find(chSplite) - 1);
		n++;
	} while (n < nIndex);

	return true;
}
bool CGeneral_Global::ExtractStr(CString sData, TCHAR cKey, UINT nIndex, CString &sOutput)
{
	TCHAR chSplite = cKey;
	CString sTemp = sData;
	CString sKey = "";
	sKey.Format("%c", cKey);
	int iCount = sTemp.Replace(sKey, ";");
	if (iCount < 0)
	{
		if (nIndex > 1)
		{
			sOutput = "Data not Find";
			return false;
		}
		if (sData.GetLength() > 0)
		{
			sData = sData + ",";
		}
		else
		{
			sOutput = "Data is Empty";
			return false;
		}
	}
	if (iCount < (nIndex - 1))
	{
		sOutput = "Data not Find";
		return false;
	}
	int n = 0;
	sData += chSplite;
	do
	{
		sOutput = sData.Left(sData.Find(chSplite));
		sData = sData.Right(sData.GetLength() - sData.Find(chSplite) - 1);
		n++;
	} while (n < nIndex);

	return true;
}
bool CGeneral_Global::Find_Data_In_Arrary(int data,int DataArray[], int ArraySzie)
{
	int i = 0;
	for (i = 0; i < ArraySzie;i++)
	{
		if (data == DataArray[i])
		{
			return true;
		}
	}
	return false;
}
bool CGeneral_Global::Judge_IPAddr_Is_Legal(CString sIPAddr)
{
	int i = 0;
	CString sMid = "";

	CString sIPStr = sIPAddr;
	int iCount = sIPStr.Replace('.', ',');
	if (iCount != 4)
	{
		return false;
	}
	for (i = 1; i < 5; i++)
	{
		ExtractStr_DouHao(sIPStr, i, sMid);
		sMid.TrimLeft();
		sMid.TrimRight();
		if (sMid.IsEmpty())
		{
			return false;
		}
		if (_ttoi(sMid)<0 || _ttoi(sMid)>255)
		{
			return false;
		}
	}
	return true;
}
CString CGeneral_Global::Bool_To_String(bool iFlag)
{
	CString sFlag = "";
	if (iFlag)
	{
		sFlag = "TRUE";
	}
	else
	{
		sFlag = "FALSE";
	}
	return sFlag;
}
bool CGeneral_Global::String_To_Bool(CString sTrue_False)
{
	sTrue_False.MakeUpper();
	if (sTrue_False == "TRUE")
	{
		return true;
	}
	return false;
}

CStringW CGeneral_Global::CStrA2CStrW(const CStringA &cstrSrcA)
{
	int len = MultiByteToWideChar(CP_ACP, 0, LPCSTR(cstrSrcA), -1, NULL, 0);
	wchar_t *wstr = new wchar_t[len];
	memset(wstr, 0, len*sizeof(wchar_t));
	MultiByteToWideChar(CP_ACP, 0, LPCSTR(cstrSrcA), -1, wstr, len);
	CStringW cstrDestW = wstr;
	delete[] wstr;
	wstr = NULL;
	return cstrDestW;
}
CStringA CGeneral_Global::CStrW2CStrA(const CStringW &cstrSrcW)
{
	int len = WideCharToMultiByte(CP_ACP, 0, LPCWSTR(cstrSrcW), -1, NULL, 0, NULL, NULL);
	char *str = new char[len];
	memset(str, 0, len);
	WideCharToMultiByte(CP_ACP, 0, LPCWSTR(cstrSrcW), -1, str, len, NULL, NULL);
	CStringA cstrDestA = str;
	delete[] str;
	str = NULL;
	return cstrDestA;
}
CString CGeneral_Global::Int_DataArry_To_String(int DataArray[], int ArraySzie)
{
	CString sData = "";
	CString sMid = "";
	int i = 0;
	for (i = 0; i < ArraySzie; i++)
	{
		sMid.Format("%d,", DataArray[i]);
		sData += sMid;
	}
	sData = sData.Left(sData.GetLength() - 1);
	return sData;
}
//计算Md5
CString CGeneral_Global::Calc_MD5(const TCHAR * sData)
{
	CString sMd5_Vaue = "";
	MD5 md5;
	md5.update(sData);
	sMd5_Vaue.Format("%s", (md5.toString()).c_str());
	sMd5_Vaue.MakeUpper();
	return sMd5_Vaue;
}
