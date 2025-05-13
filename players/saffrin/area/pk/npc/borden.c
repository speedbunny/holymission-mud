inherit "obj/monster";
#include "/players/saffrin/defs.h"

reset(){

  ::reset();
  set_name("Lizzie Borden");
  set_race("human");
  set_short("Lizzie Borden");
  set_alias("lizzie");
  set_alt_name("borden");
  set_long("She has a permenant frown on her face.  She is dressed from "+
           "head to toe in all black.  Her hair is pulled back into a tight "+
           "bun at the nape of her neck.\n");
  set_level(50 + random(25));
  set_gender(2);
  add_money(6000 + random(500));

  MOVE(CLONE(PK+"obj/axe"),TO);
      init_command("wield axe");
}
