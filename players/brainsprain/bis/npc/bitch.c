inherit "obj/monster";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg){
    ::reset();
    set_name("princess");
    set_race("human");
    set_gender(0);
    set_alias("fluentia");
    set_alt_name("princess bismarck");
    set_short("The necromantic princess");
            set_long(
"This is the Fluentia, the Princess of Bismarck.  She masquerades as a "+
"fragile lady of the court, but here she is in all her splendor, her "+
"hair is black and she is swathed in black.  The rumors of her necromantic "+
"powers must be true!\n")+
    set_level(15);
    set_hp(200);
    set_al(400);
    set_ac(6);
    set_wc(15);
move_object((clone_object(q+"/qgloves.c")),this_object());
}
