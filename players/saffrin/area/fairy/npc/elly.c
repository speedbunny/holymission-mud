inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
object shell;

void reset(int arg){

  ::reset(arg);
  if (arg) return;
      set_alias("ellyllon");
      set_name("ellyllon");
      set_race("fairy");
      set_short("A ellyllon");
      set_long("This cute little fairy is riding around on an egg shell.  "+
               "He is giggling wildly.\n");
      set_level(33 + random(5));
      set_al(50);
      set_aggressive(0);
      set_gender(1);
      add_money(1100 + random(500));
      shell=CLONE(FAIRY+"npc/eggshell");
      transfer(shell,TO);
}
