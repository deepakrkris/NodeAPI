/*********************************************************************/
/*                                                                   */
/*                  IBM Message Service Client for C/C++             */
/*                                                                   */
/*  FILE NAME:      helperfunctions.c                                */
/*                                                                   */
/*  DESCRIPTION:    Functions common to samples and the sample tool  */
/*                                                                   */
/*********************************************************************/
/*  <START_COPYRIGHT>                                                */
/*                                                                   */
/*  Licensed Materials - Property of IBM                             */
/*                                                                   */
/*  5724-I13                                                         */
/*                                                                   */
/*  (c) Copyright IBM Corp. 2003, 2008                               */
/*  All Rights Reserved                                              */
/*                                                                   */
/*  U.S. Government Users Restricted Rights - use,                   */
/*  duplication or disclosure restricted by GSA                      */
/*  ADP Schedule Contract with IBM Corp.                             */
/*                                                                   */
/*  Status: Version 2 Release 0                                      */
/*  <END_COPYRIGHT>                                                  */
/*                                                                   */
/*********************************************************************/
/*                                                                   */
/*  FUNCTION:       Provides functions common to samples             */
/*                                                                   */
/*  PROCESSOR:      C                                                */
/*                                                                   */
/*********************************************************************/

#include <string.h>
#include <helperfunctions.h>

/*
 * SYNOPSIS:   Populates the given parameters with
 *             values entered by the user.
 * PARAMETERS: argc - total number of arguments
 *             argv - list of arguments
 *             type - the sample type
 *             params - location to store input values
 * RETURNS:    int
 */

