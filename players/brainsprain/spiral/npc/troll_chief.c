
inherit "obj/monster";
#include "/players/brainsprain/spiral/spidef.h"
void reset(int arg) {
    ::reset(arg);
  if(arg) return;
    set_name("chief");
    set_race("troll");
    set_gender(1);
    set_alias("troll");
    set_short("A troll chief");
    set_long(
"A troll boss, his gnarled form misleads you as to his strength.  His six "+
"foot frames in condensed into about five feet.  The thick and knotted "+
"on his arms bulge as he moves.  A scar runs lengthwise down his jaw.\n");
    set_level(15);
    set_hp(550);
    set_al(-40);
    set_ac(6);
    set_wc(20);
    set_aggressive(1);
    move_object((clone_object(si+"/sceptert.c")),TO);
    init_command("wield scepter");
}
