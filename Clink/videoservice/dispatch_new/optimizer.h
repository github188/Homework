#ifndef _OPTIMIZER_H_
#define _OPTIMIZER_H_

/*
**���ڴ洫���滻���ڴ�ָ�봫��
**�漰Plugin��Dispatch
*/
#define OPT_MEM_TO_PTR

struct OPT_MEM
{
	char* memData;
	int memLen;
};

/*
**ȥ��֡��Ƭ��Ƭ֮��ļ��
**�漰Dispatch
*/
#define OPT_NO_SLICE_INTERVAL

/*
**ȥ��Timeout��������
**�漰Transfer, TfVideoSource, TfVideoOutput, TfAudioSource
*/
//#define OPT_NO_TIMEOUT

/*
**��ӡ���
**�漰Dispatch, __send_buf
*/
#define OPT_DEBUG_OUT


class TimeDiffer
{
public:
	TimeDiffer(const char* msg)
	{
		strcpy(m_msg, msg);
		b_time = clock();
		sprintf(m_info, "%s: TimeDiffer BEIGN now! clock=%ld\n", m_msg, b_time);
		OutputDebugStringA(m_info);
	}
	~TimeDiffer()
	{
		sprintf(m_info, "%s: TimeDiffer END now! clock=%ld, dif=%ld\n", m_msg, clock() - b_time);
		OutputDebugStringA(m_info);
	}

private:
	char m_msg[256];
	char m_info[256];
	long b_time;
};

#endif//_OPTIMIZER_H_