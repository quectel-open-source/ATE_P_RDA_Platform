#pragma once

#ifdef _DEBUG
#define COM_READ_SLEEP			100
#else
#define COM_READ_SLEEP			50
#endif
#define COM_READBUF_SIZE		4096
#define COM_READ_TIMEOUT		60000

#define COM_CHECKOPENED	\
	if(!m_bOpen)\
	{\
		AfxMessageBox("Com port isn't opened",MB_OK|MB_ICONSTOP);\
		return FALSE;\
	}

#define COM_CHECKCLOSED	\
	if(m_bOpen)\
	{\
		AfxMessageBox("Com port is opened",MB_OK|MB_ICONSTOP);\
		return FALSE;\
	}

class AFX_EXT_CLASS CComObj00
{
	// 构造
public:
	CComObj00();
	~CComObj00(void);

	// 类型
public:

	// 保护变量及函数
protected:
	//写字符串到串口
	BOOL WriteCom(LPCVOID lpBuffer, UINT dwlen);
	//从串口读字符串
	BOOL ReadCom(LPVOID lpBuffer, UINT minlen, UINT maxlen, UINT* plen);
	//清除接收堆栈
	VOID ClearReadBuf();
	//删除接收堆栈字符
	VOID DelCharFromReadBuf(UINT count);
	//得到接收堆栈字符
	UCHAR GetCharFromReadBuf(UINT offset);
	//读入字符串到接收堆栈
	BOOL ReadCharToReadBuf();

protected:
	CString smRecvBuf;
	BOOL m_bOpen;						//是否已打开串口
	HANDLE m_hCom;					    //串口句柄
	UINT m_nPort;						//端口号
	UINT m_nReadBufLen;				    //接收堆栈长度
	UINT m_nReadBufTail;				//接收堆栈尾指针
	UINT m_nReadBufHead;				//接收堆栈头指针
	UCHAR m_sReadBuf[COM_READBUF_SIZE];	//接收堆栈
	OVERLAPPED m_ov;					//异步对象

public:
	//获取对象信息
	virtual CString GetObjectInfo();
	//显示对象信息
	virtual VOID ViewObjectInfo(){};
	// 接口函数
public:
	//打开串口
	BOOL _OpenComPort(const CString sInput = CString(),CString &sOutput = CString());			
	//关闭串口
	BOOL _CloseComPort(const CString sInput = CString(),CString &sOutput = CString());			
	//清除串口
	BOOL _ClearComPort(const CString sInput = CString(),CString &sOutput = CString());			
	//设置串口
	BOOL _SetComState(const CString sInput = CString(),CString &sOutput = CString());			
	//设置串口
	BOOL _EscapeCommFunction(const CString sInput = CString(),CString &sOutput = CString());	

	//发送16进制字符串
	BOOL _SendHex(const CString sInput = CString(),CString &sOutput = CString());				
	//发送ASCII码字符串
	BOOL _SendStr(const CString sInput = CString(),CString &sOutput = CString());	
	BOOL _SendStrCR(const CString sInput,CString &sOutput);
	//接收16进制字符串
	BOOL _ReceiveHex(const CString sInput = CString(),CString &sOutput = CString());			
	//接收ASCII码字符串
	BOOL _ReceiveStr(const CString sInput = CString(),CString &sOutput = CString());	
	BOOL _ReceiveStrCheck(const CString sInput = CString(),CString &sOutput = CString());	
	//等待设定的16进制字符串
	BOOL _WaitHex(const CString sInput = CString(),CString &sOutput = CString());				
	//等待设定的ASCII码字符串
	BOOL _WaitStr(const CString sInput = CString(),CString &sOutput = CString());	
	//等待设定的字符串并完整返回
	BOOL _WaitStrPrintf(const CString sInput = CString(),CString &sOutput = CString());
};
