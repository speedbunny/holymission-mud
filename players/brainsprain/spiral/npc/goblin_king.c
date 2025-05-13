
inherit "obj/monster";
#include "/players/brainsprain/spiral/spidef.h"
void reset(int arg) {
    ::reset(arg);
if(arg) return;
    set_name("king");
    set_race("goblin");
    set_alt_name("goblin");
    set_gender(1);
    set_alias("goblin","king");
    set_short("A goblin king");
    set_long(
"A goblin king, lord of the Galgug tribe.  He anxiously dances from foot to "+
"foot as he glances about the room.  A dirty sheet is thrown over his shoulder "+
"in an attempt to make a regal cape.\n");
    set_level(6);
    set_hp(130);
    set_al(-40);
    set_ac(2);
    set_wc(8);
    set_aggressive(51);
move_object((clone_object(si+"/scepter.c")),TO);
init_command("wield scepter");
}
