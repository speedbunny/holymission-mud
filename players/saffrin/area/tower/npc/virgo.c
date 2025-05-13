inherit "obj/monster";
#include "/players/saffrin/defs.h"

reset(){

  ::reset();
  set_name("virgo fairy");
  set_race("fairy");
  set_short("virgo fairy");
  set_alias("fairy");
  set_alt_name("virgo");
  set_long("This is a tiny virgo fairy with large sparkling hazel "+
           "eyes.  She has long silver wings with violet tips.  Her "+
           "full lips are drawn up into a warm smile.\n");
  set_level(19);
  set_size(1);
  set_gender(2);
  add_money(2523);
}
