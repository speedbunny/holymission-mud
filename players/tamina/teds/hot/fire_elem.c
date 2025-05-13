inherit "room/room";

#include "/players/tamina/defs.h"

object elemental;

void reset(int arg) 
{
  if(arg) return 0;

  set_light(1);
  short_desc = "Burning waste";
  long_desc =
	"There is nothing but sand dunes baking in the heat as\n"+
	"far as the eye can see.\n";

  dest_dir = ({
	  THOT + "fire","west"
	});

  elemental = clone_object("obj/monster");

  elemental->set_name("fire elemental");
  elemental->set_race("elemental");
  elemental->set_long("An evil Fire elemental.\n");
  elemental->set_level(10);
  elemental->set_aggressive(1);
  elemental->set_whimpy(25);
  elemental->set_wc(25);
  elemental->set_ac(5);
  elemental->set_al(-300);

  call_other("/players/tamina/teds/random_armor", "make_item", elemental, 10);

  move_object(elemental, this_object());
}
