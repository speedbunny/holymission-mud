inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("black Demon Treasurer");
    set_alt_name("treasurer");
    set_alias("demon treasurer");
    set_race("demon");
    set_short("Demon Treasurer");
    set_long("An ugly demon.\n" +
             "This demon treasurer is in charge of the demon king's wealth.\n" +
             "It has a tattoo of a white crown on it's chest.\n");
    set_aggressive(0);
    set_level(10);
    set_wc(13);
    set_ac(4);
    set_al(-250);
    set_hp(265);
    add_money(5000);
    move_object(clone_object(OBJS + "tower/recordbooks"),TO);
    set_chance(25);
    set_spell_dam(20);
    set_spell_mess2("The treasurer hits you with the record books.\n");
    set_spell_mess1("The treasurer attacks with the record books.\n");
}
    id(str) {
        return str=="demon treasurer"||str=="demon"||str=="topazdemon"||str=="black demon treasurer"||str=="treasurer"||str=="black demon";
    }
