#ifndef	__IPMS_NET_SDK_H__
#define	__IPMS_NET_SDK_H__


#include <stdlib.h>

#ifdef __cplusplus
#define	IPMS_EXTERN_C	extern "C"
#else
#define	IPMS_EXTERN_C
#endif


#ifdef WIN32	/* win32 */
	#ifdef IPMS_NET_SDK_EXPORTS
		#define IPMS_API IPMS_EXTERN_C __declspec(dllexport)
	#elif defined IPMS_NET_SDK_TEST
		#define IPMS_API
	#else
		#define IPMS_API IPMS_EXTERN_C __declspec(dllimport)
	#endif 
#else	/* linux */
	#define IPMS_API IPMS_EXTERN_C
	#define	__stdcall
#endif


// ��������Э��
#define	IPMS_NET_TCP							1
#define	IPMS_NET_UDP							2
#define	IPMS_NET_MULTICAST						3


// ��������
#define	IPMS_PREVIEW							0
#define	IPMS_REPLAY								1
#define	IPMS_DOWNLOAD							2


// �����붨��

#define	IPMS_ERROR_SUCCESS							0			/*<	�����ɹ�						*/
#define	IPMS_ERROR_DOWNLOAD_COMPLETE				1			/*< �������						*/
#define	IPMS_ERROR_COMMON_FAILURE					-97000		/*< ����ʧ��						*/
#define	IPMS_ERROR_COMMON_INVALID_USER_HANDLE		-97001		/*< �û������Ч					*/
#define	IPMS_ERROR_COMMON_INVALID_USERNAME			-97002		/*< �û�����Ч(ָ��Ϊ�ջ�̫��)		*/
#define	IPMS_ERROR_COMMON_INVALID_PASSWORD			-97003		/*< ������Ч(ָ��Ϊ�ջ�̫��)		*/
#define	IPMS_ERROR_COMMON_INVALID_TRANS_TYPE		-97004		/*< ��Ч��������������				*/
#define	IPMS_ERROR_COMMON_INVALID_CHANNEL			-97005		/*< ͨ�������Ч					*/
#define	IPMS_ERROR_COMMON_INVALID_TYPE				-97006		/*< ������Ч						*/
#define	IPMS_ERROR_COMMON_MEMORY_ALLOC_FAILED		-97007		/*< �ڴ����ʧ��					*/
#define	IPMS_ERROR_COMMON_NO_SIGNAL_IN_REGION		-97008		/*< ��ָ��������Χ��û�漰�κ��ź�	*/


// �����ڵ㽻��ʱ���ֵĴ���
#define	IPMS_ERROR_MNODE_INVALID_IPADDR				-97200		/*< ����ڵ��IP��ַ��Ч			*/
#define	IPMS_ERROR_MNODE_INVALID_PORT				-97201		/*< ����ڵ�Ķ˿ں���Ч			*/
#define	IPMS_ERROR_MNODE_INVALID_RESPONSE			-97202		/*< ����ڵ㷵���˴������Ӧ��		*/
#define	IPMS_ERROR_MNODE_INVALID_CHANNEL_DESC		-97203		/*< ��Ч��ͨ��������Ϣ				*/
#define	IPMS_ERROR_MNODE_CONNECT_FAILED				-97204		/*< ���ӹ��������ʧ��				*/
#define	IPMS_ERROR_MNODE_DISCONNECTD				-97205		/*< �����������������ѶϿ�		*/
#define	IPMS_ERROR_MNODE_NOT_LOGIN					-97206		/*< ����δ��¼,������Ȩ�޲���		*/
#define	IPMS_ERROR_MNODE_EMPTY_CHANNEL				-97207		/*< ͨ���е��ź�Դ����Ϊ0			*/
#define	IPMS_ERROR_MNODE_GET_SESSION_FAILED			-97208		/*< ��ȡ�ỰIDʧ��				*/

