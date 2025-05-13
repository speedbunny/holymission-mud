
inherit "obj/monster";
#include "/players/brainsprain/spiral/spidef.h"
object wep;
void reset(int arg) {
    ::reset(arg);
    if(arg) return;
     set_name("Goblin Mystic");
    set_race("goblin");
    set_gender(1);
    set_alt_name("goblin");
    set_alias("mystic");
    set_short("A goblin mystic");
    set_long(
"A goblin mystic, he is wearing a shaggy old cloak with pockets all over "+
"it.  Various totems and fetishes adorn his belt.  He holds a rat tail "+
"in his right hand and wiggles it idly.\n");
     set_level(15);
    set_al(-40);
    set_chance(10);
    set_spell_dam(25);
    set_spell_mess2("The goblin mystic shakes his rat tail at you!\n");
move_object((clone_object(si+"/rat_tail.c")),TO);
init_command("wield tail");
}
