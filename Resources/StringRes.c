#include <string.h>
 #include <stdio.h>  
 #include "StringRes.h"
 
    
const char*  ENGLISH[]={
" MAIN MENU",
"1 CHECK LOCAL STOCK",
"2 CHECK REMOTE STOCK",
"3 PRINT PIN",
"4 DOWNLOAD PIN",
"5 REPORT SALES",
"6 RETURN STOCK",
"1 XAF 500",
"2 XAF 1000",
"3 XAF 2500",
"4 XAF 5000",
"5 XAF 10000",
"6 XAF 25000",
"7 XAF 50000",
" VOUCHER",
"Enter Number of PIN",
"Voucher",
"Number",
"Press OK to confirm",
"Enter Password",
"+ OK",
"Processing",
"Sending",
"Receiving",
"OPERATION SUCCESS",
"Press OK to print",
"CANCEL for MAIN MENU",
"OPERATION FAILURE",
" REASON",
"Press OK to return to menu",
"REMOTE STOCK IS NOT",
"ENOUGH TO SATISFY",
"REQUEST",
"NUMBER ENTERED IS",
"ABOVE MAXIMUM",
"ALLOWED",
"CONNECTION ERROR",
"DURING TRANSACTION",
"AN ERROR HAPPENS",
"LOCAL STOCK",
" REMOTE STOCK",
"AUTHENTICATION ERROR",
"SELECT FACE VALUE",
"Enter Number of Voucher",
"Press F1 to add voucher",
"SALES TRANSACTION",
"SELL VOUCHER",
"TRANSACTION SUCCESS",
"Press OK",
};

static char **stringResTable = (char **) ENGLISH;

const char **strTableList[]={
 ENGLISH,
};

void setLanguage(LanguageType type)
 {
		stringResTable = (char **)strTableList[type];
}

char *getStringByID(StringResID strId)
{
		return stringResTable[strId];
}

