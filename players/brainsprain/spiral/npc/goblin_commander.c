inherit "obj/monster";
#include "/players/brainsprain/spiral/spidef.h"
object wep;
void reset(int arg) {
    ::reset(arg);
if(arg) return;
   set_name("Goblin Commander");
    set_race("goblin");
    set_gender(1);
    set_alt_name("goblin");
    set_alias("goblin","commander");
    set_short("Goblin commander");
    set_long(
"A goblin commander, leading his platoon of fighters.  He hefts his stone "+
"axe and grumbles orders as he strolls about.  He is several inches taller "+
"and broader than his fellow goblins.\n");
   set_level(18);
    set_al(-40);
move_object(clone_object(si+"/stone_axe.c"),TO);
init_command("wield axe");
}
