
#define TQ this_player()->query_name()
#define TP this_player()

inherit "room/room";
#include "../meadow.h"

void reset (int arg) 
{

    if (filter_live(this_object()) < 3)
	CM("hart");

    if (arg) return;
    set_light(1);
    short_desc = "On a meadow";
    long_desc = BS(
      "You are standing on the big meadow. The grass is "+
      "fresh and high. To the west and north you see big "+
      "bushes and you can hear the rolling of the sea.");
    items = ({ "bushes","10 foot high hazelnut bushes" });
    /* Exos 2-22-98, fixed southeast exit to be southwest, little typo there */
    dest_dir = ({
      PATH+"m4","south",
      PATH+"m8","east",
      PATH+"m5", "southwest" });
}

init() 
{
    ::init();
    add_action("pass","pass");
}

int pass(string str) 
{
    if (str=="bushes" || str=="hazelnutbushes") 
    {
	write("You try to pass the bushes, but they are too high.\n"+
	  "Instead you hurt yourself badly.\n");
	say(TQ+" tries to pass the bushes, but falls down and hurts\n"+
	  "himself badly.\n");
	TP->hit_player(5);
	return 1; 
    }
    return 0;
}

