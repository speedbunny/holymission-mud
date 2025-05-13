inherit "obj/monster";
#include "/players/saffrin/defs.h"

reset(){

  ::reset();
  set_name("capricorn fairy");
  set_race("fairy");
  set_short("capricorn fairy");
  set_alias("fairy");
  set_alt_name("capricorn");
  set_long("This is a tiny capricorn fairy with large sparkling aqua "+
           "eyes.  She has long silver wings with violet tips.  Her "+
           "full lips are drawn up into a warm smile.\n");
  set_level(15);
  set_size(1);
  set_gender(2);
  add_money(1099);
}
