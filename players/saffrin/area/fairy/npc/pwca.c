inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
void reset(int arg){

  ::reset(arg);
  if(arg) return;
      set_alias("pwca");
      set_name("pwca");
      set_race("fairy");
      set_short("A pwca");
      set_long("A small pwca who is a variety of fairy.  He is a trickster and loves to play "+
               "pranks on the other fairies of the land.\n");
      set_level(23 + random(5));
      set_al(50);
      set_aggressive(0);
      set_gender(2);
      add_money(400 + random(500));
}
