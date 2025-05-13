inherit "room/room";

#include "/players/tamina/defs.h"

object troll;
int i;

void reset(int arg) 
{
  if (!arg) 
  {
    set_light(1);
    short_desc = "Small Bridge";
    long_desc =
"A small wooden bridge leads across a frozen\n"+
"stream. The smell of rotting flesh comes from\n"+
"the corpses of small animals and fish which\n"+
"lie on either side of the stream.\n";

    dest_dir = ({
  TCOLD + "ice_south", "north",
  TCOLD + "snow", "south"
    });

  }
  i = 0;
  if (!present("ice troll")) 
  {
    while(i < 3) 
    {
      i = i + 1;
      troll = clone_object("obj/monster");

      troll->set_name("ice troll");
      troll->set_race("troll");
      troll->set_gender(1 + random(2));
      troll->set_long("An ugly Ice Troll.\n");
      troll->set_level(7 + random(5));
      troll->set_wc(17);
      troll->set_ac(6);
      troll->set_al(-60);
      troll->set_aggressive(1);
      troll->set_whimpy(25);
      troll->add_money(100 + random(51));

      move_object(troll, this_object());
    }
  }
}
