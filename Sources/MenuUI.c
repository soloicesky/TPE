//
//  MenuUI.c
//  TPE
//
//  Created by Soloicesky on 8/14/14.
//  Copyright (c) 2014 Soloicesky. All rights reserved.
//
#include "StringRes.h"
#include "MenuUI.h"

int mainMenuItems[] = {
    MAIN_MENU,  //TITLE
    CHECK_LOCAL_STOCK,
    CHECK_REMOTE_STOCK,
    PRINT_PIN,
    DOWNLOAD_PIN,
    REPORT_SALE,
    RETURN_STOCK,
};

static Menu mainMenu = {
    mainMenuItems,
    sizeof(mainMenuItems)/sizeof(int)
};


