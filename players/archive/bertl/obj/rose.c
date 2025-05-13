inherit"obj/treasure";
#include "/players/whisky/genesis/sys/break_string.h"
#define BS(x) break_string(x+"\n",68)
reset(arg) {
    if(arg) return;
    set_id("A red rose");
    set_alias("rose");
    set_short("A Red Rose");
    set_long(BS("A beatiful red rose of love or friendship. "+
	"Give one to your sweet-heart to show just how much you care for them. "+
	"The rose is giving off such wonderful smells."));
    set_value(0);
    set_weight(0);
}
void init()
{
    ::init();
    add_action("smell","smell");
}
int smell (string str)
{
    if (str!= "rose")
    {
	notify_fail("Smell what?");
	return 0;
    }
    write(BS("You smell the freshness of the red rose."));
    say(BS("HHmmmmm! "+this_player()->query_name()+" smells the red rose."));
    return 1;
}
