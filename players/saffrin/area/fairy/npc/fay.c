inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
void reset(int arg){

  ::reset(arg);
  if (arg) return;
      set_alias("fay");
      set_name("fay");
      set_race("fairy");
      set_short("A fay");
      set_long("A small fay who is a variety of fairy.  She is a trickster and loves to play "+
               "pranks on the other fairies of the land.\n");
      set_level(23 + random(5));
      set_al(50);
      set_aggressive(0);
      set_gender(2);
      add_money(700 + random(500));
}
