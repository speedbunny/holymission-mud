inherit "room/room";

#include "/players/tamina/defs.h"

status open, locked;

void reset(int arg) 
{
  ::reset(arg);
  open = 0;
  locked = 1;
  if(!arg) 
  {
    set_light(0);
    short_desc = "Dungeon";
    long_desc =
	"The walls of this room are made of stone blocks cemented together\n"+
	"by some type of morter. Rivlets of water run and drip from the\n"+
	"walls and ceiling. The smell of torture and death hangs heavy in\n"+
	"the air. There is a cell door to the west.\n";

    dest_dir = ({
	TFIRE + "estairs","up"
	});
    }
}

void init() 
{
  ::init();
  add_action("my_look", "look");
  add_action("my_look", "exa");
  add_action("open",    "open");
  add_action("west",    "west");
  add_action("unlock",  "unlock");
}

int my_look(string str) 
{
  if (str == "door" || str == "at door") 
  {
    if (open)
      write("The door is open.\n");
    else
      write("The door is closed.\n");
  }
}

int open(string str) 
{
  if (str == "door")
  {
    if (open)
    {
      write("But the door is already open !!\n");
      return 1;
    }
    if (locked) 
    {
      write("But the door is locked.\n");
      return 1;
    }
    open = 1;
    write("You open the door.\n");
    say(TPN+" opened the door.\n");
    return 1;
  }
  else
  {
    NFAIL("Open what?\n");
    return 0;
  }
}

int unlock(string str) 
{
  if (str == "door")
  {
    if (open || !locked)
    {
      write("But the door is already unlocked !!\n");
      return 1;
    }
    if (!present("fire_key", TP)) 
    {
      if (present("key", TP))
	write("You don't seem to have the right key.\n");
      else
	write("You need a key to unlock this door.\n");
      return 1;
    }
    locked = 0;
    write("You unlock the door.\n");
    say(TPN+" unlocked the door.\n");
    return 1;
  }
  else
  {
    NFAIL("Unlock what?\n");
    return 0;
  }
}

int west() 
{
  if (!open) 
  {
    write("But the door is closed.\n");
    return 1;
  }
  MPL("west#/players/tamina/teds/fire/cell");
  return 1;
}

int query_door() 
{
    return !open;
}

int open_door_inside() 
{
    locked = 0;
    open = 1;
}