// ��ת��ڵ㽻��ʱ���ֵĴ���
#define	IPMS_ERROR_TNODE_INVALID_IPADDR				-97300		/*< ת��ڵ��IP��ַ��Ч			*/
#define	IPMS_ERROR_TNODE_INVALID_PORT				-97301		/*< ת��ڵ�Ķ˿ں���Ч			*/
#define	IPMS_ERROR_TNODE_INVALID_RESPONSE			-97302		/*< ת��ڵ㷵���˴������Ӧ��		*/
#define	IPMS_ERROR_TNODE_INVALID_STREAM_DESC		-97303		/*< ת��ڵ㷵�ص��źŷֿ��ź���Ч	*/
#define	IPMS_ERROR_TNODE_INVALID_TRANS_TYPE			-97304		/*< [�ڲ�����]��Ч��������������	*/
#define	IPMS_ERROR_TNODE_INVALID_PACKET_LEN			-97305		/*< ��Ч�����ݰ�����(>50M)			*/
#define	IPMS_ERROR_TNODE_INVALID_UDP_PACKET			-97306		/*< ת��ڵ㷢����UDP���ݰ���Ч		*/
#define	IPMS_ERROR_TNODE_CONNECT_FAILED				-97307		/*< ����ת��ڵ�ʧ��				*/
#define	IPMS_ERROR_TNODE_DISCONNECTD				-97308		/*< ��ת��ڵ�������ѶϿ�			*/
#define	IPMS_ERROR_TNODE_ALREADY_RUNNING			-97309		/*< [�ڲ�����]�ظ�����ת��ڵ�����	*/
#define	IPMS_ERROR_TNODE_UNKNOWN_RESPONSE			-97310		/*< [�ڲ�����]δ֪��ת��ڵ���Ӧ��	*/
#define	IPMS_ERROR_TNODE_GET_LOCAL_ADDR_FAILED		-97311		/*< ��ȡ������ַʧ��				*/
#define	IPMS_ERROR_TNODE_ALLOC_UDP_PORT_FAILED		-97312		/*< ����UDP����˿�ʧ��			*/
#define	IPMS_ERROR_TNODE_SIG_NOT_SUPPORT_MULTICAST	-97313		/*< ��ǰ�źŲ�֧�ֶಥ����			*/
#define	IPMS_ERROR_TNODE_MULTICAST_PORT_OCCUPIED	-97314		/*< �ಥ�˿ڱ�ռ��, �޷���������	*/
#define	IPMS_ERROR_TNODE_JOIN_MULTICAST_FAILED		-97315		/*< ����ಥ��ʧ��				*/
#define	IPMS_ERROR_TNODE_RECV_FRAME_FAILED			-97316		/*< ��ȡ֡����ʧ��				*/
#define	IPMS_ERROR_TNODE_REQUEST_STREAM_FAILED		-97317		/*< ��������ʧ�ܡ�				*/
#define	IPMS_ERROR_TNODE_MEDIA_FORMAT_UNKNOWN		-97318		/*< δ֪�������ݸ�ʽ				*/
#define	IPMS_ERROR_TNODE_PROGRAM_ERROR				-97319		/*< �����ڲ�����					*/
#define	IPMS_ERROR_TNODE_RECV_UDP_STREAM_FAILED		-97320		/*< ��UDP����ʧ��					*/
#define	IPMS_ERROR_TNODE_MAKE_UDP_SERVER_FAILED		-97321		/*< ����UDP��������ʧ��			*/


