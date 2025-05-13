inherit "obj/monster";
#include "/players/brainsprain/spiral/spidef.h"
void reset(int arg) {
    ::reset(arg);
if(arg) return;
    set_name("Goblin Fighter");
    set_race("goblin");
    set_alt_name("goblin");
    set_gender(1);
    set_alias("fighter");
    set_short("A goblin fighter");
    set_long(
"On this goblin fighter's dirty, bare chest is a tattoo proudly showing "+
"his membership in the goblin clan of Galgug.  His long arms almost reach "+
"the floor.  His wide, flat feet are positioned under him in a loose battle "+
"stance.\n");
    set_level(15);
    set_al(-40);
    set_aggressive(1);
    load_chat(2, ({
"Goblin fighter says: No man may enter the realm of Darkstaff.\n",
"Goblin fighter says: The goblins of Galgug will protect this cavern.\n"
}));
move_object((clone_object(si+"/club.c")),TO);
init_command("wield club");
    }
