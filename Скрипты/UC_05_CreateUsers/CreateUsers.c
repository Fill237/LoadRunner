CreateUsers()
{
	lr_start_transaction("UC_05_CreateUsers");
	
	
	lr_start_transaction("home_page");
		
	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_cookie("MSO=SID&1630870792; DOMAIN=127.0.0.1");
	
	web_reg_find("Text/IC=Web Tours",LAST);

	web_url("welcome.pl", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("home_page",LR_AUTO);
	

	lr_start_transaction("click_sing_up_now");
	
	lr_think_time(5);
	
	web_reg_find("Text=User Information",LAST);

	web_url("login.pl", 
		"URL=http://127.0.0.1:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/home.html", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("click_sing_up_now",LR_AUTO);
	

	lr_start_transaction("customer_profile");

	lr_think_time(5);

	web_reg_find("Text/IC={Login}",LAST);

	web_submit_data("login.pl_2", 
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={Login}", ENDITEM, 
		"Name=password", "Value={Password}", ENDITEM, 
		"Name=passwordConfirm", "Value={PassConfirm}", ENDITEM, 
		"Name=firstName", "Value={FirstName}", ENDITEM, 
		"Name=lastName", "Value={LastName}", ENDITEM, 
		"Name=address1", "Value={StreetAddress}", ENDITEM, 
		"Name=address2", "Value={CityAddress}", ENDITEM, 
		"Name=register.x", "Value=32", ENDITEM, 
		"Name=register.y", "Value=4", ENDITEM, 
		LAST);

	lr_end_transaction("customer_profile",LR_AUTO);
	

	lr_start_transaction("click_button_continue");

	lr_think_time(5);
	
	web_reg_find("Text/IC= User has returned to the home page.",LAST);

	web_url("button_next.gif", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("click_button_continue",LR_AUTO);
	

	lr_start_transaction("logout");

	lr_think_time(5);
	
	web_reg_find("Text/IC= A Session ID has been created and loaded into a cookie called MSO.",LAST);

	web_url("SignOff Button", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("logout",LR_AUTO);
	
	
	lr_end_transaction("UC_05_CreateUsers", LR_AUTO);

	return 0;
}
