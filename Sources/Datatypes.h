#ifndef _DATATYPES_H_
#define _DATATYPES_H_

#define SERVER_IP_LEN			15

#define MAX_MID_LEN			15
#define MAX_APN_LEN			50
#define MAX_PERSONALIZEDMSG_LEN			160


typedef struct _server_
{
	char ip[SERVER_IP_LEN + 1];
	int port;
}Server;

typedef struct _term_config_param_
{
	char MID[MAX_MID_LEN + 1];
	Server host;
	char APN[MAX_APN_LEN + 1];
	char PersonalizedMsg[MAX_PERSONALIZEDMSG_LEN + 1];
}TermConfigParam;

#define MAX_SN_LEN				20
#define MAX_FACEVALUE_LEN				10
#define MAX_PINCODE_LEN				20
#define MAX_VALIDDATE_LEN				25

typedef struct _pin_details_
{
	char serialNumber[MAX_SN_LEN + 1]; 
	char faceValue[MAX_FACEVALUE_LEN + 1];
	char pinCode[MAX_SN_LEN + 1]; 
	char validDate[MAX_FACEVALUE_LEN + 1];
}PIN_Details;

typedef enum {
	FREE = 0,
	SOLD,	
}Status;

typedef struct _pin_record_
{
	PIN_Details pinDetails;
	Status status;
}PIN_Record;


#endif
