inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
void reset(int arg){

  ::reset(arg);
  if(arg) return;
      set_alias("duendes");
      set_name("duendes");
      set_race("fairy");
      set_short("A duendes");
      set_long("This is an old haggy looking female fairy who hates all other "+
                "creatures because they are more beautiful than she.\n");
      set_level(40 + random(5));
      set_al(50);
      set_aggressive(1);
      set_gender(2);
      add_money(750 + random(500));
}