int getParameters(int argc, char ** argv, sampleTYPE type, InputParameters * params)
{
	int    rc                                        = XMS_OK;
	int    noIC                                      = 1;
	int    initialContextOK                          = 0;
	int    connFactOK                                = 0;
	int    destOK                                    = 0;
	char   szRequestedURI[SAMPLE_BUFFER_SIZE]        = "";
	char   pszReceiveMode[SAMPLE_BUFFER_SIZE]        = "";
	char   pszDelivMode[SAMPLE_BUFFER_SIZE]          = "";
	char   pszConnectionType[SAMPLE_BUFFER_SIZE]     = "";
	char   pszConnectionMode[SAMPLE_BUFFER_SIZE]     = "";
	char   pszDefaultURI[SAMPLE_BUFFER_SIZE]         = "";
	char   pszRunMode[SAMPLE_BUFFER_SIZE]            = "";
	char   pszHelp[2048]                             = "";
	char   responseOptions[2048]                     = "";
	char   responseFileName[SAMPLE_BUFFER_SIZE]      = "";
	char   pszPort[SAMPLE_BUFFER_SIZE]               = "";
	char   pszBrokerVersion[SAMPLE_BUFFER_SIZE]      = "";
	char   szRequestedChannel[SAMPLE_BUFFER_SIZE]    = "";	
	char   pszDefaultChannel[SAMPLE_BUFFER_SIZE]     = "";	

	FILE * responseFile                              = NULL;

	xmsHInitialContext  hInitContext                 = (xmsHInitialContext) XMS_NULL_HANDLE;
	xmsHConnFact        hConnFact                    = (xmsHConnFact) XMS_NULL_HANDLE;
	xmsHDest            hDest                        = (xmsHDest) XMS_NULL_HANDLE;
	xmsHErrorBlock      hError                       = (xmsHErrorBlock) XMS_NULL_HANDLE;
	xmsHANDLE_TYPE      hType                        = (xmsHANDLE_TYPE) 0;
	xmsINT              connType                     = 0;

	xmsErrorCreate(&hError);

	/*
	 * Display help options
	 */

	printf("\nEnter '?' for help with any question\n\n");

	/*
	 * User chooses program mode
	 */

	do
	{
		printf("Desired mode to run this sample application [simple]: ");
		fgets(pszRunMode, SAMPLE_BUFFER_SIZE, stdin);
		strcpy(responseOptions, pszRunMode);
		pszRunMode[strlen(pszRunMode) - 1] = '\0';

		strcpy(pszHelp, " - The desired mode to run this sample application. Choose 'simple' if you\n");
		strcat(pszHelp, "   prefer to specify minimal configuration settings and would like default\n");
		strcat(pszHelp, "   values for most options. Choose 'advanced' if you prefer finer control\n");
		strcat(pszHelp, "   and would like to specify value(s) of your own choice.\n");
		strcat(pszHelp, " - Valid values are: simple, or advanced\n - Default value is: simple.");
	} while (helpMessage(pszRunMode, pszHelp, (char*)"simple\0advanced\0", 2));

	/* 
	 * Then we check whether to turn on expert mode?
	 */

	if (strcmp(pszRunMode, "advanced") == 0)
	{
		params->nExpertMode = 1;
	}

    /*
	 * Get sample config output file
	 */

	if (type == sampleTOOL)
	{
		do
		{
			printf("Enter file to write administered objects to [sample.props]: ");
			fgets(params->pszFileName, SAMPLE_BUFFER_SIZE, stdin);
			strcat(responseOptions, params->pszFileName);
			params->pszFileName[strlen(params->pszFileName) - 1] = '\0';

			strcpy(pszHelp, " - The file name on file system, optionally with a path, for output.\n");
			strcat(pszHelp, "   Any existing file with the same path and name will be overwritten.\n");
			strcat(pszHelp, " - Default value is: sample.props.");
		} while (helpMessage(params->pszFileName, pszHelp, (char*)"\0", 0));

		do
		{
			printf("Enter connection factory name for initial context [sampleConnectionFactory]: ");
			fgets(params->pszICConnFact, SAMPLE_BUFFER_SIZE, stdin);
			strcat(responseOptions, params->pszICConnFact);
			params->pszICConnFact[strlen(params->pszICConnFact) - 1] = '\0';

			strcpy(pszHelp, " - The name for connection factory object in the initial context.\n");
			strcat(pszHelp, " - Default value is: sampleConnectionFactory.");
		} while (helpMessage(params->pszICConnFact, pszHelp, (char*)"\0", 0));

		do
		{
			printf("Enter destination name for initial context [sampleDestination]: ");
			fgets(params->pszICDest, SAMPLE_BUFFER_SIZE, stdin);
			strcat(responseOptions, params->pszICDest);
			params->pszICDest[strlen(params->pszICDest) - 1] = '\0';

			strcpy(pszHelp, " - The name for destination object in the initial context.\n");
			strcat(pszHelp, " - Default value is: sampleDestination.");
		} while (helpMessage(params->pszICDest, pszHelp, (char*)"\0", 0));

		/*
	     * Set defaults as neccessary
		 */

		if (strlen(params->pszICConnFact) <= 1)
			strcpy(params->pszICConnFact, "sampleConnectionFactory");

		if (strlen(params->pszICDest) <= 1)
			strcpy(params->pszICDest, "sampleDestination");
	}

	/*
	 * Check for initial context
	 */

	if ((params->nExpertMode) && (type != sampleTOOL))
	{
		/*
		 * Initial context
		 */

		do
		{
			printf("Enter administered object directory (optional): ");
			fgets(params->pszInitialContext, SAMPLE_BUFFER_SIZE, stdin);
			strcat(responseOptions, params->pszInitialContext);
			params->pszInitialContext[strlen(params->pszInitialContext) - 1] = '\0';

			strcpy(pszHelp, " - An initial context URI can be used to access administered objects.\n");
			strcat(pszHelp, "   Valid initial context prefixes are file:// and ldap://.\n");
			strcat(pszHelp, "   If no prefix is provided then file:// is assumed.");
		} while (helpMessage(params->pszInitialContext, pszHelp, (char*)"\0", 0));

		if (strlen(params->pszInitialContext) > 1)
		{
            noIC = 0;

			/*
			 * Prepend "file://" at start of initial context URI if not already present
			 */

			if (!(strstr(params->pszInitialContext, "://")))
			{
				char temp[SAMPLE_BUFFER_SIZE] = "";

				strcpy(temp, params->pszInitialContext);
				strcpy(params->pszInitialContext, "file://");
				strcat(params->pszInitialContext, temp);
			}

			/*
			 * IC connection factory?
			 */

			do
			{
				printf("Enter connection factory name for initial context [sampleConnectionFactory]: ");
				fgets(params->pszICConnFact, SAMPLE_BUFFER_SIZE, stdin);
				strcat(responseOptions, params->pszICConnFact);
				params->pszICConnFact[strlen(params->pszICConnFact) - 1] = '\0';

				strcpy(pszHelp, " - The name for connection factory object in the initial context.\n");
				strcat(pszHelp, " - Default value is: sampleConnectionFactory.");
			} while (helpMessage(params->pszICConnFact, pszHelp, (char*)"\0", 0));

			/*
			 * IC destination?
			 */

			do
			{
				printf("Enter destination name for initial context [sampleDestination]: ");
				fgets(params->pszICDest, SAMPLE_BUFFER_SIZE, stdin);
				strcat(responseOptions, params->pszICDest);
				params->pszICDest[strlen(params->pszICDest) - 1] = '\0';

				strcpy(pszHelp, " - The name for destination object in the initial context.\n");
				strcat(pszHelp, " - Default value is: sampleDestination.");
			} while (helpMessage(params->pszICDest, pszHelp, (char*)"\0", 0));

			/*
			 * Set defaults as neccessary
			 */

			if (strlen(params->pszICConnFact) <= 1)
				strcpy(params->pszICConnFact, "sampleConnectionFactory");

			if (strlen(params->pszICDest) <= 1)
				strcpy(params->pszICDest, "sampleDestination");

			/*
			 * Check IC and objects exist?
			 */

			if (xmsInitialContextCreate(params->pszInitialContext, &hInitContext, hError) == XMS_OK)
			{
                /*
                 * Lookup the connection factory object
                 */

				if (xmsInitialContextLookup(hInitContext, params->pszICConnFact, (xmsHObj *) &hConnFact, &hType, hError) == XMS_OK)
				{
                    if (xmsGetIntProperty((xmsHObj) hConnFact, XMSC_CONNECTION_TYPE, &connType, hError) == XMS_OK)
                    {
                        switch(connType)
                        {
                            case XMSC_CT_WMQ:

                                strcpy(pszConnectionType, "wmq");
                                break;

                            case XMSC_CT_RTT:

                                strcpy(pszConnectionType, "rtt");
                                break;

                            case XMSC_CT_WPM:

                                strcpy(pszConnectionType, "wpm");
                                break;

                            default:

                                strcpy(pszConnectionType, "<unknown>");
                                break;
                        }

                        if (xmsConnFactDispose(&hConnFact, hError) == XMS_OK)
                        {
					        printf("[Connection Factory \"%s\" found in \"%s\"]\n", 
						        params->pszICConnFact, params->pszInitialContext);

					        connFactOK = 1;
                        }
                        else
                        {
                            dumpError(hError);
                        }
                    }
                    else
                    {
                        dumpError(hError);
                    }
                }
                else 
                {
                    dumpError(hError);
                }

                /*
                 * Lookup the destination object
                 */

				if (xmsInitialContextLookup(hInitContext, params->pszICDest, (xmsHObj *) &hDest, &hType, hError) == XMS_OK)
				{
                    if (xmsDestDispose(&hDest, hError) == XMS_OK)
                    {
					    printf("[Destination \"%s\" found in \"%s\"]\n",
						    params->pszICDest, params->pszInitialContext);

					    destOK = 1;
                    }
                    else 
                    {
                        dumpError(hError);
                    }
				}
				else
				{
					dumpError(hError);
				}

                /*
                 * Dispose of the IC.
                 */

                if (xmsInitialContextDispose(&hInitContext, hError) == XMS_OK)
                {
                    initialContextOK = 1;
                }
                else
                {
                    dumpError(hError);
                }
			}
            else
            {
                dumpError(hError);
            }
		}
	}

	if ((initialContextOK && destOK && connFactOK) || (noIC))
	{
        if (noIC)
        {
	        /*
	         * Then ask for connection type?
	         */

	        do
	        {
		        printf("Enter connection type [wpm]: ");
		        fgets(pszConnectionType, SAMPLE_BUFFER_SIZE, stdin);
		        strcat(responseOptions, pszConnectionType);
		        pszConnectionType[strlen(pszConnectionType) - 1] = '\0';

		        strcpy(pszHelp, " - The connection type for messaging service:\n");
		        strcat(pszHelp, "   WebSphere Platform Messaging (WPM)\n");
		        strcat(pszHelp, "   or WebSphere MQ (WMQ)\n");
		        strcat(pszHelp, "   or WebSphere Business Integration Brokers using RTT transport (RTT).\n");
		        strcat(pszHelp, " - Valid values are: wpm, wmq or rtt\n - Default value is: wpm");
	        } while (helpMessage(pszConnectionType, pszHelp, (char*)"wpm\0wmq\0rtt\0", 3));

	        /*
	         * And set default if no value given?
	         */

	        if (strlen(pszConnectionType) <= 1)
	        {
		        strcpy(pszConnectionType, "wpm");
	        }
        }

		/*
		 * WPM
		 */

		if (strcmp(pszConnectionType, "wpm") == 0)
		{
			(params->nConnectionType) = XMSC_CT_WPM;
			(params->nPort)           = 7276;

			strcpy(pszDefaultURI, "topic://xms/test");

			if (!connFactOK)
			{
				/*
				 * Endpoints (WPM)
				 */

				do
				{
					printf("Enter provider endpoints [localhost:7276:BootstrapBasicMessaging]: ");
					fgets(params->pszEndpoints, SAMPLE_BUFFER_SIZE, stdin);
					strcat(responseOptions, params->pszEndpoints);
					params->pszEndpoints[strlen(params->pszEndpoints) - 1] = '\0';

					strcpy(pszHelp, " - Provider endpoints specify the connection host, port, and protocol to\n");
					strcat(pszHelp, "   use for the bootstrap process.\n");
					strcat(pszHelp, "   This is a comma separated list in the following form:\n");
					strcat(pszHelp, "     Host[:Port[:Chain]][,Host[:Port[:Chain]]]\n");
					strcat(pszHelp, "   (where square brackets imply optional)\n");
					strcat(pszHelp, "   For example, localhost:7276:BootstrapBasicMessaging\n");
					strcat(pszHelp, "   implies a bootstrap using localhost, port 7276 and TCP protocol.\n");
					strcat(pszHelp, "   Another example, localhost:7286:BootstrapSecureMessaging\n");
					strcat(pszHelp, "   implies a bootstrap using localhost, port 7286 and SSL protocol.\n");
					strcat(pszHelp, "   The order of evaluation of two or more endpoints in a list is sequential.\n");
					strcat(pszHelp, "   Note: SSL protocol requires additional client-side configuration,\n");
					strcat(pszHelp, "   HTTP protocol requires additional server-side configuration,\n");
					strcat(pszHelp, "   HTTPS protocol requires additional client- and server-side configuration.\n");
					strcat(pszHelp, " - Default value is: localhost:7276:BootstrapBasicMessaging.");
				} while (helpMessage(params->pszEndpoints, pszHelp, (char*)"\0", 0));

				/*
				 * TargetChain (WPM)
				 */

				do
				{
					printf("Enter target transport chain [InboundBasicMessaging]: ");
					fgets(params->pszTargetChain, SAMPLE_BUFFER_SIZE, stdin);
					strcat(responseOptions, params->pszTargetChain);
					params->pszTargetChain[strlen(params->pszTargetChain) - 1] = '\0';

					strcpy(pszHelp, " - The connection protocol to use for final connection after the bootstrap\n");
					strcat(pszHelp, "   process. The bootstrap and final connection protocols may be same or\n");
					strcat(pszHelp, "   different.\n");
					strcat(pszHelp, "   For example, InboundBasicMessaging implies a desired final\n");
					strcat(pszHelp, "   connection using TCP protocol.\n");
					strcat(pszHelp, "   Another example, InboundSecureMessaging implies a desired final\n");
					strcat(pszHelp, "   connection using SSL protocol.\n");
					strcat(pszHelp, "   Note: SSL protocol requires additional client-side configuration,\n");
					strcat(pszHelp, "   HTTP protocol requires additional server-side configuration,\n");
					strcat(pszHelp, "   HTTPS protocol requires additional client- and server-side configuration.\n");
					strcat(pszHelp, " - Default value is: InboundBasicMessaging.");
				} while (helpMessage(params->pszTargetChain, pszHelp, (char*)"\0", 0));

				/*
				 * Bus name (WPM - mandatory)
				 */

				while (strlen(params->pszBusName) < 1)
				{
					do
					{
						printf("Enter bus name (mandatory): ");
						fgets(params->pszBusName, SAMPLE_BUFFER_SIZE, stdin);
						strcat(responseOptions, params->pszBusName);
						params->pszBusName[strlen(params->pszBusName) - 1] = '\0';

						strcpy(pszHelp, "- The name of the messaging bus to connect to.");
					} while (helpMessage(params->pszBusName, pszHelp, (char*)"\0", 0));

					if (strlen(params->pszBusName) < 1)
						printf(" - A value must be specified for this option\n\n");
				}
			}
		}

		/*
		 * RTT
		 */

		else if (strcmp(pszConnectionType, "rtt") == 0)
		{
			(params->nConnectionType) = XMSC_CT_RTT;
			(params->nConnectionMode) = XMSC_RTT_CP_TCP;
			(params->nPort)           = 1506;

			strcpy(pszDefaultURI, "topic://xms/test");

			if (!connFactOK)
			{
				/*
				 * Hostname (RTT)
				 */

				do
				{
					printf("Enter hostname [localhost]: ");
					fgets(params->pszHostname, SAMPLE_BUFFER_SIZE, stdin);
					strcat(responseOptions, params->pszHostname);
					params->pszHostname[strlen(params->pszHostname) - 1] = '\0';

					strcpy(pszHelp, " - The name of the computer on the network providing messaging service\n");
					strcat(pszHelp, "   or its IPv4 address.\n");
					strcat(pszHelp, " - Default value is: localhost.");
				} while (helpMessage(params->pszHostname, pszHelp, (char*)"\0", 0));

				/*
				 * Port (RTT)
				 */

				do
				{
					printf("Enter port [1506]: ");
					fgets(pszPort, SAMPLE_BUFFER_SIZE, stdin);
					strcat(responseOptions, pszPort);

					strcpy(pszHelp, " - The port number for messaging service using desired transport.\n");
					strcat(pszHelp, "   Valid range is 0 to 65535 (both inclusive).\n");
					strcat(pszHelp, " - Default value is: 1506.");
				} while (helpMessage(pszPort, pszHelp, (char*)"\0", 0));

				if (strlen(pszPort) > 1)
					(params->nPort) = atoi(pszPort);
			}
		}

		/*
		 * WMQ
		 */

		else if (strcmp(pszConnectionType, "wmq") == 0)
		{
			(params->nConnectionType) = XMSC_CT_WMQ;
			(params->nPort)           = 1414;

			strcpy(pszDefaultURI, "queue:///SYSTEM.DEFAULT.LOCAL.QUEUE");
			strcpy(pszDefaultChannel, "SYSTEM.DEF.SVRCONN");	

			if (!connFactOK)
			{
				/*
				 * Client/server bindings (WMQ)
				 */

				do
				{
					printf("Enter connection mode [client]: ");
					fgets(pszConnectionMode, SAMPLE_BUFFER_SIZE, stdin);
					strcat(responseOptions, pszConnectionMode);
					pszConnectionMode[strlen(pszConnectionMode) - 1] = '\0';

					strcpy(pszHelp, " - The Websphere MQ connection mode to use\n");
					strcat(pszHelp, "   Valid values are: client, or bindings\n");
					strcat(pszHelp, " - Default value is: client.");
				} while (helpMessage(pszConnectionMode, pszHelp, (char*)"client\0bindings\0", 2));

				if ((strlen(pszConnectionMode) > 1) && (strcmp(pszConnectionMode, "client") == 0))
					params->nConnectionMode = XMSC_WMQ_CM_CLIENT;
				else if ((strlen(pszConnectionMode) > 1) && (strcmp(pszConnectionMode, "bindings") == 0))
					params->nConnectionMode = XMSC_WMQ_CM_BINDINGS;
				else
					params->nConnectionMode	= XMSC_WMQ_CM_CLIENT;

				/*
				 * Connection QMgr (WMQ)
				 */

				do
				{
					/*
					 * Although there is a default QMgr value, if the default is not
					 * set up on the system, this may cause more problems than it solves.
					 * Hence we prompt the user for one.
					 */

					printf("Enter connection queue manager (optional): ");
					fgets(params->pszWMQQMgr, SAMPLE_BUFFER_SIZE, stdin);
					strcat(responseOptions, params->pszWMQQMgr);
					params->pszWMQQMgr[strlen(params->pszWMQQMgr) - 1] = '\0';

					strcpy(pszHelp, " - The name of the WMQ queue manager to connect to.\n");
					strcat(pszHelp, "   If no queue manager is specified, then the default queue\n");
					strcat(pszHelp, "   manager for the WMQ server is used, if defined, otherwise\n");
					strcat(pszHelp, "   the connection will fail.\n");
				} while (helpMessage(params->pszWMQQMgr, pszHelp, (char*)"\0", 0));

				if ((params->nConnectionMode) == XMSC_WMQ_CM_CLIENT)
				{
					/*
					 * Hostname (WMQ)
					 */

					do
					{
						printf("Enter hostname [localhost]: ");
						fgets(params->pszHostname, SAMPLE_BUFFER_SIZE, stdin);
						strcat(responseOptions, params->pszHostname);
						params->pszHostname[strlen(params->pszHostname) - 1] = '\0';

						strcpy(pszHelp, " - The name of the computer on the network providing messaging service\n");
						strcat(pszHelp, "   or its IPv4 address.\n");
						strcat(pszHelp, " - Default value is: localhost.");
					} while (helpMessage(params->pszHostname, pszHelp, (char*)"\0", 0));

					/*
					 * Port  and Channel(WMQ)
					 */

					strcpy(params->pszChannel, pszDefaultChannel);
					if (params->nExpertMode)
					{
						do
						{
							printf("Enter port [1414]: ");
							fgets(pszPort, SAMPLE_BUFFER_SIZE, stdin);
							strcat(responseOptions, pszPort);

							strcpy(pszHelp, " - The port number for messaging service using desired transport.\n");
							strcat(pszHelp, "   Valid range is 0 to 65535 (both inclusive).\n");
							strcat(pszHelp, " - Default value is: 1414.");
						} while (helpMessage(pszPort, pszHelp, (char*)"\0", 0));

						if (strlen(pszPort) > 1)
							(params->nPort) = atoi(pszPort);
						do
						{
							printf("Enter channel [%s]: ",pszDefaultChannel);
							strcpy(pszHelp, " - The channel to use. A WebSphere MQ channel is a logical communication.\n");
							strcat(pszHelp, " link between a WebSphere MQ client and a WebSphere MQ queue manager \n");
							strcat(pszHelp, "(MQI channels), or between two queue managers (message channels).\n");
							strcat(pszHelp, " - Default value is: ");
							strcat(pszHelp, pszDefaultChannel);
							fgets(szRequestedChannel, SAMPLE_BUFFER_SIZE, stdin); 
							strcat(responseOptions, szRequestedChannel);
							szRequestedChannel[strlen(szRequestedChannel) - 1] = '\0';
							if (strlen(szRequestedChannel) > 0)
							{
								strcpy(params->pszChannel, szRequestedChannel);
							}
                                                        
						} while (helpMessage(szRequestedChannel, pszHelp, (char*)"\0", 0));

					}
				}
			}
		}
		else
		{
			printf("\n\nERROR: Invalid connection type '%s'\n\n", pszConnectionType);

			return(1);
		}

		/*
		 * Destination
		 */

		strcpy(params->pszDestURI, pszDefaultURI);

		if (!destOK)
		{
			do
			{
				if ((params->nConnectionType) == XMSC_CT_RTT)
				{
					printf("Enter destination topic [%s]: ", pszDefaultURI);
					strcpy(pszHelp, " - A topic for publish/subscribe messaging. Destination must have the\n");
					strcat(pszHelp, "   topic:// prefix.\n");
					strcat(pszHelp, " - Default value is: ");
					strcat(pszHelp, pszDefaultURI);
				}
				else if ((params->nConnectionType) == XMSC_CT_WPM)
				{
					printf("Enter destination URI [%s]: ", pszDefaultURI);
					strcpy(pszHelp, " - A queue for point-to-point messaging or topic for publish/subscribe\n");
					strcat(pszHelp, "   messaging. Destination is a logical address on bus. Destination\n");
					strcat(pszHelp, "   must have either queue:// or topic:// prefix.\n");
					strcat(pszHelp, " - Default value is: ");
					strcat(pszHelp, pszDefaultURI);
				}
				else if ((params->nConnectionType) == XMSC_CT_WMQ)
				{
					printf("Enter destination URI [%s]: ", pszDefaultURI);
					strcpy(pszHelp, " - A queue for point-to-point messaging or topic for publish/subscribe\n");
					strcat(pszHelp, "   messaging. Destination must have either queue:// or topic:// prefix.\n");
					strcat(pszHelp, " - Default value is: ");
					strcat(pszHelp, pszDefaultURI);
				}

				fgets(szRequestedURI, SAMPLE_BUFFER_SIZE, stdin);
				strcat(responseOptions, szRequestedURI);
				szRequestedURI[strlen(szRequestedURI) - 1] = '\0';

				if (strlen(szRequestedURI) > 0)
				{
					strcpy(params->pszDestURI, szRequestedURI);
				}
			} while (helpMessage(szRequestedURI, pszHelp, (char*)"\0", 0));

			if ((params->nConnectionType == XMSC_CT_WMQ)
			&& (strncmp(params->pszDestURI, "topic://", 8) == 0))
			{
				/*
				 * WMQ Broker Version?
				 */

				do
				{
					printf("Enter broker version [broker]: ");
					fgets(pszBrokerVersion, SAMPLE_BUFFER_SIZE, stdin);
					strcat(responseOptions, pszBrokerVersion);
					pszBrokerVersion[strlen(pszBrokerVersion) - 1] = '\0';

					strcpy(pszHelp, " - The broker version describes which type of broker is being used.\n");
					strcat(pszHelp, "   Valid values are: broker, or integrator which implies the use of either\n");
					strcat(pszHelp, "   the WMQ publish/subscribe broker or the WMQ Integrator broker.\n");
					strcat(pszHelp, " - Default value is: broker.");
				} while (helpMessage(pszBrokerVersion, pszHelp, (char*)"broker\0integrator\0", 2));

				if (strcmp(pszBrokerVersion, "broker") == 0)
					params->nWMQBrokerVersion = 0;
				else if (strcmp(pszBrokerVersion, "integrator") == 0)
					params->nWMQBrokerVersion = 1;
				else
					params->nWMQBrokerVersion = 0;

				/*
				 * WMQ Publish Queue Name (mandatory in producer & integrator only)
				 */

				if ((params->nWMQBrokerVersion == 1) 
					&& ((type == sampleTOOL) || (type == samplePROD)))
				{
					while (strlen(params->pszWMQPubQ) < 1)
					{
						do
						{
							printf("Enter publish queue name (mandatory): ");
							fgets(params->pszWMQPubQ, SAMPLE_BUFFER_SIZE, stdin);
							strcat(responseOptions, params->pszWMQPubQ);
							params->pszWMQPubQ[strlen(params->pszWMQPubQ) - 1] = '\0';

							strcpy(pszHelp, "- The name of the input queue for publishing messages.");
						} while (helpMessage(params->pszWMQPubQ, pszHelp, (char*)"\0", 0));

						if (strlen(params->pszWMQPubQ) < 1)
							printf(" - A value must be specified for this option\n\n");
					}
				}
			}
		}

		if (params->nExpertMode)
		{
			if (!connFactOK)
			{
				/*
				 * This check stops RTT samples asking for user/password
				 */

				if (((type != sampleTOOL) || (params->nConnectionType == XMSC_CT_WPM)))
				{
					/*
					 * User id
					 */

					do
					{
						printf("Enter user (optional): ");
						fgets(params->pszUserID, SAMPLE_BUFFER_SIZE, stdin);
						strcat(responseOptions, params->pszUserID);
						params->pszUserID[strlen(params->pszUserID) - 1] = '\0';

						strcpy(pszHelp, " - The user id, if security is enabled.");
					} while (helpMessage(params->pszUserID, pszHelp, (char*)"\0", 0));

					/*
					 * Password
					 */

					if (strlen(params->pszUserID) > 1)
					{
						do
						{
							printf("Enter password (optional): ");
							fgets(params->pszPassword, SAMPLE_BUFFER_SIZE, stdin);
							strcat(responseOptions, params->pszPassword);
							params->pszPassword[strlen(params->pszPassword) - 1] = '\0'; 

							strcpy(pszHelp, " - The password for user id, if security is enabled.");
						} while (helpMessage(params->pszPassword, pszHelp, (char*)"\0", 0));
					}
				}
			}
		}

		if (type == sampleCONS)
		{
			/*
			 * Receive mode
			 */

			if (params->nExpertMode)
			{
				do
				{
					printf("Enter receive mode [async]: ");
					fgets(pszReceiveMode, SAMPLE_BUFFER_SIZE, stdin);
					strcat(responseOptions, pszReceiveMode);
					pszReceiveMode[strlen(pszReceiveMode) - 1] = '\0';

					strcpy(pszHelp, " - Synchronously or asynchronously receive message(s).\n");
					strcat(pszHelp, "   Synchronous mode will poll the server for messages\n");
					strcat(pszHelp, "   Asynchronous will receive messages as they become available\n");
					strcat(pszHelp, " - Valid values are: sync or async.\n");
					strcat(pszHelp, " - Default value is: async.");
				} while (helpMessage(pszReceiveMode, pszHelp, (char*)"async\0sync\0", 2));

				if (strlen(pszReceiveMode) <= 1)
					strcpy(pszReceiveMode, "async");

				/*
				 * SQL selector statement
				 */

				do
				{
					printf("Enter SQL selector statement (optional): ");
					fgets(params->pszSelector, SAMPLE_BUFFER_SIZE, stdin);
					strcat(responseOptions, params->pszSelector);
					params->pszSelector[strlen(params->pszSelector) - 1] = '\0';

					strcpy(pszHelp, " - Selector expression that must be matched for messages passed to\n");
					strcat(pszHelp, "   this Consumer by any Destination to which the Consumer attaches.");
				} while (helpMessage(params->pszSelector, pszHelp, (char*)"\0", 0));
			}

			if (params->nConnectionType == XMSC_CT_WPM)
			{
				/*
				 * Multicast mode (WPM) - currently disabled
				 */

				/*
				do
				{
				    printf("Enter multicast mode [uni-and-multicast]: ");
				    fgets(params->pszMulticast, SAMPLE_BUFFER_SIZE, stdin);
				    strcat(responseOptions, params->pszMulticast);
				    params->pszMulticast[strlen(params->pszMulticast) - 1] = '\0';
		
				    strcpy(pszHelp, " - Selects the IP transmission modes you will allow the server to use when\n");
				    strcat(pszHelp, "   receiving messages (if available).\n");
				    strcat(pszHelp, "   Note: Multicast messaging requires additional configuration on the server.\n");
				    strcat(pszHelp, " - Valid values are: unicast, multicast, or uni-and-multicast.\n");
				    strcat(pszHelp, " - Default value is: unicast.");
				} while (helpMessage(params->pszMulticast, pszHelp, (char*)"unicast\0multicast\0uni-and-multicast\0", 3));
				*/
			}
		}

		if ((type == sampleCONS) || (type == sampleTOOL))
		{
			if ((params->nExpertMode) && (params->nConnectionType == XMSC_CT_RTT))
			{
				if (!connFactOK)
				{
					/*
					 * Multicast mode (RTT)
					 */

					do
					{
						printf("Enter multicast mode [disabled]: ");
						fgets(params->pszMulticast, SAMPLE_BUFFER_SIZE, stdin);
						strcat(responseOptions, params->pszMulticast);
						params->pszMulticast[strlen(params->pszMulticast) - 1] = '\0';

						strcpy(pszHelp, " - Selects the IP transmission modes you will allow the server to use when\n");
						strcat(pszHelp, "   receiving messages (if available).\n");
						strcat(pszHelp, "   Note: Multicast messaging requires additional configuration on the server.\n");
						strcat(pszHelp, " - Valid values are: disabled, enabled, non-reliable, or reliable.\n");
						strcat(pszHelp, " - Default value is: disabled.");
					} while (helpMessage(params->pszMulticast, pszHelp, (char*)"disabled\0enabled\0non-reliable\0reliable\0", 4));
				}
			}
		}

		if ((type == samplePROD) || (type == sampleTOOL))
		{
			/*
			 * Delivery mode
			 */

			if (params->nExpertMode)
			{
				if ((params->nConnectionType != XMSC_CT_RTT) && (!destOK))
				{
					do
					{
						printf("Enter delivery mode [not-persistent]: ");
						fgets(pszDelivMode, SAMPLE_BUFFER_SIZE, stdin);
						strcat(responseOptions, pszDelivMode);
						pszDelivMode[strlen(pszDelivMode) - 1] = '\0';

						strcpy(pszHelp, " - The delivery mode for the messages.\n");
						strcat(pszHelp, "   Persistent messages are guaranteed to be delivered exactly once.\n");
						strcat(pszHelp, "   Non-persistent messages are guaranteed to be delivered at most once.\n");
						strcat(pszHelp, " - Valid values are: as-app, as-dest, non-persistent, or persistent.\n");
						strcat(pszHelp, " - Default value is: non-persistent.");
					} while (helpMessage(pszDelivMode, pszHelp, (char*)"as-app\0as-dest\0non-persistent\0persistent\0", 4));
				}

				/*
				 * Message type
				 */

				if (type != sampleTOOL)
				{
					do
					{
						printf("Enter message type [text]: ");
						fgets(params->pszMsgType, SAMPLE_BUFFER_SIZE, stdin);
						strcat(responseOptions, params->pszMsgType);
						params->pszMsgType[strlen(params->pszMsgType) - 1] = '\0';

						strcpy(pszHelp, " - The type of message(s) to send or receive.\n");
						strcat(pszHelp, " - Valid values are: base, bytes, map, object, stream, or text.\n");
						strcat(pszHelp, " - Default value is: text.");
					} while (helpMessage(params->pszMsgType, pszHelp, (char*)"base\0bytes\0map\0object\0stream\0text\0", 6));
				}
			}
		}

		if (type == samplePROD)
		{
			do
			{
				printf("Your message (optional): ");
				fgets(params->pszCustomMessage, CUSTOM_MESSAGE_MAX, stdin);
				strcat(responseOptions, params->pszCustomMessage);
				params->pszCustomMessage[strlen(params->pszCustomMessage) - 1] = '\0';

				strcpy(pszHelp, " - Your message. If no message text is provided,\n");
				strcat(pszHelp, "   then the application alternates between two pre-defined messages.\n");
			} while (helpMessage(params->pszCustomMessage, pszHelp, (char*)"\0", 0));
		}

		/*
		 * Number of messages
		 */

		if (params->nExpertMode && (type != sampleTOOL))
		{
			/*
			 * Don't ask for number of messages if running asynchronously on WMQ
			 */

			if (!((strcmp(pszReceiveMode,"async") == 0) && (params->nConnectionType == XMSC_CT_WMQ)))
			{
				do
				{
					printf("Enter number of messages [infinite]: ");
					fgets(params->pszMessageCount, SAMPLE_BUFFER_SIZE, stdin);
					strcat(responseOptions, params->pszMessageCount);
					params->pszMessageCount[strlen(params->pszMessageCount) - 1] = '\0';

					strcpy(pszHelp, " - The number of messages to send or receive.\n");
					strcat(pszHelp, "   Valid range is 0 to 2147483647 (both inclusive).\n");
					strcat(pszHelp, " - Default value is: infinite.");
				} while (helpMessage(params->pszMessageCount, pszHelp, (char*)"\0", 0));
			}

			/*
			 * And interval
			 */

			do
			{
				printf("Enter interval between messages in seconds [1]: ");
				fgets(params->pszInterval, SAMPLE_BUFFER_SIZE, stdin);
				strcat(responseOptions, params->pszInterval);
				params->pszInterval[strlen(params->pszInterval) - 1] = '\0';

				strcpy(pszHelp, " - The interval in seconds between sending or receiving messages.\n");
				strcat(pszHelp, "   Valid range is 0 to 2147483647 (both inclusive).\n");
				strcat(pszHelp, " - Default value is: 1.");
			} while (helpMessage(params->pszInterval, pszHelp, (char*)"\0", 0));
		}

		/*
		 * Set defaults if values not given
		 */

		if (strlen(params->pszHostname) <= 1)
			strcpy(params->pszHostname, "localhost");

		if (strlen(params->pszEndpoints) <= 1)
			strcpy(params->pszEndpoints, "localhost:7276:BootstrapBasicMessaging");

		if (strlen(params->pszTargetChain) <= 1)
			strcpy(params->pszTargetChain, "InboundBasicMessaging");

		if (strlen(params->pszDestURI) <= 1)
			strcpy(params->pszDestURI, pszDefaultURI);

		if (strlen(params->pszFileName) <= 1)
			strcpy(params->pszFileName, "sample.props");

		if (strlen(params->pszICConnFact) <= 1)
			strcpy(params->pszICConnFact, "sampleConnectionFactory");

		if (strlen(params->pszICDest) <= 1)
			strcpy(params->pszICDest, "sampleDestination");

		if (strlen(params->pszInterval) >= 1)
			(params->nInterval) = atoi(params->pszInterval);
		else
			(params->nInterval)	= 1;

		if (strlen(params->pszChannel) <= 1)
			strcpy(params->pszChannel, pszDefaultChannel);

		/*
		 * Set to -1 to signify infinite messages
		 */

		if (strlen(params->pszMessageCount) >= 1)
			(params->nMessageCount) = atoi(params->pszMessageCount);
		else
			(params->nMessageCount)	= -1;

		if (strcmp(pszDelivMode, "as-app") == 0)
			(params->nDeliveryMode) = XMSC_DELIVERY_AS_APP;
		else if (strcmp(pszDelivMode, "as-dest") == 0)
			(params->nDeliveryMode) = XMSC_DELIVERY_AS_DEST;
		else if (strcmp(pszDelivMode, "persistent") == 0)
			(params->nDeliveryMode) = XMSC_DELIVERY_PERSISTENT;
		else
			(params->nDeliveryMode)	= XMSC_DELIVERY_NOT_PERSISTENT;

		if (params->nConnectionType == XMSC_CT_RTT)
		{
			if (strcmp(params->pszMulticast, "enabled") == 0)
				(params->nMulticast) = XMSC_RTT_MULTICAST_ENABLED;
			else if (strcmp(params->pszMulticast, "disabled") == 0)
				(params->nMulticast) = XMSC_RTT_MULTICAST_DISABLED;
			else if (strcmp(params->pszMulticast, "reliable") == 0)
				(params->nMulticast) = XMSC_RTT_MULTICAST_RELIABLE;
			else if (strcmp(params->pszMulticast, "not-reliable") == 0)
				(params->nMulticast) = XMSC_RTT_MULTICAST_NOT_RELIABLE;
			else
				(params->nMulticast) = XMSC_RTT_MULTICAST_DISABLED;
		}
		else if (params->nConnectionType == XMSC_CT_WPM)
		{
			/* WPM multicast is currently disabled
			if (strcmp(params->pszMulticast, "unicast") == 0)
			    (params->nMulticast) = XMSC_WPM_UNICAST_ONLY;
			else if (strcmp(params->pszMulticast, "multicast") == 0)
			    (params->nMulticast) = XMSC_WPM_MULTICAST_ONLY;
			else if (strcmp(params->pszMulticast, "uni-and-multicast") == 0)
			    (params->nMulticast) = XMSC_WPM_UNICAST_AND_MULTICAST;
			else
			*/
			(params->nMulticast) = XMSC_WPM_UNICAST_ONLY;
		}

		if (strcmp(params->pszMsgType, "base") == 0)
			params->msgType = XMS_MESSAGE_TYPE_BASE;
		else if (strcmp(params->pszMsgType, "bytes") == 0)
			params->msgType = XMS_MESSAGE_TYPE_BYTES;
		else if (strcmp(params->pszMsgType, "map") == 0)
			params->msgType = XMS_MESSAGE_TYPE_MAP;
		else if (strcmp(params->pszMsgType, "object") == 0)
			params->msgType = XMS_MESSAGE_TYPE_OBJECT;
		else if (strcmp(params->pszMsgType, "stream") == 0)
			params->msgType = XMS_MESSAGE_TYPE_STREAM;
		else
			params->msgType	= XMS_MESSAGE_TYPE_TEXT;

		if (strcmp(pszReceiveMode, "sync") == 0)
			params->bSynchronous = xmsTRUE;
		else
			params->bSynchronous = xmsFALSE;

		/*
		 * Open response file to write question responses to
		 */

		if (params->nConnectionType == XMSC_CT_RTT)
			strcpy(responseFileName, "rtt-");
		else if (params->nConnectionType == XMSC_CT_WMQ)
			strcpy(responseFileName, "wmq-");
		else if (params->nConnectionType == XMSC_CT_WPM)
			strcpy(responseFileName, "wpm-");

		if (type == sampleCONS)
			strcat(responseFileName, "consumer.rsp");
		else if (type == samplePROD)
			strcat(responseFileName, "producer.rsp");
		else if (type == sampleTOOL)
			strcat(responseFileName, "config.rsp");

		responseFile = fopen(responseFileName, "w");

		if (responseFile == NULL)
			printf("\nERROR: Unable to write response file \"%s\"\n", responseFileName);
		else
		{
			fprintf(responseFile, "%s", responseOptions);
			fclose(responseFile);
		}
	}
	else
	{
		/*
		 * If initial context lookup fails
		 */

		rc = ~(XMS_OK);
	}

    /*
     * Dispose of the error block
     */

    xmsErrorDispose(&hError);

	return(rc);
}

