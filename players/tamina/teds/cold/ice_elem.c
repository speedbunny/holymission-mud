inherit "room/room";

#include "/players/tamina/defs.h"

object elemental;

void reset(int arg) 
{
    if (arg) return 0;
    set_light(1);
    short_desc = "Frozen Waste";
    long_desc =
"There is nothing as far as the eye can see\n"+
"except snow and ice.\n";

    dest_dir = ({
  TCOLD + "snow", "west"
    });

    elemental = clone_object("obj/monster");

    elemental->set_name("ice elemental");
    elemental->set_race("elemental");
    elemental->set_long("A supernatural being made out of solid Ice.\n");
    elemental->set_level(10);
    elemental->set_wc(25);
    elemental->set_ac(4);
    elemental->set_aggressive(1);
    elemental->set_whimpy(25);
    elemental->add_money(50);

    move_object(elemental, this_object());

}
