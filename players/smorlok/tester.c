

inherit "/obj/monster";
#include "/obj/obj_defs.h"

void reset(int arg){

  ::reset(arg);
  if(arg)return;
set_name("tester");
set_short("A tester");
set_long("The tester is here to test something.\n");
set_race("tester");
set_gender(0);
set_level(1);

set_al(0);
set_hp(10000000);

}

