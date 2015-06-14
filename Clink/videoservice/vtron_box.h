#ifndef __VTRON_BOX_H__
#define __VTRON_BOX_H__

#include <network/network.h>
#include <x_log/msglog.h>

#define Uint8 unsigned char
typedef char Int8;              ///< Signed  8-bit integer

#define Uint16 unsigned short
typedef unsigned int Uint32;    ///< Unsigned 32-bit integer
typedef	char CHAR;

#pragma pack(push)
#pragma pack(1)

typedef struct _PARAMS_DEF
{
	char			ProxyServer[32];
	int				channel;

}PARAMS_DEF;

typedef struct
{                      
    Uint32    sync;             //Э�������ֶ�
    Uint32    msgType ;          //��Ϣ����
    Uint32    msgCode ;          //��Ϣ����
    Uint32    len;              //��Ϣ����
    Uint32    errCode;          //������
} T_IPC_NET_HEADER;

typedef  struct
{
    T_IPC_NET_HEADER head;
    Uint8 channel;              //
    Uint8 ipAddress[20];        //modeΪ�鲥����Ϊ�鲥��ַ ����Ϊclient��ip��ַ
    Uint16 port;                //�˿ں�   ----��ʱ��������
    Uint8 mode;                 //��Ƶ���ͷ�ʽ 0:UDP�鲥 1:TCP 2:UDP 3:RTP.
} T_IPC_VIDEO_CONNECT_REQ, T_IPC_VIDEO_CONNECT_RESP;

typedef  struct
{
    T_IPC_NET_HEADER head;
    Uint8 channel;              //ͨ����
    Uint8 multAddress[20];      //�鲥��ַ ---��������Ψһ�鲥��ַ
    Uint16 port;                //�˿ں�   ----��ʱ��������
    Uint8 mode;                 //��Ƶ���ͷ�ʽ 0:UDP�鲥 1:TCP 2:UDP 3:RTP.

} T_IPC_VIDEO_DISCONNECT_REQ, T_IPC_VIDEO_DISCONNECT_RESP;

typedef  struct
{
    T_IPC_NET_HEADER	   head;
    Uint8  channel;          //
    Uint8  ipAddress[20];   //
    Uint16  port;            //
    Uint8  mode;            //
} T_IPC_AUDIO_CONNECT_REQ, T_IPC_AUDIO_CONNECT_RESP;

typedef  struct
{
    T_IPC_NET_HEADER	   head;
    Uint8  channel;          //
    Uint8  ipAddress[20];   //
    Uint16  port;            //--
    Uint8  mode;            //
} T_IPC_AUDIO_DISCONNECT_REQ, T_IPC_AUDIO_DISCONNECT_RESP;


typedef struct              
{
    T_IPC_NET_HEADER head;      //Э��ͷ
    Uint8 channel;              //ͨ��,

}T_IPC_KEYFRAME_REQ, T_IPC_KEYFRAME_RESP;

typedef  struct
{
    T_IPC_NET_HEADER head;
    Uint8 channel;              //ֻ��cvbs��Ҫ���ô��ֶ�
    Uint8 autoBright;           //0:mannul 1:auto

} T_IPC_SIGNAL_AUTO_BRIGHT_REQ, T_IPC_SIGNAL_AUTO_BRIGHT_RESP;

typedef  struct
{
    T_IPC_NET_HEADER head;
    Uint8 channel;              //CVBS �����ʹ��
    Uint8 autoContrast;         //0:mannul 1:auto

} T_IPC_SIGNAL_AUTO_CONTRAST_REQ, T_IPC_SIGNAL_AUTO_CONTRAST_RESP;

typedef  struct
{
    T_IPC_NET_HEADER head;
    Uint8 channel;              //cvbs ���ô��ֶ�
    Uint8 color;                ///< RGB�������Ҫ���ô��ֶΣ���ɫ 0 :Red  1:Green  2:Blue
    Uint16 offset;              ///< �Աȶ� 0��150

} T_IPC_SIGNAL_MANNUL_CONTRAST_REQ, T_IPC_SIGNAL_MANNUL_CONTRAST_RESP;

typedef  struct
{
    T_IPC_NET_HEADER head;
    Uint8 channel;              //ֻ��CVBS��Ҫ����
    Uint8 color;                ///< ֻ��RGB���뿨��Ҫ���ã���ɫ 0 :Red  1:Green  2:Blue
    Uint16 offset;              ///ƫ�� 0��1023

} T_IPC_SIGNAL_MANNUL_BRIGHT_REQ, T_IPC_SIGNAL_MANNUL_BRIGHT_RESP; 

typedef  struct
{
    T_IPC_NET_HEADER head;
    Uint8  channel;             //cvbs ���ô��ֶ�
    Uint8  color; 
    Uint16 offset;              //CVBS 0-255

} T_IPC_SIGNAL_MANNUL_SATURATION_REQ, T_IPC_SIGNAL_MANNUL_SATURATION_RESP;
 
