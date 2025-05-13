inherit "obj/monster";
#include "/players/brainsprain/spiral/spidef.h"
void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("troll");
    set_race("troll");
    set_gender(1);
    set_alias("troll");
    set_short("Troll axe thrower");
    set_long(
"A troll axe thrower, fingering his axe blade.  He is short for a troll. "+
"However, his massive hands and arms make it apparent that he is quite "+
"capable of wielding his axe.  His red tunic is covered with metal shavings "+
"and he has a sharpening stone in his pocket.\n");
    set_level(12);
    set_hp(310);
    set_al(-40);
    set_ac(4);
    set_wc(14);
    move_object((clone_object(si+"/axe.c")),TO);
    init_command("wield axe");
    load_chat(2, ({
"You want axe?\n",
"The trolls of Trakag will protect this cavern.\n"
}));

}
