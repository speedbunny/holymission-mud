/*
 * Allzweck-object
 * 
 * ##mike## 30.08.94
 */

inherit "obj/thing";

void reset(int arg)
{
	if(arg) return;
	::reset(arg);
	
	set_name("x");
	set_short("x");
	
}

void init()
{
	::init();
	add_action("a_x","x");
}

int a_x(string arg)
{
	if(call_other("/players/whisky/guild/spells/xx","xx",arg))
		 write("Function xx successfully called.\n");
	else write("Error calling xx.\n");
	return 1;
}