/*
 * SYNOPSIS:   Displays the usage help for a particular question
 * PARAMETERS: lpInput - input from user to check for '?'
 *             pszMessage - message for question
 * RETURNS:    xmsINT
 */

xmsINT helpMessage(xmsCHAR * lpInput, 
	xmsCHAR * pszMessage, xmsCHAR * validResponses, xmsINT nValidResponses)
{
	xmsINT  i             = 0;
	xmsRC   rc            = XMS_OK;
	xmsBOOL responseValid = xmsFALSE;

	if (lpInput[0] == '?')
	{
		printf("%s\n\n", pszMessage);

		rc = 1;
	}
	else
	{
		if ((nValidResponses == -1) && (strlen(lpInput) == 0))
		{
			/*
			 * -1 signals that this question is non-optional,
			 * but doesn't have any specific acceptable values,
			 * so just check they have entered something
			 */

			printf(" - Incorrect value for this option\n");
			printf("%s\n\n", pszMessage);

			rc = 1;
		}
		else if (((nValidResponses == 0) || (strlen(lpInput) <= 1))
			|| (nValidResponses == -1 && (strlen(lpInput) > 0)))
		{
			/*
			 * 0 signals that this question is optional
			 */

			responseValid = xmsTRUE;
		}
		else
		{
			for (i = 0; i < nValidResponses; i++)
			{
				if (strcmp(lpInput, validResponses) == 0)
				{
					responseValid = xmsTRUE;
					i = nValidResponses;
				}
				else
				{
					validResponses = validResponses + strlen(validResponses) + sizeof(xmsCHAR);
				}
			}

			if (!responseValid)
			{
				printf(" - Incorrect value for this option\n");
				printf("%s\n\n", pszMessage);

				rc = 1;
			}
		}
	}

	return(rc);
}

