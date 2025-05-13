inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("black Demon Corporal");
    set_alt_name("corporal");
    set_alias("corporal");
    set_race("demon");
    set_short("An ugly demon");
    set_long("An ugly demon.\n" +
             "This demon corporal won't let you out of this room alive!\n" +
             "It has a tattoo of a white crown on its chest.\n");
    set_aggressive(1);
    set_level(11);
    set_wc(14);
    set_ac(5);
    set_al(-300);
    set_hp(310);
    set_chance(26);
    set_spell_dam(25);
    set_spell_mess2("The corporal kicks you in the leg, hard!\n");
    set_spell_mess1("The corporal kicks its opponent!\n");
}
    id(str) {
        return str=="demon corporal"||str=="demon"||str=="topazdemon"||str=="black demon corporal"||str=="corporal"||str=="black demon"; }

init() {
    ::init();
    add_action("cannot","up");
    add_action("cannot","down");
}

cannot() {
    tell_room(environment(this_object()),
    "The demon corporal moves toward you as you try to use the stairs!\n");
    return 1;
}
