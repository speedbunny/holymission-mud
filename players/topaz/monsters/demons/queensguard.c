inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("black Demon Queen's Guard");
    set_alt_name("guard");
    set_alias("queen's guard");
    set_race("demon");
    set_short("An ugly demon");
    set_long("An ugly demon.\n" +
             "The Queen's guard won't let anyone harm the Queen!\n" +
             "It has a tattoo of a white crown on its chest.\n");
    set_aggressive(0);
    set_level(27);
    set_wc(38);
    set_ac(19);
    set_al(-850);
    set_hp(2670);
    move_object(clone_object(WEAP + "demons/dsword"),this_object());
    command("wield sword");
    set_chance(45);
    set_spell_dam(45+(random(45)));
    set_spell_mess2("The Queen's guard pokes you with its sword!\n");
    set_spell_mess1("The Queen's guard pokes its opponent with its sword!\n");
}
    id(str) {
        return str=="demon guard"||str=="demon"||str=="topazdemon"||str=="black demon guard"||str=="guard"||str=="black demon"; }

init() {
    ::init();
    add_action("_cannot","up");
}

_cannot() {
    tell_room(environment(this_object()),
    "The Queen's guard steps in your way!\n");
    return 1;
}
