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
    set_level(15);
    set_wc(21);
    set_ac(7);
    set_al(-350);
    set_hp(600);
    move_object(clone_object(WEAP + "demons/cblade"),this_object());
    command("wield blade");
    set_chance(30);
    set_spell_dam(35);
    set_spell_mess2("The dancer cuts you with its blade.\n");
    set_spell_mess1("The dancer cuts its opponent with its blade.\n");
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
