inherit "obj/monster";
#include "/players/saffrin/defs.h"

reset(){

  ::reset();
  set_name("libra fairy");
  set_race("fairy");
  set_short("libra fairy");
  set_alias("fairy");
  set_alt_name("libra");
  set_long("This is a tiny libra fairy with large sparkling hazel "+
           "eyes.  She has long silver wings with violet tips.  Her "+
           "full lips are drawn up into a warm smile.\n");
  set_level(18);
  set_size(1);
  set_gender(2);
  add_money(2111);
}
