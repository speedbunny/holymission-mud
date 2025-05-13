inherit "room/room";

#include "/players/tamina/defs.h"

object prince, weapon, arrow;

void reset(int arg) 
{
  ::reset(arg);
  if (!arg) 
  {
    set_light(1);
    short_desc = "Playroom";
    long_desc =
"This is a childs playroom. Toys are scatered all over the floor.\n"+
"Books and puzzles lie discarded on tables and a few pillows\n"+
"leaking feathers lie in a heap near the door.\n";

    dest_dir = ({
	TFIRE + "ehall2", "south"
    });

    items = ({
  "toys",
"You are a grownup!!! What would you do with a childs toy?",
  "toy",
"You are a grownup!!! What would you do with a childs toy?",
  "books",
"These are childrens books and are impossible to understand",
  "puzzles",
"Just looking at the puzzles gives you a headache",
  "pillows",
"These are huge feather pillows. They look worse for wear",
  "feathers",
"Some feathers have escaped from the feather pillows"
    });
  }
  if (!present("fire giant prince")) 
  {
    prince = clone_object(TMONS + "fire_giant_prince");
    move_object(prince, this_object());
    call_other("players/tamina/teds/random_treasure","make_item",prince,19);
  }
}
