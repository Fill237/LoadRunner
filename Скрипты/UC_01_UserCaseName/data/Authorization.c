Authorization()
{

	lr_start_transaction("logout");

	lr_end_transaction("logout",LR_AUTO);

	return 0;
}