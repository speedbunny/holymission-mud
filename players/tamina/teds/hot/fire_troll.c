inherit "room/room";

#include "/players/tamina/defs.h"

object troll;
int i;

void reset(int arg) 
{
  if (!arg) 
  {
    set_light(1);
    short_desc = "Lava Pool";
    long_desc =
"A large pool of bubling lava is exposed to the open air.\n"+
"A worn path winds around the edge. It looks as if someone\n"+
"or something makes frequent trips down to the pool and\n"+
"back up. It is much to hot for you to attempt though.\n";

    dest_dir = ({
   THOT + "fire_south", "north",
   THOT + "fire", "south"
    });

  }
  if (!present("fire troll")) 
  {
    i = 0;
    while(i < 3) 
    {
      i++;
      troll = clone_object("obj/monster");

      troll->set_name("fire troll");
      troll->set_race("troll");
      troll->set_gender(1);
      troll->set_long(
  "This creature vaguely resembles a troll made of molten lava...\n");
      troll->set_level(5 + random(7));
      troll->set_wc(15);
      troll->set_ac(4);
      troll->set_al(-100);
      troll->set_aggressive(1);
      troll->set_whimpy(25);

    call_other("players/tamina/teds/random_treasure","make_item", troll, 12);
    move_object(troll, this_object());
    }
  }
}
