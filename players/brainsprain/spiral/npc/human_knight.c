inherit "obj/monster";
#include "/players/brainsprain/spiral/spidef.h"
void reset(int arg) {
    ::reset(arg);
if(arg) return;
    set_name("knight");
    set_race("human");
    set_gender(1);
    set_alias("human");
    set_short("Human knight");
    set_long(
"A massive figure stands here clad in a steel chainmail.  His sword gleams "+
"in the light.   His long blond hair and carefully trimmed mustaches "+
"mark him as a proud man.  He hold his buckler in front of his chest and "+
"paces.\n");
    set_level(17);
    set_hp(800);
    set_al(-40);
    set_ac(8);
    set_aggressive(1);
    set_wc(24);
    move_object((clone_object(si+"/bastardsword.c")),TO);
    move_object((clone_object(si+"/chainmail.c")),TO);
    move_object((clone_object(si+"/boots.c")),TO);
    move_object((clone_object(si+"/buckler.c")),TO);
      init_command("wield sword");
      init_command("wear chainmail");
      init_command("wear boots");
      init_command("wear buckler");
}
