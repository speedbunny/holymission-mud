void log_this_location(object player, string str);

int main(string str)
{
    if (!str)
    {
	notify_fail("Usage: location <town (state)>, <country>");
	return 0;
    }
    if (sizeof(explode(str,","))==2)
    {
	log_this_location(this_player(), str);
	tell_object(this_player(), "Your location has been logged.\n");
	return 1;
    }

    notify_fail("Usage: location <town (state)>, <country>");
    return 0;
}

void log_this_location(object player, string str)
{
    string logline;
    
//    logline = player -> query_real_name();


    logline = sprintf("%-25s %-15s %s",
		      (capitalize(player -> query_real_name())),
		      (query_ip_number(player)),
		      str);
    log_file("location_log",logline);

}