/*
 * SYNOPSIS:    Resets/Initialises InputParameter values
 * PARAMETERS:  InputParameters * lpInput
 * RETURNS:     xmsVOID
 */

xmsVOID resetParameters(InputParameters * lpInput)
{
	lpInput->pszInitialContext = (char *) calloc(SAMPLE_BUFFER_SIZE, sizeof(char));
	lpInput->pszICConnFact     = (char *) calloc(SAMPLE_BUFFER_SIZE, sizeof(char));
	lpInput->pszICDest         = (char *) calloc(SAMPLE_BUFFER_SIZE, sizeof(char));
	lpInput->pszInterval       = (char *) calloc(SAMPLE_BUFFER_SIZE, sizeof(char));
	lpInput->pszMessageCount   = (char *) calloc(SAMPLE_BUFFER_SIZE, sizeof(char));
	lpInput->pszMsgType        = (char *) calloc(SAMPLE_BUFFER_SIZE, sizeof(char));
	lpInput->pszReceive        = (char *) calloc(SAMPLE_BUFFER_SIZE, sizeof(char));
	lpInput->pszMulticast      = (char *) calloc(SAMPLE_BUFFER_SIZE, sizeof(char));
	lpInput->pszHostname       = (char *) calloc(SAMPLE_BUFFER_SIZE, sizeof(char));
	lpInput->pszEndpoints      = (char *) calloc(SAMPLE_BUFFER_SIZE, sizeof(char));
	lpInput->pszTargetChain    = (char *) calloc(SAMPLE_BUFFER_SIZE, sizeof(char));
	lpInput->pszBusName        = (char *) calloc(SAMPLE_BUFFER_SIZE, sizeof(char));
	lpInput->pszDestURI        = (char *) calloc(SAMPLE_BUFFER_SIZE, sizeof(char));
	lpInput->pszUserID         = (char *) calloc(SAMPLE_BUFFER_SIZE, sizeof(char));
	lpInput->pszPassword       = (char *) calloc(SAMPLE_BUFFER_SIZE, sizeof(char));
	lpInput->pszSelector       = (char *) calloc(SAMPLE_BUFFER_SIZE, sizeof(char));
	lpInput->pszConnFactQM     = (char *) calloc(SAMPLE_BUFFER_SIZE, sizeof(char));
	lpInput->pszFileName       = (char *) calloc(SAMPLE_BUFFER_SIZE, sizeof(char));
	lpInput->pszCustomMessage  = (char *) calloc(CUSTOM_MESSAGE_MAX, sizeof(char));
	lpInput->pszWMQQMgr        = (char *) calloc(CUSTOM_MESSAGE_MAX, sizeof(char));
	lpInput->pszWMQPubQ        = (char *) calloc(CUSTOM_MESSAGE_MAX, sizeof(char));
	lpInput->pszChannel        = (char *) calloc(SAMPLE_BUFFER_SIZE, sizeof(char));	
	lpInput->nInterval         = 0;
	lpInput->nMessageCount     = 0;
	lpInput->nMulticast        = 0;
	lpInput->nConnectionType   = 0;
	lpInput->nConnectionMode   = 0;
	lpInput->nExpertMode       = 0;
	lpInput->nWMQBrokerVersion = 0;
	lpInput->bSynchronous      = xmsFALSE;
}

