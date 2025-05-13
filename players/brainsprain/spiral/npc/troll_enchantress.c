inherit "obj/monster";
#include "/players/brainsprain/spiral/spidef.h"
void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("troll");
    set_race("troll");
    set_gender(0);
    set_alias("troll");
    set_short("A troll enchantress");
    set_long(
"An troll enchantress with a staff made of a human femur.  She is wearing "+
"practically nothing.  Here green-brown flesh is wrinkled with age.  Her "+
"belt has several pouches bulging with various objects.  A massive brooch "+
"is pinned directly into her throat.\n");
    set_level(7);
    set_hp(150);
    set_al(-40);
    set_ac(2);
    set_wc(9);
    set_chance(8);
    set_spell_dam(10);
    set_spell_mess2("The troll enchantress points her wand at you!!\n");
    move_object((clone_object(si+"/bone_wand.c")),TO);
}