// ��洢�ڵ㽻��ʱ���ֵĴ���
#define	IPMS_ERROR_SNODE_INVALID_IPADDR				-97400		/*< �洢�ڵ��IP��ַ��Ч			*/
#define	IPMS_ERROR_SNODE_INVALID_PORT				-97401		/*< �洢�ڵ�Ķ˿ں���Ч			*/
#define	IPMS_ERROR_SNODE_INVALID_RESPONSE			-97402		/*< �洢�ڵ㷵���˴������Ӧ��		*/
#define	IPMS_ERROR_SNODE_INVALID_STREAM_DESC		-97403		/*< �洢�ڵ㷵�ص��źŷֿ��ź���Ч	*/
#define	IPMS_ERROR_SNODE_INVALID_TRANS_TYPE			-97404		/*< [�ڲ�����]��Ч��������������	*/
#define	IPMS_ERROR_SNODE_INVALID_PACKET_LEN			-97405		/*< ��Ч�����ݰ�����(>50M)			*/
#define	IPMS_ERROR_SNODE_CONNECT_FAILED				-97407		/*< ���Ӵ洢�ڵ�ʧ��				*/
#define	IPMS_ERROR_SNODE_DISCONNECTD				-97408		/*< ��洢�ڵ�������ѶϿ�			*/
#define	IPMS_ERROR_SNODE_ALREADY_RUNNING			-97409		/*< [�ڲ�����]�ظ����մ洢�ڵ�����	*/
#define	IPMS_ERROR_SNODE_UNKNOWN_RESPONSE			-97410		/*< [�ڲ�����]δ֪�Ĵ洢�ڵ���Ӧ��	*/
#define	IPMS_ERROR_SNODE_GET_LOCAL_ADDR_FAILED		-97411		/*< ��ȡ������ַʧ��				*/
#define	IPMS_ERROR_SNODE_RECV_FRAME_FAILED			-97416		/*< ��ȡ֡����ʧ��				*/
#define	IPMS_ERROR_SNODE_REQUEST_STREAM_FAILED		-97417		/*< ��������ʧ�ܡ�				*/
#define	IPMS_ERROR_SNODE_MEDIA_FORMAT_UNKNOWN		-97418		/*< δ֪�������ݸ�ʽ				*/
#define	IPMS_ERROR_SNODE_PROGRAM_ERROR				-97419		/*< �����ڲ�����					*/



#define	IPMS_ERROR_SDK_MIN_ERROR_CODE				-97000		/*< ��SDK��С�Ĵ�����ֵ			*/
#define	IPMS_ERROR_SDK_MAX_ERROR_CODE				-99000		/*< ��SDK���Ĵ�����ֵ			*/


#pragma pack(push)
#pragma pack(1)

/** ͨ����Ż��������(��uuid_t���ڴ�ṹһ��) */
typedef	struct	_IPMS_UUID_t
{
	unsigned char	data[16];
}IPMS_UUID_t;


/** ��һ������ */
typedef	struct	_IPMS_ZONE_t
{
	double			x;		// �뱣֤x <= 1 && x >= 0
	double			y;		// �뱣֤y <= 1 && y >= 0
	double			w;		// �뱣֤ w >= 0 && x + w <= 1
	double			h;		// �뱣֤ h >= 0 && y + h <= 1
}IPMS_ZONE_t;


/** �������� */
typedef	enum _IPMS_MEDIA_FMT_t
{
	IPMS_MEDIA_FMT_UNKNOWN	= 0,
	IPMS_MEDIA_FMT_YV12		= 0x32315659,
	IPMS_MEDIA_FMT_I420		= 0x30323449,
	IPMS_MEDIA_FMT_H264		= 0x34363248,
	IPMS_MEDIA_FMT_MPEG4	= 0x2034504D,
	IPMS_MEDIA_FMT_G726		= 0x36323747,
	IPMS_MEDIA_FMT_AAC		= 0x20434141,
	IPMS_MEDIA_FMT_OGG		= 0x2047474F
}IPMS_MEDIA_FMT_t;


/** ֡���� */
typedef	enum _IPMS_FRAME_TYPE_t
{
	IPMS_FRAME_NONE			= 0,
	IPMS_FRAME_IFRAME		= 100,
	IPMS_FRAME_PFRAME		= 200,
	IPMS_FRAME_BFRAME		= 300
}IPMS_FRAME_TYPE_t;


typedef	struct	_IPMS_VIDEO_t
{
	IPMS_FRAME_TYPE_t		frame_type;				// ֡����
	IPMS_ZONE_t				region;					// [��Ƶ����]ͼ�����ͨ���ϵ�λ�úʹ�С, ���[0.0, 0.0, 1.0, 1.0]
	IPMS_ZONE_t				clip;					// [��Ƶ����]ͼ������Ч����������(����ȥ�ӱ�), ���[0.0, 0.0, 1.0, 1.0]
	int						width;					// ͼ���
	int						height;					// ͼ���
}IPMS_VIDEO_t;


