inherit "room/room";

#include "/players/tamina/defs.h"

status open;

void reset(int arg) 
{
  open = 0;
  ::reset(arg);
  if (!arg) 
  {
    set_light(1);
    short_desc = "Large Red Castle";
    long_desc =
	"The walls of this grim fortress are made of red stone, the\n"+
	"color of dried blood. A large iron gate blocks the entrance\n"+
	"to the castle. You can hear rumbling voices and the tramp of\n"+
	"booted feet from inside.\n"+
	"****Be sure to look at everything in this castle****\n";

    dest_dir = ({
	  THOT + "fire_giant","south"
	});

    items = ({
  "castle",
"This is the dreaded stronghold of the evil fire giants "+
"Only the very brave or the very foolish would dare to "+
"enter without a Giantslayer",
	});
    }
}


void init() 
{
    ::init();
    add_action("my_look", "look");
    add_action("my_look", "exa");
    add_action("do_open",  "open");
    add_action("go_north", "north");
}

int my_look(string str) 
{
  if (str == "gate" || str == "iron gate" || str == "at gate") 
  {
    write("This is a massive iron gate. It appears to be made of\n"+
	  "a red iron ore, baddly rusted. It looks as if a strong\n"+
	  "person could open it.\n");
    if (open) 
      write("The gate is already open.\n");
  }
}

int do_open(string str) 
{
  if (str == "gate" || str == "iron gate")
  {
    if (open)
    {
      write("But the gate is already opened !!\n");
      return 1;
    }
    if (TP->STR > 14) 
    {
      open = 1;
      write("You open the gate.\n"+
            "It is now possible to go north into the castle.\n");
      say(TPN+" opens the gate to the Fire Castle.\n");
      return 1;
    }
    write("You are not strong enough to open the gate.\n");
    return 1;
  }
}

int go_north() 
{
  if (!open) 
  {
    write("The gate is closed.\n");
    say(TPN+" walks into the closed gate.\n"+
	TP->QPRO+" feels very foolish.\n");
    return 1;
  }
  else
  {
    MPL("north#players/tamina/teds/fire/guard");
    return 1;
  }
}

