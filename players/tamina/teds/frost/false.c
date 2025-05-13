inherit "room/room";

#include "/players/tamina/defs.h"

int test;
status open, locked;
object money;

void reset(int arg) 
{
  open = 0; locked = 1; test = 1;
  ::reset(arg);
  if (!arg) 
  {
    set_light(0);
    short_desc = "Treasure Room";
    long_desc =
"This is the treasure room of the Frost Giants. Here they store\n"+
"their wealth. It is a small room with smoke stains on walls \n";

    dest_dir = ({
      TFROST + "study","south"
    });

  }
  if (!money) 
  {
    money = clone_object("obj/money");
    money->set_money(random(2000) + 1000);
    MO(money, TO);
  }
}

void long(string str) 
{
  ::long(str);
  if ((str == "door") && call_other(TFROST + "study", "query_ink_move")) 
  {
    if (open)
      write("The door is open.\n");
    else 
      write("The door is closed.\n");
  }
  if (!str && call_other(TFROST + "study", "query_ink_move"))
    write("There is the outline of a door on the north wall.\n");
}

void init() 
{
  ::init();
  AA("open", "open");
  AA("unlock", "unlock");
  AA("north", "north");
}


int id(string str)
{
    return str == "door";
}

int open(string str) 
{
  if (call_other(TFROST + "study", "query_ink_move")) 
  {
    if (str && str != "door")
      return 0;
    if (open)
    {
      write("But the door is open.\n");
      return 1;
    }
    if (locked) 
    {
      write("The door is locked.\n");
      return 1;
    }
    open = 1;
    write("You open the door.\n");
    say(TPN+" opened the door.\n");
    return 1;
  }
}

int unlock(string str) 
{
  if (call_other(TFROST + "study","query_ink_move")) 
  {
    if (present("king")) 
    {
      write("The Frost Giant King gets in your way!\n");
      return 1;
    }
    if (str && str != "door")
      return 0;
    if (open || !locked)
	return 0;
    if (!present("frost_key", this_player())) 
    {
      if (present("key", this_player()))
        write("You don't have the right key.\n");
      else
	write("You need a key.\n");
      return 1;
    }
    locked = 0;
    write("You unlock the door.\n");
    say(TPN+" unlocked the door.\n");
    return 1;
  }
}

int north() 
{
  if (call_other(TFROST + "study","query_ink_move")) 
  {
    if (!open) 
    {
	write("The door is closed.\n");
	return 1;
    }
    MPL("north#players/tamina/teds/frost/treasure");
    return 1;
  }
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
