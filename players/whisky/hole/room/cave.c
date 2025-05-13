inherit "room/room";
#include "/players/gambit/defs2.h"
reset(arg) {
    if (!arg) {
	short_desc = "Cave Entrance";
	long_desc = 
        "This cave looks like it used to be part of some old "+
           "castle. The walls and floor are covered in dried blood "+
           "and the ceiling has sharp rocks jutting out of "+
           "it. Huge grooves are dug into the walls "+
           "and betray the presence of an ominous evil. You notice "+
           "water dripping from the ceiling into a small pool "+
          "and a sign is posted in the rocks.\n";
	dest_dir = ({
	  "/players/whisky/hole/room/cave1","west",
	  "/players/whisky/hole/room/h14","east",
	});
	smell = "The cave smells old and musty";
	items = ({
	  "wall","Huge scratches are dug into the wall",
	  "walls","Dried blood and scratches are dug into the wall",
	  "floor",
	  "Dried blood covers the floor",
	  "pool","Water slowly drips into the pool",
	  "water","You see nothing special about it",
	  "ceiling","The ceiling has jagged rocks hanging from it",
	  "scratches","Huge scratches from something are dug into the walls",
	  "sign",
	  "There is something written on it",    
	});
    }
}

void init ()
{
    ::init();
    add_action("read","read");
}
int read(string str)
{
    if (str != "sign")
    {
	notify_fail("Read what?");
	return 0;
    }
    write(BS("Warning!!"));
    write(BS("I am the last survivor of the wizard Gambit's experiments "+
	"and something has gone wrong. Please take all caution upon entering "+
	"this area. If you find this place fast, please send help!! It "+
	"is out of control and destroying everything in its path."));
    write(BS("Oh My God..It's coming after me, please send some help."));
    write(BS("HHuurrryyyyy!!"));                        
    write(BS("**The rest of the sign is covered in splashed blood**"));
    return 1;
}
