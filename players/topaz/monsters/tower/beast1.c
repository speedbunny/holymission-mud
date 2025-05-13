inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("demon Beast");
    set_alt_name("beast");
    set_alias("demon beast");
    set_race("demon");
    set_short("A monstrous beast");
    set_long("A monstrous demon beast!\n" +
             "The beast thinks you are dinner!!\n" +
             "There is a white crown branded on its hindquarters.\n");
    set_aggressive(0);
    set_level(13);
    set_wc(17);
    set_ac(6);
    set_al(-400);
    set_hp(500);
    move_object(clone_object(WEAP + "demonhorn"),this_object());
    command("wield horn");
    set_chance(25);
    set_spell_dam(30);
    set_spell_mess2("The beast gores you with its horn!\n");
    set_spell_mess1("The beast attacks with its horn!\n");
}
    id(str) {
        return str=="demon beast"||str=="demon"||str=="topazdemon"||str=="black demon beast"||str=="beast"||str=="black demon"; }