/*
 * SYNOPSIS:    Frees allocated memory in InputParameter struct
 * PARAMETERS:  InputParameters * lpInput
 * RETURNS:     xmsVOID
 */

xmsVOID freeParameters(InputParameters * lpInput)
{
	free(lpInput->pszInitialContext);
	free(lpInput->pszICConnFact);
	free(lpInput->pszICDest);
	free(lpInput->pszInterval);
	free(lpInput->pszMessageCount);
	free(lpInput->pszCustomMessage);
	free(lpInput->pszMsgType);
	free(lpInput->pszReceive);
	free(lpInput->pszMulticast);
	free(lpInput->pszHostname);
	free(lpInput->pszEndpoints);
	free(lpInput->pszTargetChain);
	free(lpInput->pszBusName);
	free(lpInput->pszDestURI);
	free(lpInput->pszUserID);
	free(lpInput->pszPassword);
	free(lpInput->pszSelector);
	free(lpInput->pszConnFactQM);
	free(lpInput->pszWMQQMgr);
	free(lpInput->pszWMQPubQ);
	free(lpInput->pszChannel);
	free(lpInput->pszFileName);
}

/*
 * SYNOPSIS:   Asynchronous user defined exception callback function
 * PARAMETERS: lpContext - user defined context associated with this callback
 *             hError - handle to the associated error
 * RETURNS:    xmsVOID
 */

