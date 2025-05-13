inherit "obj/monster";
#include "/players/saffrin/defs.h"

reset(){

  ::reset();
  set_name("Marquis de Sade");
  set_race("human");
  set_short("Marquis de Sade");
  set_alias("marquis");
  set_alt_name("sade");
  set_long("This is a sensous looking man wiht long, slim fingers and "+
           "hypnotic blue eyes.  He gives you a look that makes you feel "+
           "as if he has undressed you with those eyes.\n");
  set_level(50 + random(25));
  set_gender(1);
  add_money(6000 + random(500));

  MOVE(CLONE(PK+"obj/whip"),TO);
      init_command("wield whip");
}
