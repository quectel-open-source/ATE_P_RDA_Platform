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
	// ����
public:
	CComObj00();
	~CComObj00(void);

	// ����
public:

	// ��������������
protected:
	//д�ַ���������
	BOOL WriteCom(LPCVOID lpBuffer, UINT dwlen);
	//�Ӵ��ڶ��ַ���
	BOOL ReadCom(LPVOID lpBuffer, UINT minlen, UINT maxlen, UINT* plen);
	//������ն�ջ
	VOID ClearReadBuf();
	//ɾ�����ն�ջ�ַ�
	VOID DelCharFromReadBuf(UINT count);
	//�õ����ն�ջ�ַ�
	UCHAR GetCharFromReadBuf(UINT offset);
	//�����ַ��������ն�ջ
	BOOL ReadCharToReadBuf();

protected:
	CString smRecvBuf;
	BOOL m_bOpen;						//�Ƿ��Ѵ򿪴���
	HANDLE m_hCom;					    //���ھ��
	UINT m_nPort;						//�˿ں�
	UINT m_nReadBufLen;				    //���ն�ջ����
	UINT m_nReadBufTail;				//���ն�ջβָ��
	UINT m_nReadBufHead;				//���ն�ջͷָ��
	UCHAR m_sReadBuf[COM_READBUF_SIZE];	//���ն�ջ
	OVERLAPPED m_ov;					//�첽����

public:
	//��ȡ������Ϣ
	virtual CString GetObjectInfo();
	//��ʾ������Ϣ
	virtual VOID ViewObjectInfo(){};
	// �ӿں���
public:
	//�򿪴���
	BOOL _OpenComPort(const CString sInput = CString(),CString &sOutput = CString());			
	//�رմ���
	BOOL _CloseComPort(const CString sInput = CString(),CString &sOutput = CString());			
	//�������
	BOOL _ClearComPort(const CString sInput = CString(),CString &sOutput = CString());			
	//���ô���
	BOOL _SetComState(const CString sInput = CString(),CString &sOutput = CString());			
	//���ô���
	BOOL _EscapeCommFunction(const CString sInput = CString(),CString &sOutput = CString());	

	//����16�����ַ���
	BOOL _SendHex(const CString sInput = CString(),CString &sOutput = CString());				
	//����ASCII���ַ���
	BOOL _SendStr(const CString sInput = CString(),CString &sOutput = CString());	
	BOOL _SendStrCR(const CString sInput,CString &sOutput);
	//����16�����ַ���
	BOOL _ReceiveHex(const CString sInput = CString(),CString &sOutput = CString());			
	//����ASCII���ַ���
	BOOL _ReceiveStr(const CString sInput = CString(),CString &sOutput = CString());	
	BOOL _ReceiveStrCheck(const CString sInput = CString(),CString &sOutput = CString());	
	//�ȴ��趨��16�����ַ���
	BOOL _WaitHex(const CString sInput = CString(),CString &sOutput = CString());				
	//�ȴ��趨��ASCII���ַ���
	BOOL _WaitStr(const CString sInput = CString(),CString &sOutput = CString());	
	//�ȴ��趨���ַ�������������
	BOOL _WaitStrPrintf(const CString sInput = CString(),CString &sOutput = CString());
};
