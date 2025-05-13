inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("black Demon Colonel");
    set_alt_name("colonel");
    set_alias("colonel");
    set_race("demon");
    set_short("An ugly demon");
    set_long("An ugly demon.\n" +
             "The demon colonel will CRUSH anyone who tries to get by him!\n" +
             "It has a tattoo of a white crown on it's chest.\n");
    set_aggressive(1);
    set_level(25);
    set_wc(36);
    set_ac(17);
    set_al(-825);
    set_hp(2360);
    move_object(clone_object(ARMR + "tower/dchainmail"),this_object());
    command("wear chainmail");
    set_chance(40);
    set_spell_dam(45+(random(45)));
    set_spell_mess2("The colonel grabs your head and CRUSHES it!\n");
    set_spell_mess1("The colonel grabs his attacker's head and CRUSHES it!\n");
}
    id(str) {
        return str=="demon colonel"||str=="demon"||str=="topazdemon"||str=="black demon colonel"||str=="colonel"||str=="black demon"; }

init() {
    ::init();
    add_action("cannot","up");
    add_action("cannot","down");
}

cannot() {
    tell_room(environment(this_object()),
    "The demon colonel laughs at you as you try to get past him!\n");
    return 1;
}
