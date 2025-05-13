inherit "room/room";

#include "/players/tamina/defs.h"

object giant, young, sword;
int i;

void reset(int arg) 
{
  if (!arg) 
  {
    set_light(1);
    short_desc = "Frozen Forest";
    long_desc =
"The remains of a freshly dead mammoth lie here.\n"+
"Most of the meat has been wrapped in ice packed\n"+
"leather skins.\n";

    dest_dir = ({
    TCOLD + "frozen_forest", "south",
    TFROST + "base", "north"
    });

  }
  if (!present("giant")) 
  {
    i = 0;
    while(i < 2) 
    {
      i = i + 1;
      giant = clone_object("obj/monster");
    
      giant->set_name("frost giant hunter");
      giant->set_alias("hunter");
      giant->set_race("giant");
      giant->set_gender(1);
      giant->set_long("A Giant of the colder realms, which likes to hunt.\n");
      giant->set_level(16);
      giant->set_wc(20);
      giant->set_ac(6);
      giant->set_al(-150);
      giant->set_aggressive(1);

      sword = clone_object("/players/tamina/teds/weapons/sword_of_frost");
      move_object(sword, giant);
      command("wield sword", giant);
      move_object(giant, this_object());
    }
  }
  if (!present("young frost giant"))
  {
    young = clone_object("obj/monster");

    young->set_name("young frost giant");
    young->set_alias("young giant");
    young->set_race("giant");
    young->set_gender(1);
    young->set_long("A younger frost giant.\n"+
		    "He looks quite inexperienced...\n");
    young->set_level(14);
    young->set_wc(21);
    young->set_ac(4);
    young->set_al(-150);
    young->set_aggressive(1);
    young->set_whimpy(25);

    call_other("/players/tamina/teds/random_treasure", "make_item", giant, 14);
    move_object(giant, this_object());
  }
}