xmsVOID callbackException(xmsCONTEXT lpContext, xmsHErrorBlock hInfo)
{
	printf("Exception received:\n");

	dumpError(hInfo);
}

/*
 * SYNOPSIS:   Dumps the specified error contents to stdout
 * PARAMETERS: hError - handle to the XMS error block
 * RETURNS:    xmsVOID
 */

xmsVOID dumpError(xmsHErrorBlock hError)
{
	xmsCHAR        szText[100]  = { '\0'};
	xmsINT         cbTextSize   = sizeof(szText) / sizeof(xmsCHAR);
	xmsCHAR        szData[1000] = { '\0'};
	xmsINT         cbDataSize   = sizeof(szData) / sizeof(xmsCHAR);
	xmsINT         cbActualSize = 0;
	xmsINT         nReason      = XMS_E_NONE;
	xmsJMSEXP_TYPE jmsexception = XMS_X_NO_EXCEPTION;

	if (hError != NULL)
	{
		xmsHErrorBlock xmsLinkedError = (xmsHErrorBlock) XMS_NULL_HANDLE;

		xmsErrorGetJMSException(hError, &jmsexception);
		xmsErrorGetErrorCode(hError, &nReason);
		xmsErrorGetErrorString(hError, szText, cbTextSize, &cbActualSize);
		xmsErrorGetErrorData(hError, szData, cbDataSize, &cbActualSize);

		printf("Error Block:\n");
		printf("  -> JMSException = %d (%s)\n", jmsexception, getExceptionTypeString(jmsexception));
		printf("  -> Error Code   = %d (%s)\n", nReason, szText);
		printf("  -> Error Data   = %s\n\n", szData);

		/*
		 * Get the next linked error, and act recursively
		 */

		xmsErrorGetLinkedError(hError, &xmsLinkedError);
		
        dumpError(xmsLinkedError);
	}
}

