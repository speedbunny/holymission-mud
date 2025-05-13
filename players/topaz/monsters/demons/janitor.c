inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("demon Janitor");
    set_alt_name("janitor");
    set_alias("topazdemon");
    set_race("demon");
    set_short("An ugly demon");
    set_long("This demon is ugly.\n" +
             "The Janitor keeps the Demon Queen's area clean.\n" +
             "It is very muscular from all of the hard work it does.\n" +
             "It has a tattoo of a white crown on it's chest.\n");
    set_aggressive(0);
    set_level(17);
    set_wc(26);
    set_ac(9);
    set_al(-100);
    set_hp(1000);
    move_object(clone_object(WEAP + "demons/mop"),this_object());
    command("wield mop");
    set_chance(30);
    set_spell_dam(30);
    set_spell_mess2("The janitor slaps you hard with the mop.\n");
    set_spell_mess1("The janitor slaps its opponent hard with its mop.\n");
}
