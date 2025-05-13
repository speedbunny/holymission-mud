inherit "obj/monster";
#include "/players/saffrin/defs.h"

reset(){

  ::reset();
  set_name("Elizabeth Bathory");
  set_race("human");
  set_short("Elizabeth Bathory");
  set_alias("elizabeth");
  set_alt_name("bathory");
  set_long("This is the blood-sucking Countess of Cahtice who enjoys "+
           "using blood of her victims to preserve her youth.  Maybe "+
           "you can be part of her next blood bath.\n");
  set_level(50 + random(25));
  set_gender(2);
  add_money(6000 + random(500));

  MOVE(CLONE(PK+"obj/dagger"),TO);
      init_command("wield dagger");
}
