inherit "room/room";

#include "/players/tamina/defs.h"

object bear;

void reset(int arg) 
{
  ::reset(arg);
  if (!arg) 
  {
    set_light(0);
    short_desc = "Dark Cave";
    long_desc =
"This part of the cave looks like a large animal lives here.\n"+
"A massive iron chain is securely fastened to the wall with large\n"+
"iron bolts. It looks like the chain is used to keep an animal\n"+
"here. The cave becomes dryer and less icy to the north.\n";
  
    dest_dir = ({
      TFROST + "cave3", "north",
      TFROST + "cave1", "south"
    });

    items = ({
"chain","This massive iron chain is in good repair, with no signs of rust\n"+
        "or damage. It looks like is has been cleaned recently. It is\n"+
        "securly fastened to the cave wall. It looks like even a very\n"+
        "strong man could not pull it loose",
"bolts", "These iron bolts are sunk deep into the hard granite of the\n"+
         "cave wall. It would be almost impossible to pull them out"
    });
  }
  if(!present("cave bear")) 
  {
    bear = clone_object("obj/monster");

    bear->set_name("Cave Bear");
    bear->set_alias("cave bear");
    bear->set_race("bear");
    bear->set_gender(2);
    bear->set_short("A ferocious Cave Bear");
    bear->set_long("A wild, ferocious Cave Bear, with long, sharp teeth.\n");
    bear->set_level(15);
    bear->set_wc(20);
    bear->set_ac(5);
    bear->set_al(-10);
    bear->set_spell_mess2("The Cave Bear rips you apart with her claws.\n");
    bear->set_spell_mess1("The Bear swings her claws !!\n");
    bear->set_spell_dam(40);
    bear->set_chance(40);

    move_object(bear, this_object());
  }
}

void init() 
{
  ::init();
  add_action("_north", "north");
  add_action("_pull",  "pull");
}

int _north() 
{
  if (present("cave bear")) 
  {
    write("The Cave Bear blocks the entrance with his massive body!\n");
    return 1;
  }
}

int _pull(string str) 
{
  if (str == "chain") 
  {
    write("You pull as hard as you can on the chain, but nothing happens\n");
    say(TPN+" pulls on the chain\n");
    return 1;
  }
}
