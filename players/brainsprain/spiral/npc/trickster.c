inherit "obj/monster";
#include "/players/brainsprain/spiral/spidef.h"
void reset(int arg) {
    ::reset(arg);
if(arg) return;
    set_name("trickster");
    set_alt_name("troll");
    set_race("orc");
    set_gender(1);
    set_alias("trickster");
    set_short("A trollish trickster");
    set_long(
"A tiny troll whoese hand keeps darting in and out of a bag that is "+
"tied to his belt.  He is dressed in bright green and is wearing a "+
"jester's cap.  He is perpetually grinning as he hops to and fro.\n");
    set_level(7);
    set_hp(150);
    set_al(-40);
    set_ac(2);
    set_wc(9);
set_chance(9);
    set_spell_dam(7);
    set_spell_mess2("The trickster throws a trick at you!\n");
    load_chat(2, ({
"Hehe I have tricks.\n",
"These tricks are cool.\n"
    }));
    move_object((clone_object(si+"/bag_o_tricks.c")),TO);
}
