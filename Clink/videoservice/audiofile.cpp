#include <stdlib.h>
#include "audiofile.h"
/*�ṩAAC-ADTS�ļ��ķ��ʽӿ�*/

/*strFileName [in]: ��Ƶ�ļ���·�����ַ���
 * boolRepeat [in]: �������ļ�βʱ�Ƿ���ʼ��ļ���ʼλ���ظ���ȡ
*/
AudioFile::AudioFile(char * strFileName, bool boolRepeat)
{
	m_boolRepeat = boolRepeat;
	m_audioFile = fopen(strFileName, "rb");
	if(NULL == m_audioFile)
	{
		printf("========>[APP] Error! In AudioFile::AudioFile(): fopen() failed at %s:%d\n", __FILE__, __LINE__);
	}
	GenerateFramePosIndex();
	m_it = m_framePosIndex.begin();
	
	return;
}

/*��ȡ��Ƶ������
* ����˵��: sampleRate [out]:������(HZ)
*           bitsPerSample [out]: ÿ����ռ��bit��
*����: 0: �ɹ���-1:ʧ��
*/
int AudioFile::GetSampleInfo(int & sampleRate, int & bitsPerSample)
{
	sampleRate = 44100;
	bitsPerSample = 8;
	return 0;
}

/*��ȡ��һ֡��Ƶ������
* ����˵��:buf [in]: ֡��Ƶ���ݵĻ�����[Ԥ�ȹ̶�����,Ҫ��֤�䳤�ȴ�������һ֡����]
*                        dataLen [in]:Ԥ�ȷ����֡����������
*                        dataLen [out]: �����ĳ��� 
   *  ����: 0:�ɹ���1: δ��ȡ��֡����,���ѻ�ȡ���ļ�β�����ٴγ��Զ�ȡ��-1: ʧ��
*/
int AudioFile::GetNextFrame(char * buf, int & dataLen)
{
	//MyTime	myTime((char *)"AudioFile::GetNextFrame()");
	int ret = -1;
	int curPos = *m_it;
	m_it++;
	if(m_it == m_framePosIndex.end()) //��ȡ�����һ֡
	{
		if(m_boolRepeat)
		{
			m_it = m_framePosIndex.begin();
			return 1;
		}
		return -1;
	}

	int nextPos = *m_it;

	fseek(m_audioFile, curPos, SEEK_SET);
	int len = nextPos - curPos;
	if(len > dataLen)
	{
		printf("========>[APP] Error! In AudioFile::GetNextFrame(): frameBuf size(%d) is too small at %s:%d\n", dataLen,  __FILE__, __LINE__);
		return -1;
	}
	ret = fread(buf, 1, len, m_audioFile);
	if(ret < 0)
	{
		printf("========>[APP] Error! In AudioFile::GetNextFrame(): fread() failed at %s:%d\n", __FILE__, __LINE__);
		return -1;
	}
	else
	{
		dataLen = len;
		//printf(">>>>>>>>[APP]: In AudioFile::GetNextFrame(): buf[0~4] = [0x%x, 0x%x, 0x%x, 0x%x, 0x%x], dataLen = %d\n", buf[0], buf[1], buf[2], buf[3], buf[4], dataLen);
		return 0;
	}

	return -1;	
}

/*Ѱ����һ��section�Ŀ�ʼ(0xFFF91080Ϊ���)[����ļ�ͷ���ֽ���ƫ��]
* ����: >=0: ��ǿ�ʼλ�����ļ���λ��
*              <0: ���ҵ��ļ�β����δ���ҵ�
* ע:���øú����ڼ䣬��Ҫ�޸��ļ���дλ��
*/
int AudioFile::SeekNextSectionFlag(void)
{
	if(NULL == m_audioFile)
	{
		printf("========>[APP]: Warning! In AudioFile::SeekNextSectionFlag(): AudioFile is NULL!\n");
		return -1;
	}

	/*Ѱ�ҷ���: ÿ�����ƫ��1���ֽڣ���ȡ4���ֽڣ����õ�0xFFFX����˵���ҵ��˱��*/
	#define  FLAG_SIZE  4
	//int flag = 0x00000001;
	char content[FLAG_SIZE+1] = {0};
	int ret = -1;
	
	do{
		ret = fread(content, 1, FLAG_SIZE, m_audioFile);
		if(FLAG_SIZE != ret)
		{
			return -1;
		}
		
		//if( (0xFF == content[0]) &&(0xF9 == content[1]) && (0x10 == content[2]) && (0x80 == content[3]) )
		//if((0xFF == content[0]) && ( (content[1] & 0xF0) == 0xF0))
		if( (0xFF == content[0]) &&(0xF1 == content[1]) && (0x50 == content[2]) && (0x80 == content[3]) )
		{
			return (ftell(m_audioFile) - FLAG_SIZE);
		}
		else
		{
			fseek(m_audioFile, -(FLAG_SIZE-1), SEEK_CUR); //���ֽڲ��� 
		}
	}while(0 < ret);

	return -1;
}

/*�ж��Ƿ�����Ƶ֡���ݶ�
*/
bool AudioFile::IsFrameSection(unsigned char flag)
{
	return false;
}

/*����֡λ������*/
int AudioFile::GenerateFramePosIndex(void)
{
	int pos = -1;
	do{
		pos = SeekNextSectionFlag();
		if(0 <= pos)
		{
			//printf("========>[APP]: In AudioFile::GenerateFramePosIndex(): m_framePosIndex.push_back(%d)...\n", pos);
			m_framePosIndex.push_back(pos);
		}
	}while(0 <= pos);
	fseek(m_audioFile, 0, SEEK_SET); //�ļ���дָ�����ص��ļ���ʼ��
	
	return 0;
}


