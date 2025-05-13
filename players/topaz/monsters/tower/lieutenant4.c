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
    set_level(17);
    set_wc(25);
    set_ac(9);
    set_al(-600);
    set_hp(870);
    move_object(clone_object(ARMR + "tower/dgloves"),this_object());
    command("wear gloves");
    set_chance(32);
    set_spell_dam(40);
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
