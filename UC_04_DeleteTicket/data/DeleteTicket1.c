DeleteTicket1()
{

	lr_start_transaction("click_button_Itinerary");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_auto_header("sec-ch-ua", 
		"\"Google Chrome\";v=\"93\", \" Not;A Brand\";v=\"99\", \"Chromium\";v=\"93\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	lr_think_time(23);

	web_url("welcome.pl_4", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=itinerary", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("click_button_Itinerary",LR_AUTO);

	lr_start_transaction("select_and_delete_ticket");

	web_add_header("Origin", 
		"http://127.0.0.1:1080");

	web_submit_form("itinerary.pl_2", 
		"Snapshot=t19.inf", 
		ITEMDATA, 
		"Name=1", "Value=<OFF>", ENDITEM, 
		"Name=2", "Value=on", ENDITEM, 
		"Name=3", "Value=<OFF>", ENDITEM, 
		LAST);

	lr_end_transaction("select_and_delete_ticket",LR_AUTO);

	return 0;
}