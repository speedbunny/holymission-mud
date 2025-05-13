inherit "room/room";

#include "/players/tamina/defs.h"

object prisoner;

void reset(int arg) 
{
  ::reset(arg);
  if (!arg) 
  {
    set_light(0);
    short_desc = "Dark Cell";
    long_desc =
	"The floor of this cell is covered with straw dark with mildew.\n"+
	"Rats scatter and scurry out of the range of your light. A\n"+
	"small cot sits in one corner of the room.\n";

    dest_dir = ({
	TFIRE + "dungeon","east"
	});

    items = ({
	  "cot","A hard plank of wood covered with a wet blanket"
	});

  }
  if (!present("prisoner")) 
  {
    prisoner = CLO("/players/tamina/teds/monsters/frost_giant_prisoner");
    MO(prisoner, TO);
  }
}

void init() 
{
  ::init();
  add_action("give_key", "open");
}

int give_key(string str) 
{
  object key_ob;

  if (!str || str != "shackles")
  {
    NFAIL("Open what?\n");
    return 0;
  }
  write("Frost Giant says: Thank you!\n"+
        "Frost Giant gives you his key.\n"+
        "Frost Giant says: Take this key to the Frost Giant King....\n");
  say("Frost Giant gives away his key.\n");

  key_ob = CLO("/players/tamina/teds/items/frost_key");
  if (transfer(key_ob, TP)) 
  {
    write("You are carrying too much.\n");
    move_object(key_ob, TO);
  }
  write("Frost Giant leaves east.\n");
  say("Frost Giant leaves east.\n");
  destruct(prisoner);
  return 1;
}
