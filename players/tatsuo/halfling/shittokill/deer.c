
inherit "obj/monster";

#include "/players/tatsuo/def.h"

void reset(int arg){
  ::reset(arg);
  
   if(arg) return;
  
  set_name("deer");  
  set_short("A wild deer");
  set_long("A beautiful wild deer graces the mountain path");
  set_level(3);
  set_al(30);
  set_race("halfling");
  set_size("small");
  set_gender(0);
  load_chat(8,({"The deer pauses to look at you, then continues grazing"}) );

  
 
}



