#ifndef _VTRON_HIPC_H_
#define _VTRON_HIPC_H_
#include <network/network.h>
#include <x_log/msglog.h>

#define Uint8 unsigned char
typedef char Int8;              ///< Signed  8-bit integer

#define Uint16 unsigned short
#define Int16  short
typedef unsigned int Uint32;    ///< Unsigned 32-bit integer
typedef	char CHAR;

//��x1000���岻ͬ
#define    HIPC_CODEC_PCM				0
#define    HIPC_CODEC_G711				1
#define    HIPC_CODEC_AAC				2
#define    HIPC_CODEC_G726				3

#pragma pack(push)
#pragma pack(1)

//namespace HIPC
//{
typedef struct
{
	char proxyserver[32];
	Uint32 channel;
	Uint8 streamID;
	char OSD[48];
}PARAMS_DEF;

typedef struct
{                      
	Uint32    sync;         //Э��汾��
	Uint32    msgType;      //��Ϣ���� ID
	Uint32    msgCode;      //��Ϣ���
	Uint32	  len;          //��Ϣ����
	Uint32    errCode;      //������
}T_HIPC_NET_HEADER;

typedef struct _IPC_CMD_VIDEO_INFO
{//����0x8201��Ӧ��0x8202
    T_HIPC_NET_HEADER	   head;      //Э��ͷ
    Uint32	sig_chan;			//�忨�Ĵ���ͨ�����
	Uint8	streamID;			//ÿ������ͨ�����������
    Int8    video_encode_type;	//0--264;1--mepg2;2--MJPEG
    Int16   width;				//���
    Int16   height;				//�߶� 
	Uint32	reserved;			//�����ֽ�
}T_IPC_VIDEO_INFO_REQ, T_IPC_VIDEO_INFO_RESP;

typedef struct _IPC_CMD_AUDIO_INFO
{//����0x8209��Ӧ��0x8210
	T_HIPC_NET_HEADER	head;
	Uint32				sig_chan;			//�忨�Ĵ���ͨ�����
	Uint16				audio_encode_type;	//��Ƶ�����ʽ0--PCM;1��G.711;2--AAC
	Uint32				audio_sample_rate;	//��Ƶ����Ƶ����
	Uint8				audio_sample_bit;	//����λ��
	Uint8				audio_sample_chan;	//��Ƶ������0����������1����������2��˫����
	Uint32				reserved;			//�����ֽ�
}T_IPC_AUDIO_INFO_REQ, T_IPC_AUDIO_INFO_RESP;

typedef  struct _T_IPC_VIDEO_CONNECT
{//����0x8203��Ӧ��0x8204
    T_HIPC_NET_HEADER	head;
	Uint32				sig_chan;		//�忨�Ĵ���ͨ�����
	Uint8				streamID;		//ÿ������ͨ�����������
	Uint8				ipAddress[64];	// ������Լ���ip��ַ(������RTSPʱ������Ϊrtsp��URL��ַ)
	Uint16				port;			//�����tcp�����ʹ�øö˿�������Ƶ����
	Uint8				mode;			//��Ƶ���ͷ�ʽ 0:UDP�鲥 1: UDP 2: TCP 3:RTSP.
	Uint32				reserved;		//�����ֽ�
}T_IPC_VIDEO_CONNECT_REQ, T_IPC_VIDEO_CONNECT_RESP;

typedef  struct _T_IPC_VIDEO_DISCONNECT
{//����0x8205��Ӧ��0x8206
    T_HIPC_NET_HEADER	head;
	Uint32				sig_chan;		//�忨�Ĵ���ͨ�����
	Uint8				streamID;		//ÿ������ͨ�����������
	Uint8				ipAddress [64];	// ������Լ���ip��ַ
	Uint16				port;			//�����tcp�����ʹ�øö˿�������Ƶ����
	Uint8				mode;			//��Ƶ���ͷ�ʽ0:UDP�鲥 1: UDP 2: TCP 3:RTSP.
	Uint32				reserved;		//�����ֽ�
}T_IPC_VIDEO_DISCONNECT_REQ, T_IPC_VIDEO_DISCONNECT_RESP;

