#include <string.h>

#include "ErrorNo.h"
#include "Datatypes.h"

#define SERAIALNUMBER			0
#define FACEVALUE				1
#define PINCODE					2
#define VALIDDATE				3


int decodeVoucherDeatils(char *voucherDetails, PIN_Record *PINRecord)
{
	char *p1 = NULL;	
	char *p2 = NULL;
	int lit = 0;
	
	if(voucherDetails == NULL || PINRecord == NULL)
	{
		return ERR_INVALID_ARGUMENTS;
	}

	memset(PINRecord, 0x00, sizeof(PIN_Record));
	PINRecord->status = SOLD;

	p1 = strtok(voucherDetails,"|");

	if(p1 == NULL)
	{
		return ERR_INVALID_ARGUMENTS;
	}

	while(p1!=NULL) 
	{
		switch(lit)
		{
			case SERAIALNUMBER:
				strcpy(PINRecord->pinDetails.serialNumber, p1);

				break
			case FACEVALUE:
				strcpy(PINRecord->pinDetails.faceValue, p1);

				break
			case PINCODE:
				strcpy(PINRecord->pinDetails.pinCode, p1);
			
				break
			case VALIDDATE:
				strcpy(PINRecord->pinDetails.validDate, p1);
			
				break
		}
		
		p1=strtok(NULL,"|");
		lit++;
	}

	return 0;
}

