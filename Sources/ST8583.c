#include "ST8583.h"
#include "Utils.h"
#include "Pack8583.h"

//static FdContent fc;

FIELD fieldS[] = { 
//			{ 1, { N, MAX_MSGCODE_LEN, FIX, L }, },  //message code
//			{ 2, { N, MAX_PAN_LEN, VAR, LL }, }, //Primary Account Number
//			{ 3, { N, MAX_TPC_LEN, FIX, L }, },  //Transaction Processing Code
		{ 5, { B, MAX_MDI_LEN, FIX, L }, }, //MDI
		{ 6, { ANS, MAX_PWD_LEN, VAR, LLL }, }, //Amount, settlement

//			{ 6, { N, MAX_AOCB_LEN, FIX, LL }, },  //Amount, cardholder billing
//			{ 7, { N, MAX_TDT_LEN, FIX, LL }, }, //Transmission date & time
//			{ 8, { N, MAX_TPC_LEN, FIX, L }, },  //Amount, cardholder billing fee
		{ 10, { AN, MAX_FACEVALUEISO8583_LEN, FIX, LL}, }, //Conversion rate, settlement
//			{ 10, { N, MAX_CROCB_LEN, FIX, LL }, }, //Conversion rate, cardholder billing
//	
//			{ 11, { N, MAX_STAN_LEN, FIX, L }, },  //System trace audit number
//			{ 12, { N, MAX_TOLT_LEN, FIX, LL }, }, //Time, local transaction (hhmmss)
		{ 14, { AN, MAX_RSPDESCRIPTION_LEN, FIX, LL}, }, //Date, local transaction (MMDD)
//			{ 14, { N, MAX_DOE_LEN, FIX, L }, }, //Date, expiration
//			{ 15, { N, MAX_DOS_LEN, FIX, L }, }, //Date, settlement
//	
//			{ 16, { N, MAX_DOC_LEN, FIX, L }, },  //Date, conversion
//			{ 17, { N, MAX_DOCP_LEN, FIX, L }, }, //Date, capture
//			{ 18, { N, MAX_MT_LEN, FIX, L }, },  //Merchant type
		{ 21, { N, MAX_VOUCHER500XAFNUM_LEN, FIX, L }, }, //Acquiring institution country code
		{ 21, { N, MAX_VOUCHER1000XAFNUM_LEN, FIX, L }, }, //PAN extended, country code

		{ 22, { N, MAX_VOUCHER2500XAFNUM_LEN, FIX, L }, }, //Forwarding institution. country code
		{ 23, { N, MAX_VOUCHER5000XAFNUM_LEN, FIX, L }, }, //Point of service entry mode
		{ 24, { N, MAX_VOUCHER10000XAFNUM_LEN, FIX, L }, }, //Application PAN sequence number
		{ 25, { N, MAX_VOUCHER25000XAFNUM_LEN, FIX, L }, }, //Function code (ISO 8583:1993)/Network International identifier (NII)
		{ 26, { N, MAX_VOUCHER50000XAFNUM_LEN, FIX, L }, }, //Point of service condition code

//			{ 26, { N, MAX_POSPCC_LEN, FIX, L }, }, //Point of service capture code
//			{ 27, { N, MAX_AIRL_LEN, FIX, L }, }, //Authorizing identification response length
//			{ 28, { N, MAX_AOTF_LEN, FIX, L }, },  //Amount, transaction fee
		{ 30, { AN, MAX_PERSONALIZEDMSGISO8583_LEN, FIX, LLL }, }, //Amount, settlement fee
//			{ 30, { N, MAX_AOTPF_LEN, FIX, LL }, }, //Amount, transaction processing fee
//	
//			{ 31, { N, MAX_AOSPF_LEN, FIX, L }, }, //	Amount, settlement processing fee
//			{ 32, { N, MAX_AIIC_LEN, VAR, LL }, }, //Acquiring institution identification code
//			{ 33, { N, MAX_FIIC_LEN, FIX, L }, }, //Forwarding institution identification code
//			{ 34, { N, MAX_PANEX_LEN, VAR, LL }, }, //Primary account number, extended
//			{ 35, { Z, MAX_T2_LEN, VAR, LL }, }, //Track 2 data
//	
//			{ 36, { Z, MAX_T3_LEN, VAR, LLL }, },  //Track 3 data
//			{ 37, { AN, MAX_RRN_LEN, FIX, LL }, }, //Retrieval reference number
//			{ 38, { N, MAX_AIR_LEN, FIX, L }, }, //Authorization identification response
//			{ 39, { AN, MAX_RC_LEN, FIX, L }, }, //Response code
		{ 40, { ANS, MAX_VOUCHERDETAILS_LEN, VAR, LLL }, }, //Service restriction code

		{ 41, { ANS, MAX_VOUCHERDETAILS_LEN, VAR, LLL }, }, //	Card acceptor terminal identification
		{ 42, { ANS, MAX_VOUCHERDETAILS_LEN, VAR, LLL }, }, //Card acceptor identification code
		{ 43, { ANS, MAX_VOUCHERDETAILS_LEN, VAR, LLL }, }, //Card acceptor name/location (1-23 address 24-36 city 37-38 state 39-40 country)
		{ 44, { ANS, MAX_VOUCHERDETAILS_LEN, VAR, LLL }, }, //Additional response data
		{ 45, { ANS, MAX_VOUCHERDETAILS_LEN, VAR, LLL }, }, //Track 1 data

		{ 46, { ANS, MAX_VOUCHERDETAILS_LEN, VAR, LLL }, },  //Additional data - ISO
		{ 47, { ANS, MAX_VOUCHERDETAILS_LEN, VAR, LLL }, }, //Additional data - national
		{ 48, { ANS, MAX_VOUCHERDETAILS_LEN, VAR, LLL }, },  //Additional data - private
		{ 49, { ANS, MAX_VOUCHERDETAILS_LEN, VAR, LLL }, }, //Currency code, transaction
		{ 50, { ANS, MAX_VOUCHERDETAILS_LEN, VAR, LLL }, }, //Currency code, settlement

		{ 51, { ANS, MAX_VOUCHERDETAILS_LEN, VAR, LLL }, }, //	Currency code, cardholder billing
		{ 52, { ANS, MAX_VOUCHERDETAILS_LEN, VAR, LLL }, }, //Personal identification number data
		{ 53, { ANS, MAX_VOUCHERDETAILS_LEN, VAR, LLL }, }, //Security related control information
		{ 54, { ANS, MAX_VOUCHERDETAILS_LEN, VAR, LLL }, }, //Additional amounts
		{ 55, { ANS, MAX_VOUCHERDETAILS_LEN, VAR, LLL }, }, //Reserved ISO

		{ 56, { ANS, MAX_VOUCHERDETAILS_LEN, VAR, LLL }, },  //Reserved ISO
		{ 57, { ANS, MAX_VOUCHERDETAILS_LEN, VAR, LLL }, }, //Reserved national
		{ 58, { ANS, MAX_VOUCHERDETAILS_LEN, VAR, LLL }, },  //Reserved national
		{ 59, { ANS, MAX_VOUCHERDETAILS_LEN, VAR, LLL }, }, //Reserved for national use
		{ 60, { ANS, MAX_VOUCHERDETAILS_LEN, VAR, LLL }, }, //Advice/reason code (private reserved)

		{ 61, { ANS, MAX_VOUCHERDETAILS_LEN, VAR, LLL }, }, //	Reserved private
		{ 62, { ANS, MAX_VOUCHERDETAILS_LEN, VAR, LLL }, }, //Reserved private
		{ 63, { ANS, MAX_VOUCHERDETAILS_LEN, VAR, LLL }, }, //Reserved private
		{ 64, { ANS, MAX_VOUCHERDETAILS_LEN, VAR, LLL }, }, //Message authentication code (MAC)

		};

