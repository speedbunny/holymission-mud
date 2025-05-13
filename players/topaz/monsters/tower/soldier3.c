inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("black Demon Soldier");
    set_alt_name("soldier");
    set_alias("soldier");
    set_race("demon");
    set_short("An ugly demon");
    set_long("An ugly demon.\n" +
             "This demon soldier will fight to protect its king!\n" +
             "It has a tattoo of a white crown on it's chest.\n");
    set_aggressive(1);
    set_level(10);
    set_wc(13);
    set_ac(4);
    set_al(-250);
    set_hp(265);
    move_object(clone_object(ARMR + "tower/dboots"),this_object());
    command("wear boots");
    set_chance(26);
    set_spell_dam(15);
    set_spell_mess2("The soldier hits you fiercely.\n");
    set_spell_mess1("The soldier attacks fiercely.\n");
}
    id(str) {
        return str=="demon soldier"||str=="demon"||str=="topazdemon"||str=="black demon soldier"||str=="soldier"||str=="black demon"; }

init() {
    ::init();
    add_action("cannot","up");
    add_action("cannot","down");
}

cannot() {
    tell_room(environment(this_object()),
    "The demon soldier allows no passage up or down the stairs!\n");
    return 1;
}
