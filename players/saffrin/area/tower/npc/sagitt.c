inherit "obj/monster";
#include "/players/saffrin/defs.h"

reset(){

  ::reset();
  set_name("sagittarius fairy");
  set_race("fairy");
  set_short("sagittarius fairy");
  set_alias("fairy");
  set_alt_name("sagittarius");
  set_long("This is a tiny sagittarius fairy with large sparkling light brown "+
           "eyes.  She has long silver wings with violet tips.  Her "+
           "full lips are drawn up into a warm smile.\n");
  set_level(16);
  set_size(1);
  set_gender(2);
  add_money(1345);
}
