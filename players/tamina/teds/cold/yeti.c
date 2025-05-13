inherit "room/room";

#include "/players/tamina/defs.h"

object yeti;

void reset(int arg) 
{
    if (arg) return 0;
    set_light(1);
    short_desc = "Ice Cave";
    long_desc =
"This is a frozen desolate ice cave. A chill wind\n"+
"wistles through the opening making even colder.\n";

    dest_dir = ({
   TCOLD + "cold_top", "east"
    });

    yeti = clone_object("obj/monster");

    yeti->set_name("yeti");
    yeti->set_race("yeti");
    yeti->set_gender(1);
    yeti->set_long("A huge white snow ape.\n");
    yeti->set_level(12);
    yeti->set_wc(17);
    yeti->set_ac(5);
    yeti->set_aggressive(1);
    yeti->set_whimpy(25);

    call_other("/players/tamina/teds/random_weapon", "make_item", yeti, 12);

    move_object(yeti, this_object());
}
