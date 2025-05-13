inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
void reset(int arg){

  ::reset(arg);
  if (!arg) {
      set_name("ghost of King Hamlet");
      set_alias("king");
      set_race("ghost");
      set_short("The Ghost of King Hamlet");
      set_long("The ghost of the murdered king of Denmark.  He is wearing a long flowing cloth\n"+
                 "of white.  He face is pale and drawn.\n");
      set_level(50);
      set_ac(15);
      set_wc(35);
      set_al(-1000);
      set_aggressive(1);
      set_gender(1);
      add_money(5000 + random(1000));
  }
}