/*
 * SYNOPSIS:   Returns the character string value for specified JMS type exception.
 * PARAMETERS: exceptionType - JMS exception type
 * RETURNS:    xmsCHAR *
 */

xmsCHAR * getExceptionTypeString(xmsJMSEXP_TYPE exceptionType)
{
	xmsCHAR *  pszExceptionType = NULL;

	switch (exceptionType)
	{
		case XMS_X_NO_EXCEPTION:

			pszExceptionType = (xmsCHAR *) "XMS_JMSEXP_TYPE_NONE";
			break;

		case XMS_X_GENERAL_EXCEPTION:

			pszExceptionType = (xmsCHAR *) "XMS_JMSEXP_TYPE_GENERALEXCEPTION";
			break;

		case XMS_X_ILLEGAL_STATE_EXCEPTION:

			pszExceptionType = (xmsCHAR *) "XMS_JMSEXP_TYPE_ILLEGALSTATEEXCEPTION";
			break;

		case XMS_X_INVALID_CLIENTID_EXCEPTION:

			pszExceptionType = (xmsCHAR *) "XMS_JMSEXP_TYPE_INVALIDCLIENTIDEXCEPTION";
			break;

		case XMS_X_INVALID_DESTINATION_EXCEPTION:

			pszExceptionType = (xmsCHAR *) "XMS_JMSEXP_TYPE_INVALIDDESTINATIONEXCEPTION";
			break;

		case XMS_X_INVALID_SELECTOR_EXCEPTION:

			pszExceptionType = (xmsCHAR *) "XMS_JMSEXP_TYPE_INVALIDSELECTOREXCEPTION";
			break;

		case XMS_X_MESSAGE_EOF_EXCEPTION:

			pszExceptionType = (xmsCHAR *) "XMS_JMSEXP_TYPE_MESSAGEEOFEXCEPTION";
			break;

		case XMS_X_MESSAGE_FORMAT_EXCEPTION:

			pszExceptionType = (xmsCHAR *) "XMS_JMSEXP_TYPE_MESSAGEFORMATEXCEPTION";
			break;

		case XMS_X_MESSAGE_NOT_READABLE_EXCEPTION:

			pszExceptionType = (xmsCHAR *) "XMS_JMSEXP_TYPE_MESSAGENOTREADABLEEXCEPTION";
			break;

		case XMS_X_MESSAGE_NOT_WRITEABLE_EXCEPTION:

			pszExceptionType = (xmsCHAR *) "XMS_JMSEXP_TYPE_MESSAGENOTWRITEABLEEXCEPTION";
			break;

		case XMS_X_RESOURCE_ALLOCATION_EXCEPTION:

			pszExceptionType = (xmsCHAR *) "XMS_JMSEXP_TYPE_RESOURCEALLOCATIONEXCEPTION";
			break;

		default:

			pszExceptionType = (xmsCHAR *) "";
			break;
	}

	return(pszExceptionType);
}

