#ifndef _PACK8583_H_
#define _PACK8583_H_

#include "ST8583.h"

#ifdef __cplusplus
extern "C" {
#endif

#define STANDARD_BITMAP_SIZE		8
#define EXTEND_BITMAP_SIZE			16

#define ERR_INVALID_FIELDNO			-10  //invalid field no the field no is out of ranges
#define ERR_NULL_POINTER			-11 // null pointer
#define ERR_ALOM_FAILED				-12 // Alloc memery fails
#define ERR_BASELEN_WRONG			-1000 //base error of invalid length and real length errno will be (ERR_BASELEN_WRONG - field no)
#define ERR_INVALID_BITMAPSIZE		-13 //invalid size of bitmap
#define ERR_INVALID_MSG				-14 //invalid length of message
#define ERR_INVALID_LENLENATTR		-15 //the length's length's attribute is out of range
#define ERR_INVALID_CONTENTATTR		-16 //the content's attribute is out of range

#define BITMAPBIT1			0X80
#define BITMAPBIT2			0X40
#define BITMAPBIT3			0X20
#define BITMAPBIT4			0X10
#define BITMAPBIT5			0X08
#define BITMAPBIT6			0X04
#define BITMAPBIT7			0X02
#define BITMAPBIT8			0X01

typedef int (*saveData)(unsigned char fieldNo, void *content, unsigned short len);

/**
 * @description: unpack the iso8583 message
 * @param: srcMsg -  the iso8583 message that you wan to decode
 * @param: srcMsgLen - des message length in
 * @param: PsaveData - save the field's callback
 * @retval: 0 - success
 * @retval: none zero - fail
 */
int unpackISO8583Msg(unsigned char *srcMsg, unsigned short srcMsgLen, saveData PsaveData);

/**
 * @description: pack ISO8583 message
 * @param: des8583Msg - buffer for the iso8583 message
 * @param: desMsgLen - des message length out
 * @param: fns - the field set that you want to use for build the iso8583 message
 * @retval: 0 - success
 * @retval: none zero - fail
 */
int packISO8583Msg(unsigned char *des8583Msg, unsigned short *desMsgLen,
		FdNoSet *fns);

#ifdef __cplusplus
}
#endif

#endif
