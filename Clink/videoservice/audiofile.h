#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <list>
/*�ṩAAC-ADTS�ļ��ķ��ʽӿ�*/
using namespace std;

class AudioFile{
	public:
		/*strFileName [in]: ��Ƶ�ļ���·�����ַ���
              * boolRepeat [in]: �������ļ�βʱ�Ƿ���ʼ��ļ���ʼλ���ظ���ȡ
		*/
		AudioFile(char * strFileName, bool boolRepeat);
		/*��ȡ��һ֡��Ƶ������
		* ����˵��:buf [in]: ֡��Ƶ���ݵĻ�����[Ԥ�ȹ̶�����,Ҫ��֤�䳤�ȴ�������һ֡����]
		*                        dataLen [in]:Ԥ�ȷ����֡����������
		*                        dataLen [out]: �����ĳ��� 
	       *  ����: 0:�ɹ���1: δ��ȡ��֡����,���ѻ�ȡ���ļ�β��-1: ʧ��
		*/
		int GetNextFrame(char * buf, int & dataLen);

	private:
		/*��ȡ��Ƶ������
		* ����˵��: sampleRate [out]:������
		*           bitsPerSample [out]: ÿ����ռ��bit��
		*����: 0: �ɹ���-1:ʧ��
		*/
		int GetSampleInfo(int & sampleRate, int & bitsPerSample);
		/*Ѱ����һ��section�Ŀ�ʼ(0x00000001Ϊ���)
		* ����: >=0: ��ǿ�ʼλ�����ļ���λ��
		*              <0: ���ҵ��ļ�β����δ���ҵ�
		* ע:���øú����ڼ䣬��Ҫ�޸��ļ���дλ��
		*/
		int SeekNextSectionFlag(void);
		/*�ж��Ƿ�����Ƶ֡���ݶ�
         * �㷨: int type = flag & 0x1f����typeΪ5����ΪI֡����typeΪ1����ΪB/P֡
		*/
		bool IsFrameSection(unsigned char flag);
		/*����֡λ������*/
		int GenerateFramePosIndex(void);

	private:
		bool				m_boolRepeat;	//�������ļ�βʱ�Ƿ���ʼ��ļ���ʼλ���ظ���ȡ
		FILE	*			m_audioFile;	
		list<int>			m_framePosIndex; //֡λ����������¼ÿһ֡���ļ��е���ʼλ��
		list<int>::iterator	m_it;	//��ǰm_framePosIndex�ĵ�����
};


