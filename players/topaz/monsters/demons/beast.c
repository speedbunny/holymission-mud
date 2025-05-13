inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("demon Beast");
    set_alt_name("beast");
    set_alias("demon beast");
    set_race("demon");
    set_short("A huge beast");
    set_long("A huge demon beast.\n" +
             "The beast doesn't like you here and keeps you away from the pit.\n" +
             "There is a white crown branded on its hindquarters.\n");
    set_aggressive(1);
    set_level(15);
    set_wc(20);
    set_ac(9);
    set_al(-400);
    set_hp(1000);
    set_chance(25);
    set_spell_dam(30);
    set_spell_mess2("The beast gores you with its horn!\n");
    set_spell_mess1("The beast slashes with its horn!\n");
}
    id(str) {
        return str=="demon beast"||str=="demon"||str=="topazdemon"||str=="black demon beast"||str=="beast"||str=="black demon"; }

init() {
    ::init();
    add_action("_down","down");
}

_down() {
    tell_room(environment(TO),
    "The beast keeps you away from the pit.\n");
    return 1;
}
