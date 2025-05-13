
inherit "obj/monster";
#include "/players/brainsprain/spiral/spidef.h"
void reset(int arg) {
    ::reset(arg);
if(arg) return;
    set_name("Human Fighter");
    set_race("human");
    set_alt_name("human");
    set_gender(1);
    set_alias("human","fighter");
    set_short("Human fighter");
    set_long(
"A Human fighter who guards the entrance to the lower levels.  He stares "+
"out at you through his visor as he unflinchingly guards the way to the lower "+
"levels.  He is wearing a heavy chainmail of fine wrought steel.\n");
    set_level(30);
    set_al(-40);
    set_aggressive(1);
    move_object((clone_object(si+"/long_sword.c")),TO);
    move_object((clone_object(si+"/long_sword.c")),TO);
    move_object((clone_object(si+"/chainmail.c")),TO);
    move_object((clone_object(si+"/helmet.c")),TO);
    init_command("wield sword");
    init_command("wear chainmail");
    init_command("wear helmet");
}