typedef	struct	_IPMS_AUDIO_t
{
	int						sample_rate;			// [��Ƶ����]������
	int						channels;				// [��Ƶ����]������
	int						bits_per_sample;		// [��Ƶ����]������λ��
}IPMS_AUDIO_t;



/** ֡��Ϣ */
typedef	struct	_IPMS_MEDIA_FRAME_t
{
	int						stream_id;				// �����

	IPMS_MEDIA_FMT_t		media_fmt;				// ���ݸ�ʽ
	int						is_video;				// �Ƿ�Ϊ��Ƶ֡

	unsigned long long		timestamp;				// ʱ������Ժ���Ϊ��λ��
	unsigned long long		position;				// �ط�λ��(�ط�ʱ��Ч)

	IPMS_VIDEO_t			video;					// ͼ��֡��Ϣ(is_video��0ʱ��Ч)
	IPMS_AUDIO_t			audio;					// ��Ƶ֡��Ϣ(is_videoΪ0ʱ��Ч)

	unsigned char*			frame_data;				// ֡������ָ��
	unsigned int			frame_size;				// ֡���ݳ���
}IPMS_FRAME_t;


// ����Ϣ
typedef	struct	_IPMS_STREAM_t
{
	int						stream_id;				// �����

	IPMS_MEDIA_FMT_t		format;					// ���ݸ�ʽ
	int						is_video;				// �Ƿ�Ϊ��Ƶ֡

	IPMS_VIDEO_t			video;					// ͼ��֡��Ϣ(is_video��0ʱ��Ч)
	IPMS_AUDIO_t			audio;					// ��Ƶ֡��Ϣ(is_videoΪ0ʱ��Ч)
}IPMS_STREAM_t;


typedef	struct	_IPMS_REPLAY_PERIOD_t
{
	unsigned long long		begin_time;
	unsigned long long		end_time;
}IPMS_REPLAY_PERIOD_t;


typedef	struct {int unused;}*	IPMS_USER_t;

typedef void (__stdcall *IPMS_FRAME_CB_t)(IPMS_FRAME_t* frame, void* context);
typedef	void (__stdcall *IPMS_ERROR_CB_t)(IPMS_UUID_t* channel, int error, const char* description, const char* addr, unsigned short port, void* context);
typedef	void (__stdcall *IPMS_STREAM_LISTENER_t)(IPMS_UUID_t* id /*preview.channel | replay.stream*/, int stream_num, IPMS_STREAM_t streams[], void* context);




IPMS_API	IPMS_USER_t	__stdcall	IPMS_NET_Login				(const char* addr, unsigned short port, const char* user, const char* pwd, int timeout = -1, int* error = NULL);
IPMS_API	IPMS_USER_t	__stdcall	IPMS_NET_Login2				(const char* addr, unsigned short port, long long session, int timeout = -1, int* error = NULL);
IPMS_API	int			__stdcall	IPMS_NET_Logout				(IPMS_USER_t user);

IPMS_API	int			__stdcall	IPMS_NET_SetFrameCB			(IPMS_USER_t user, IPMS_FRAME_CB_t frame_cb, void* context);
IPMS_API	int			__stdcall	IPMS_NET_SetErrorCB			(IPMS_USER_t user, IPMS_ERROR_CB_t error_cb, void* context);

IPMS_API	int			__stdcall	IPMS_NET_SetStreamListener	(IPMS_USER_t user, IPMS_STREAM_LISTENER_t listener, void* context);

IPMS_API	int			__stdcall	IPMS_NET_OpenStream			(IPMS_USER_t user, IPMS_UUID_t* channel, int protocol, int type = IPMS_PREVIEW, IPMS_REPLAY_PERIOD_t* period = NULL);
IPMS_API	int			__stdcall	IPMS_NET_OpenStream2		(IPMS_USER_t user, IPMS_UUID_t* channel, int protocol, IPMS_ZONE_t* region, int type = IPMS_PREVIEW, IPMS_REPLAY_PERIOD_t* period = NULL, IPMS_UUID_t* stream = NULL);
IPMS_API	int			__stdcall	IPMS_NET_CloseStream		(IPMS_USER_t user);


#pragma pack(pop)

#endif	// __IPMS_NET_SDK_H__