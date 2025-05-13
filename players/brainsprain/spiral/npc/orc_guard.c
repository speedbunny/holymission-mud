
inherit "obj/monster";
#include "/players/brainsprain/spiral/spidef.h"
void reset(int arg) {
    ::reset();
    set_name("orc guard");
    set_race("orc");
    set_gender(1);

     set_alt_name("guard");
    set_alias("orc");
    set_short("An orc guard");
    set_long(
"An orc guard, his massive, barrel chest swells as he breaths.  A sword "+
"hangs from his belt.  His stubbly beard has crumbs and bits of last "+
"nights meal in it.  Both of his heavily muscles arms flex as he walks "+
"to and fro.\n");
    set_level(20);
    set_al(-40);
    set_aggressive(1);
    load_chat(2, ({
"Orc says: No man may enter the realm of Darkstaff.\n",
"Orc says: The orcs of Ormag will protect this cavern.\n"
}));
move_object((clone_object(si+"/sword.c")),TO);
init_command("wield sword");
}