FieldSet FS = { fieldS, sizeof(fieldS) / sizeof(FIELD) };

/**
 * @description: setup a specify field's attribute and it's content
 * @param: FIELD - fd the field
 * @retval: ERR_INVALID_FIELDNO - the field no is out of ranges
 * @retval: 0 - at return zero means success
 */
int setField(FIELD *fd) {
	if (fd->filedNo > FS.size - 1) {
		return ERR_INVALID_FIELDNO;
	}

	FS.fdSet[fd->filedNo - 1] = *fd;
	return 0;
}

/**
 * @description: setup a specify field's attribute by specify the field no and attribute
 * @param: filedNo - the field's no
 * @param: attr - the field's attribute
 * @retval: ERR_INVALID_FIELDNO - the field no is out of ranges
 * @retval: 0 - at return zero means success
 */
int setFieldAttr(unsigned char filedNo, FdAttr attr) {
	if (filedNo > FS.size - 1) {
		return ERR_INVALID_FIELDNO;
	}

	FS.fdSet[filedNo - 1].attr = attr;

	return 0;
}

/**
 * @description: setup a specify field's content by specify the field no and content
 * @param: filedNo - the field's no
 * @param: content - the field's content
 * @param: contentLen - the field's content's length
 * @retval: ERR_INVALID_FIELDNO - the field no is out of ranges
 * @retval: 0 - at return zero means success
 */
int setFieldContent(unsigned char filedNo, void *content,
		unsigned short contentLen) {
	if (filedNo > FS.size - 1) {
		return ERR_INVALID_FIELDNO;
	}

	if (CHECK_M(FS.fdSet[filedNo - 1].content.value)
			|| (FS.fdSet[filedNo - 1].content.length < contentLen)) {
		FS.fdSet[filedNo - 1].content.value = (unsigned char *) malloc(
				sizeof(unsigned char) * (contentLen + 2));

		if (CHECK_M(FS.fdSet[filedNo - 1].content.value)) {
			return ERR_ALOM_FAILED;
		}
	}

	memset(FS.fdSet[filedNo - 1].content.value, 0x00, (contentLen + 2));
	memcpy(FS.fdSet[filedNo - 1].content.value, content, contentLen);
	FS.fdSet[filedNo - 1].content.length = contentLen;
	return 0;
}

