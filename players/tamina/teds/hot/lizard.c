inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  if (!arg) 
  {
    set_light(1);
    short_desc = "Burning waste";
    long_desc =
	"There is nothing but sand dunes baking in the sun\n"+
	"for as far as the eye can see.\n";

    dest_dir = ({
	  THOT + "fire","east",
	});

    }
    if (!present("fire lizard")) 
    {
      int i;
      object lizard;
      i = 0;
      while(i < 3) 
      {
        i++;
	lizard = clone_object("obj/monster");

        lizard->set_name("fire lizard");
        lizard->set_race("lizard");
        lizard->set_gender(1);
        lizard->set_long(
  "This is a huge fire-lizard, which seems to be on fire.\n"+
  "But the fire does not seem to be affecting it at all...\n");
        lizard->set_level(5 + random(5));
        lizard->set_wc(11);
        lizard->set_ac(3);
        lizard->set_aggressive(1);
        lizard->set_al(-100);

	call_other("/players/tamina/teds/random_treasure", "make_item", lizard, 10);
	move_object(lizard, this_object());
     }
  }
}
