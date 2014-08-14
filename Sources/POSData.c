//
//  POSData.c
//  TPE
//
//  Created by Soloicesky on 8/14/14.
//  Copyright (c) 2014 Soloicesky. All rights reserved.
//
#include <string.h>
#include "POSData.h"

static TermConfigParam termConfigParam;

int setMID(char *mid)
{
    if (mid == NULL) {
        return -1;
    }
    
    memcpy(&termConfigParam.MID, mid, strlen(mid));
    return 0;
}

int setAPN(char *apn)
{
    if (apn == NULL) {
        return -1;
    }
    
    memcpy(&termConfigParam.APN , apn, strlen(apn));
    return 0;
}

int setHostIP(char *ip)
{
    if (ip == NULL) {
        return -1;
    }
    
    memcpy(&termConfigParam.host.ip , ip, strlen(ip));
    return 0;
}

void setHostPort(int port)
{
    termConfigParam.host.port = port;
}

