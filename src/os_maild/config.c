/* @(#) $Id: ./src/os_maild/config.c, 2011/09/08 dcid Exp $
 */

/* Copyright (C) 2009 Trend Micro Inc.
 * All rights reserved.
 *
 * This program is a free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public
 * License (version 2) as published by the FSF - Free Software
 * Foundation
 */

#include "shared.h"

#include "maild.h"
#include "config/config.h"


/* MailConf v0.1: 2005/04/01
 * Reads the Mail configuration
 */
int MailConf(int test_config, char *cfgfile, MailConfig *Mail)
{
    int modules = 0;

    modules|= CMAIL;

    Mail->to = NULL;
    Mail->from = NULL;
    Mail->smtpserver = NULL;
    Mail->mn = 0;
    Mail->priority = 0;
    Mail->maxperhour = 12;
    Mail->gran_to = NULL;
    Mail->gran_id = NULL;
    Mail->gran_level = NULL;
    Mail->gran_location = NULL;
    Mail->gran_group = NULL;
    Mail->gran_set = NULL;
    Mail->gran_format = NULL;
    Mail->groupping = 1;
    Mail->strict_checking = 0;
#ifdef GEOIP
    Mail->geoip = 0;
#endif

    if(ReadConfig(modules, cfgfile, NULL, Mail) < 0)
        return(OS_INVALID);

    if(!Mail->mn)
    {
        if(!test_config)
        {
            verbose(MAIL_DIS, ARGV0);
        }
        exit(0);        
    }

    return(0);
}

/* EOF */