//ɫ��
typedef  struct
{
    T_IPC_NET_HEADER head;
    Uint8 channel;              //cvbs ���ô��ֶ�
    Uint8 color;        
    Uint16 offset;              //CVBS 0-255

} T_IPC_SIGNAL_MANNUL_HUE_REQ, T_IPC_SIGNAL_MANNUL_HUE_RESP; 

typedef  struct
{
    T_IPC_NET_HEADER head;
    Uint8 drgbOrArgb;           //0��DRGB  1:ARGB

} T_IPC_SIGNAL_SELECT_REQ,T_IPC_SIGNAL_SELECT_RESP;

typedef  struct
{
    T_IPC_NET_HEADER head;
    Uint8 type;                 //0:��ƫ1:��ƫ
    Uint16 value;               //<=511
    Uint8 channel;

} T_IPC_SIGNAL_HS_REQ, T_IPC_SIGNAL_HS_RESP;

typedef  struct
{
    T_IPC_NET_HEADER head;
    Uint8 type;                 //0:��ƫ1:��ƪ
    Uint8 value;                //<=15
    Uint8 channel;

} T_IPC_SIGNAL_VS_REQ, T_IPC_SIGNAL_VS_RESP;

typedef  struct
{
    T_IPC_NET_HEADER head;
    Uint8 autoOffset;           //0:MANNUL 1:auto        

} T_IPC_SIGNAL_AUTO_OFFSET_REQ, T_IPC_SIGNAL_AUTO_OFFSET_RESP;


typedef  struct
{
    T_IPC_NET_HEADER head;
    Uint8 type;                 //0:��ƫ 1:��ƫ
    Uint16 htotalOffset;        //ÿ��������ƫ��ֵ   127  

} T_IPC_SIGNAL_HTOTAL_OFFSET_REQ, T_IPC_SIGNAL_HTOTAL_OFFSET_RESP;

typedef  struct
{
    T_IPC_NET_HEADER head;
    Uint8 channel;
    Uint8 autoFormat;           //0: mannual 1:auto

} T_IPC_VIDEO_FORMAT_REQ, T_IPC_VIDEO_FORMAT_RESP;

typedef  struct
{
    T_IPC_NET_HEADER head;
    Uint8 pumpCurrent;          //�õ���ֵ0-7

} T_IPC_ARGB_PUMP_CURRENT_REQ, T_IPC_ARGB_PUMP_CURRENT_RESP;

typedef  struct
{
    T_IPC_NET_HEADER head;
    Uint8 samplePhase;          //ʱ����λ0-31

} T_IPC_ARGB_SAMPLE_PHASE_REQ, T_IPC_ARGB_SAMPLE_PHASE_RESP;

typedef  struct
{
    T_IPC_NET_HEADER head;

} T_IPC_ARGB_WHITE_BLANCE_REQ, T_IPC_ARGB_WHITE_BLANCE_RESP;

typedef  struct
{
    T_IPC_NET_HEADER head;
    Uint8 channel;
    Uint16 width;
    Uint16 height;

} T_IPC_SIGNAL_RESOLUTION_REQ, T_IPC_SIGNAL_RESOLUTION_RESP;

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
    Uint32 frame_type;          //֡����0-I frmae, 1-P frame   
    Uint32 timestamp;           //ʱ���
    Uint16 all_w;               //���
    Uint16 all_h;               //�߶�
    Uint16 valid_x;             //
    Uint16 valid_y;             //
    Uint16 valid_w;             //
    Uint16 valid_h;             //
    Uint8  frame_data[8 * 1024];//��Ƶ��Ч����

}V_PACKET;


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
	Uint8  frame_data[2 * 1024];// ��Ƶ��Ч����
}A_PACKET;


#pragma pack(pop)


#define IP_TCP_PORT      	5002

#define IPC_CMD_VIDEO_CONNECT_STREAM_REQ  0x8203 //������Ƶ����
typedef enum 
{
    NET_SEND_MULTICAST = 0,
    NET_SEND_UDP,
    NET_SEND_TCP,  
    NET_SEND_RTP

} NET_SEND_TYPE; 

inline bool check(V_PACKET* p)
{
	if(p->sync != 0x12345678)
	{
		return false;
	}

	if(p->packet_last != 0 && p->packet_last != 1)
	{
		return false;
	}

	if(p->valid_x + p->valid_w > p->all_w || p->valid_y + p->valid_h > p->all_h)
	{
		return false;
	}

	return true;

}

inline int GetHeader(int sockfd, V_PACKET *header)
{
	u_int32       readlen;

	if ( (readlen =	Network::Readn(sockfd, header, sizeof(V_PACKET))) != sizeof(V_PACKET))
	{
		return RET_ERROR;
	}

	if(!check(header) )
	{
		LOG(LEVEL_ERROR,"Check The Sync Is Error \n");
		return RET_ERROR;
	}

	return RET_SUCCESS;

}

inline int GetHeader(int sockfd, A_PACKET *header)
{
	u_int32       readlen;

	if ( (readlen =	Network::Readn(sockfd, header, sizeof(A_PACKET))) != sizeof(A_PACKET))
	{
		return RET_ERROR;
	}

	return RET_SUCCESS;

}


#endif

