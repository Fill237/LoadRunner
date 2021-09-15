test()
{

	web_url("WebTours", 
		"URL=http://127.0.0.1:1080/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "2&3");

	web_custom_request("actions", 
		"URL=https://nav.smartscreen.microsoft.com/api/browser/edge/actions", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"config\":{\"device\":{\"appControl\":{\"level\":\"anywhere\"},\"appReputation\":{\"enforcedByPolicy\":false,\"level\":\"unknown\"},\"pua\":null},\"user\":{\"uriReputation\":{\"enforcedByPolicy\":false,\"level\":\"unknown\"}}},\"identity\":{\"caller\":{\"locale\":\"ru-RU\",\"name\":\"anaheim\",\"process\":null,\"version\":\"93.0.961.47 (Official build) \"},\"client\":{\"data\":{\"customSettings\":\"F95BA787499AB4FA9EFFF472CE383A14\",\"customSynchronousLookupUris\":\"0\",\"edgeSettings\":\""
		"2.0-2f9188b68640dbf72295f9083a21d674a314721ef06f82db281cbcb052ff8ec1\",\"synchronousLookupUris\":\"637665197444665839\",\"topTraffic\":\"637582443620690300\"},\"version\":\"281479409696768\"},\"device\":{\"architecture\":9,\"browser\":{\"internetExplorer\":\"9.11.19041.0\"},\"cloudSku\":false,\"customId\":null,\"enterprise\":null,\"family\":3,\"id\":null,\"locale\":\"ru-RU\",\"netJoinStatus\":2,\"onlineIdTicket\":\"t=GwAWAd9tBAAUCqvYdtHJRIwInP+r5YPm2nbkkcAOZgAAELbp/hdP4zQ46jKbrof+Dp/"
		"gAD9n1Qj9bO55tjyq21NylP3VOxcJxZT2gRnEUNI+x2bhCX0uQXr03VB7OFmCyJS97uCdahBNH+schV2/HxsZ8h1Qz53dP5N5hH2UUCPVHx6huAkSFrvnFGElVSR98bEQv+xbqq2zGB96DclToUrRfqHLOjcfjB7K0pc3Wi3qdaqcrDpfSr5KbvS0GX7HkKIMPXGTh6t2B6Da9cpdUdvspJL4005MTU4oFQG2nAe0KC97IIMxM42TTBLS6d7t7OEO54sQKQTUpGMgcGnXv9SpfamJyMl3ZlQArY3EE49kf6fSHAE=&p=\",\"osVersion\":\"10.0.19043.1165.vb_release\"},\"user\":{\"locale\":\"ru-RU\"}},\"systemSettings\":{\"battery\":null,\"network\":null}}", 
		LAST);

	web_add_header("Sec-Fetch-Dest", 
		"empty");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_header("Sec-Fetch-Site", 
		"none");

	web_url("93.0.961.47", 
		"URL=https://config.edge.skype.com/config/v1/Edge/93.0.961.47?clientId=457701211842714665&osname=win&client=edge&channel=stable&scpfull=0&scpguard=1&scpfre=0&scpver=2&osver=10.0.19043&osarch=x86_64&osedition=home&wu=1&devicefamily=desktop&uma=1&mngd=0&installdate=1587895353", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(14);

	web_submit_data("login.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=132160.997407857zHQiADVpDAtVzzzHtAHiipViHicf", ENDITEM, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=48", ENDITEM, 
		"Name=login.y", "Value=14", ENDITEM, 
		LAST);

	lr_think_time(14);

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t5.inf", 
		LAST);

	return 0;
}