/*
 * SYNOPSIS:   Returns the character string value for specified message type.
 * PARAMETERS: msgType - message type
 * RETURNS:    xmsCHAR *
 */

xmsCHAR * getMessageTypeString(xmsMESSAGE_TYPE msgType)
{
	xmsCHAR * pszMsgType = NULL;

	switch (msgType)
	{
		case XMS_MESSAGE_TYPE_BASE:

			pszMsgType = (xmsCHAR *) "XMS_MESSAGE_TYPE_BASE";
			break;

		case XMS_MESSAGE_TYPE_BYTES:

			pszMsgType = (xmsCHAR *) "XMS_MESSAGE_TYPE_BYTES";
			break;

		case XMS_MESSAGE_TYPE_MAP:

			pszMsgType = (xmsCHAR *) "XMS_MESSAGE_TYPE_MAP";
			break;

		case XMS_MESSAGE_TYPE_OBJECT:

			pszMsgType = (xmsCHAR *) "XMS_MESSAGE_TYPE_OBJECT";
			break;

		case XMS_MESSAGE_TYPE_STREAM:

			pszMsgType = (xmsCHAR *) "XMS_MESSAGE_TYPE_STREAM";
			break;

		case XMS_MESSAGE_TYPE_TEXT:

			pszMsgType = (xmsCHAR *) "XMS_MESSAGE_TYPE_TEXT";
			break;

		default:

			pszMsgType = (xmsCHAR *) "";
			break;
	}

	return(pszMsgType);
}


