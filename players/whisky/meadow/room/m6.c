/* Edited by Colossus 040694 Check for present herbs before cloning more */
/* Edited by Portil 05/05/94 Moved the line that cloned herbs to before the if(arg) return so that it is actually cloned at the reset! */

#define TQ this_player()->query_name()
#define TP this_player()

inherit "room/room";

#include "../meadow.h"

void reset (int arg) 
{

    if (filter_live(this_object()) < 2)
	CM("butterfly");
    if(!present("herbs")) { CO("herbs"); }

    if (!present("wuki",this_object()))
    {
        move_object(clone_object("/players/whisky/guild/monster/wuki"),
        this_object());
       }
    if (arg) return;
    set_light(1);
    short_desc = "On a meadow";
    long_desc = BS(
      "You are standing on the big meadow. The grass is "+
      "fresh and high. To the east you can see really big "+
      "bushes and you can hear the rolling of the sea.");
    dest_dir = ({
      PATH+"m5","west",
      PATH+"m8","northwest",
      PATH+"m3","south",
      PATH+"m9","north",
      PATH+"m2","southwest" });
    items = ({ "bushes","10 foot high hazelnut bushes" });
}
init() {
    ::init();
    add_action("pass","pass");
}

int pass(string str) 
{
    if (str=="bushes" || str=="hazelnut bushes") 
    {
	say(TQ+" tries to pass the bushes, but falls down and hurts\n"+
	  "himself badly.\n");
	TP->hit_player(5);
	write("You try to pass the bushes, but they are too high.\n"+
	  "Instead you hurt yourself badly.\n");
	return 1; 
    }
    return 0;
}
