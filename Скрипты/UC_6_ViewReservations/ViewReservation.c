ViewReservation()
{
	lr_start_transaction("UC_06_ViewReservations");
	
	
	lr_start_transaction("home_page");
	
	lr_think_time(3);
	
	web_reg_find("Text/IC=Web Tours",LAST);

	web_reg_save_param_ex(
		"ParamName=userSession",
		"LB=userSession\" value=\"",
		"RB=\"",
		"Ordinal=1",
		SEARCH_FILTERS,
		LAST);

	web_url("welcome.pl_2", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);
		
	lr_end_transaction("home_page",LR_AUTO);
	

	lr_start_transaction("logon");
	
	lr_think_time(3);
	
	web_reg_find("Text/IC=User password was correct", LAST);

	web_submit_data("login.pl",
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t3.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={Login}", ENDITEM,
		"Name=password", "Value={Password}", ENDITEM,
		"Name=login.x", "Value=70", ENDITEM,
		"Name=login.y", "Value=5", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);
	
	lr_end_transaction("logon",LR_AUTO);
	
		
	lr_start_transaction("click_button_itinerary");
	
	lr_think_time(3);
			
	web_reg_save_param("FlightID",
		"LB=flightID\" value=\"",
		"RB=\"",
		"Ord=1",
		LAST);
	
	web_reg_find("Text/IC=User wants the intineraries.",LAST);

	web_url("welcome.pl_2", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t45.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("click_button_itinerary", LR_AUTO);
	
	
	lr_start_transaction("logout");
	
	lr_think_time(3);

	web_reg_find("Text/IC=A Session ID has been created and loaded into a cookie called MSO.", LAST);

	web_url("SignOff Button", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("logout",LR_AUTO);

	
	lr_end_transaction("UC_06_ViewReservations", LR_AUTO);

	return 0;
}
