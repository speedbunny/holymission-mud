
inherit "/players/blade/guild/poison/ingredient";

void reset(int arg)
{
    ::reset(arg);
    if(arg) 
	return;
    set_name("blackthorn root");
    set_alias("root");
    set_alt_name("blackthorn");
    set_short("A blackthorn root");
    set_long("A powerful poison can be extracted from the legendary blackthorn root.\n");
}

