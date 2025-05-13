inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("black Demon Captain");
    set_alt_name("captain");
    set_alias("captain");
    set_race("demon");
    set_short("An ugly demon");
    set_long("An ugly demon.\n" +
             "This demon captain is under strict orders not to let anyone by!\n" +
             "It has a tattoo of a white crown on its chest.\n");
    set_aggressive(1);
    set_level(20);
    set_wc(31);
    set_ac(12);
    set_al(-750);
    set_hp(1585);
    move_object(clone_object(ARMR + "tower/dchainmail"),this_object());
    command("wear chainmail");
    set_chance(35);
    set_spell_dam(50);
    set_spell_mess2("The captain backhands you hard!\n");
    set_spell_mess1("The captain backhands its opponent hard!\n");
}
    id(str) {
        return str=="demon captain"||str=="demon"||str=="topazdemon"||str=="black demon captain"||str=="captain"||str=="black demon"; }

init() {
    ::init();
    add_action("cannot","up");
    add_action("cannot","down");
}

cannot() {
    tell_room(environment(this_object()),
    "The demon captain barks out some orders as you move toward the stairs!\n");
    return 1;
}
