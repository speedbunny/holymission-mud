inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("black Demon Lieutenant");
    set_alt_name("lieutenant");
    set_alias("lieutenant");
    set_race("demon");
    set_short("An ugly demon");
    set_long("An ugly demon.\n" +
             "This demon lieutenant will do all in its power to guard its king!\n" +
             "It has a tattoo of a white crown on its chest.\n");
    set_aggressive(1);
    set_level(15);
    set_wc(21);
    set_ac(7);
    set_al(-500);
    set_hp(610);
    set_chance(30);
    set_spell_dam(35);
    set_spell_mess2("The lieutenant bites you!\n");
    set_spell_mess1("The lieutenant bites its opponent!\n");
}
    id(str) {
        return str=="demon lieutenant"||str=="demon"||str=="topazdemon"||str=="black demon lieutenant"||str=="lieutenant"||str=="black demon"; }

init() {
    ::init();
    add_action("cannot","up");
    add_action("cannot","down");
}

cannot() {
    tell_room(environment(this_object()),
    "The demon lieutenant guards the stairs and allows no passage up or down!\n");
    return 1;
}
