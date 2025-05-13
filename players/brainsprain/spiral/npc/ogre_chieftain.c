
inherit "obj/monster";
#include "/players/brainsprain/spiral/spidef.h"
void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("ogre");
    set_race("ogre");
    set_gender(1);
    set_alias("ogre");
    set_short("Ogre chieftain");
    set_long(
"The ogre boss, his sloped head as large as your chest.  He is dressed "+
"In a fine clothing hedged with golden filgree, it looks distinctly "+
"out of place on him.  He is easily fourteen feet tall and is "+
"incredibly massive.\n");
    set_level(15);
    set_hp(550);
    set_al(-40);
    set_ac(6);
    set_wc(20);
    set_aggressive(1);
    move_object(clone_object(si+"/scepterog.c"),TO);
    init_command("wield scepter");
}
