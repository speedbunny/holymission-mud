inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
void reset(int arg){

  ::reset(arg);
  if(arg) return;
      set_alias("attrocrope");
      set_name("attrocrope");
      set_race("fairy");
      set_short("A attrocrope");
      set_long("This is a tiny fairy who is has the head of a fairy and the body of a snake.  "+
               "She has has beautifully colored scales.\n");
      set_level(45 + random(5));
      set_al(50);
      set_aggressive(0);
      set_gender(2);
      add_money(1000 + random(500));
}
