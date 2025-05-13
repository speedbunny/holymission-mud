inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("demon Dancer");
    set_alt_name("dancer");
    set_alias("topazdemon");
    set_race("demon");
    set_short("An ugly demon");
    set_long("This demon is ugly.\n" +
             "This dancing demon hates being interrupted in the\n" +
             "middle of a dance!\n" +
             "It has a tattoo of a white crown on it's chest.\n");
    set_aggressive(1);
    set_level(12);
    set_wc(15);
    set_ac(5);
    set_al(-300);
    set_hp(360);
    move_object(clone_object(WEAP + "demons/cknife"),this_object());
    command("wield knife");
    set_chance(20);
    set_spell_dam(25);
    set_spell_mess2("The dancer slashes at you with its knife!\n");
    set_spell_mess1("The dancer slashes with its knife!\n");
}

init() {
    ::init();
    add_action("cannot","south");
}

cannot() {
    tell_room(environment(this_object()),
    "The dancer won't let anyone go south!\n");
    return 1;
}
