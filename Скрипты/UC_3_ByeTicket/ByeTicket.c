ByeTicket()
{
	
	lr_start_transaction("UC_03_ByeTicket");
	

	lr_start_transaction("home_page");
	
	lr_think_time(5);
	
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
	
	lr_think_time(5);
	
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
		

	lr_start_transaction("click_button_flights");
	
	lr_think_time(5);
	
	web_reg_find("Text/IC=User has returned to the search page.", LAST);

	web_url("Search Flights Button", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("click_button_flights",LR_AUTO);

	
	lr_start_transaction("find_flight");

	lr_think_time(5);
	
	web_reg_find("Text/IC=Flight Selections", LAST);
	
	web_reg_find("Text/IC=<B>{depart}</B> to <B>{arrive}</B>", LAST);
	
	web_reg_save_param_ex(
		"ParamName=OBF",
		"LB=outboundFlight\" value=\"",
		"RB=\"",
		"Ordinal=1",
		SEARCH_FILTERS,
		LAST);

	web_submit_data("reservations.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={depart}", ENDITEM, 
		"Name=departDate", "Value={DepData}", ENDITEM, 
		"Name=arrive", "Value={arrive}", ENDITEM, 
		"Name=returnDate", "Value={ArrData}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value={Row}", ENDITEM, 
		"Name=seatType", "Value={Klass}", ENDITEM, 
		"Name=findFlights.x", "Value=51", ENDITEM, 
		"Name=findFlights.y", "Value=13", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		LAST);
	
	lr_end_transaction("find_flight",LR_AUTO);
	

	lr_start_transaction("flight_selection");
	
	lr_think_time(5);

	web_reg_find("Text/IC=Flight Reservation", LAST);
	
	web_submit_data("reservations.pl_2", 
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={OBF}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value={Klass}", ENDITEM, 
		"Name=seatPref", "Value={Row}", ENDITEM, 
		"Name=reserveFlights.x", "Value=55", ENDITEM, 
		"Name=reserveFlights.y", "Value=9", ENDITEM, 
		LAST);
			
	lr_end_transaction("flight_selection",LR_AUTO);
	

	lr_start_transaction("payment_details");
	
	lr_think_time(5);
	
	web_reg_find("Text/IC=Reservation Made!", LAST);

	web_submit_data("reservations.pl_3", 
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value={FirstName}", ENDITEM, 
		"Name=lastName", "Value={LastName}", ENDITEM, 
		"Name=address1", "Value={Street}", ENDITEM, 
		"Name=address2", "Value={City}", ENDITEM, 
		"Name=pass1", "Value={PassName}", ENDITEM, 
		"Name=creditCard", "Value={CreditCard}", ENDITEM, 
		"Name=expDate", "Value={ExpDate}", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value={Klass}", ENDITEM, 
		"Name=seatPref", "Value={Row}", ENDITEM, 
		"Name=outboundFlight", "Value={OBF}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=buyFlights.x", "Value=24", ENDITEM, 
		"Name=buyFlights.y", "Value=11", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		LAST);

	lr_end_transaction("payment_details",LR_AUTO);
	
	
	lr_start_transaction("click_button_itinerary");
	
	lr_think_time(5);
	
	web_reg_find("Text/IC= User wants the intineraries.", LAST);

	web_url("Itinerary Button", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("click_button_itinerary",LR_AUTO);

	
	lr_start_transaction("logout");
	
	lr_think_time(5);

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
	
	
	lr_end_transaction("UC_03_ByeTicket", LR_AUTO);


	return 0;
}
