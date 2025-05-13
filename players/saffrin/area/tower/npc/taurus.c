inherit "obj/monster";
#include "/players/saffrin/defs.h"

reset(){

  ::reset();
  set_name("taurus fairy");
  set_race("fairy");
  set_short("taurus fairy");
  set_alias("fairy");
  set_alt_name("taurus");
  set_long("This is a tiny taurus fairy with large sparkling violet "+
           "eyes.  She has long silver wings with aqua tips.  Her "+
           "full lips are drawn up into a warm smile.\n");
  set_level(11);
  set_size(1);
  set_gender(2);
  add_money(633);
}
