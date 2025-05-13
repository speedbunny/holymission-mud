inherit "/obj/treasure";

#include "location.c"
void reset(int arg)
{
    ::reset(arg);
    if(!arg)
    {
	set_weight(1);
	set_name("locator");
	set_short("Darastor's location tester");
	set_long("A small amulet which Darastor has created " +
		 " to test the location logging code.\n");
    }
}

void init()
{
    ::init();
    add_action("main","location");
}