typedef  struct _T_IPC_AUDIO_CONNECT
{//����0x8300��Ӧ��0x8301
    T_HIPC_NET_HEADER	head;
	Uint32				sig_chan;		//�忨�Ĵ���ͨ�����  
	Uint8				audioID;		//���Ӧ��Ƶ�������������Ƶ��
	Uint8				ipAddress[64];	//������Լ���ip��ַ��
	Uint16				port;			//�����tcp�����ʹ�øö˿�������Ƶ����
	Uint8				mode;			//��Ƶ���ͷ�ʽ 0:UDP�鲥 1: UDP 2: TCP 3:RTSP.
	Uint32				reserved;		//�����ֽ�
}T_IPC_AUDIO_CONNECT_REQ, T_IPC_AUDIO_CONNECT_RESP;

typedef  struct _T_IPC_AUDIO_DISCONNECT
{//����0x8302��Ӧ��0x8303
    T_HIPC_NET_HEADER	head;
	Uint32				sig_chan;		//�忨�Ĵ���ͨ�����  
	Uint8				audioID;		//���Ӧ��Ƶ�������������Ƶ��
	Uint8				ipAddress[64];	//������Լ���ip��ַ
	Uint16				port;			//�����tcp�����ʹ�øö˿����ӱ���
	Uint8				mode;			//��Ƶ���ͷ�ʽ 0:UDP�鲥 1: UDP 2: TCP 3:RTSP.
	Uint32				reserved;		//�����ֽ�
}T_IPC_AUDIO_DISCONNECT_REQ, T_IPC_AUDIO_DISCONNECT_RESP;

typedef struct _T_IPC_VIDEO_I_FRAME
{//����0x8207��Ӧ��0x8208
	T_HIPC_NET_HEADER	head;
	Uint32				sig_chan;	//�忨�Ĵ���ͨ�����
	Uint8				streamID;	//ÿ������ͨ�����������      
}T_IPC_VIDEO_I_FRAME_REQ, T_IPC_VIDEO_I_FRAME_RESP;

typedef struct{
    Uint32 sync;                //ͬ��ͷ
    Uint32 len;                 //����������
    Uint32 frame_num;           //֡����
    Uint32 frame_size;          //��ǰ֡�Ĵ�С
    Uint32 stream_id;           //�ڼ�·��Ƶ
    Uint32 packet_num;          //�ְ�����
    Uint32 packet_size;         //��ǰ��frame_data�Ĵ�С
    Uint32 packet_last;         //�Ƿ���һ֡�����һ����
    Uint32 frame_gop;           //gop ��С
    Uint32 frame_type;          //֡����,1-I frmae, 0-P frame   
    Uint32 timestamp;           //ʱ���
    Uint16 all_w;               //�ܿ��
    Uint16 all_h;               //�ܸ߶�
    Uint16 valid_x;             //��ʼ�㣺Xλ��
    Uint16 valid_y;             //��ʼ�㣺Yλ��
    Uint16 valid_w;             //ͼ����Ч��� ��X+W<= width_t
    Uint16 valid_h;             //ͼ����Ч�߶� ��Y+h<= height_t
    Uint8  frame_data[8 * 1024];//��Ƶ��Ч����

}HIPC_V_PACKET;


typedef struct{
	Uint32 sync;				//ͬ��ͷ
	Uint32 len;					//����������
	Uint32 frame_num;           //֡����
	Uint32 frame_size;          //��ǰ֡�Ĵ�С
	Uint32 stream_id;           //�ڼ�·��Ƶ
	Uint32 packet_num;          //�ְ�����
	Uint32 packet_size;         //��ǰ��frame_data�Ĵ�С
	Uint32 packet_last;         //�Ƿ���һ֡�����һ����
	Uint32 timestamp;           //ʱ���
	Uint8  frame_data[2048];	//��Ƶ��Ч����
}HIPC_A_PACKET;

//2015/05/29 add

typedef struct
{
    T_HIPC_NET_HEADER		head;
    Uint32					sig_chan;
    Uint8					streamID;
    Uint16					framerate;     //��������֡��
}T_HIPC_CMD_VIDEO_FRAME_RATE_REQ, T_HIPC_CMD_VIDEO_FRAME_RATE_RESP;


//};//namespace HIPC

#pragma pack(pop)

#endif
