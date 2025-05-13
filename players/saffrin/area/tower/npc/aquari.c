inherit "obj/monster";
#include "/players/saffrin/defs.h"

reset(){

  ::reset();
  set_name("aquarius fairy");
  set_race("fairy");
  set_short("aquarius fairy");
  set_alias("fairy");
  set_alt_name("aquarius");
  set_long("This is a tiny aquarius fairy with large sparkling grey "+
           "eyes.  She has long silver wings with violet tips.  Her "+
           "full lips are drawn up into a warm smile.\n");
  set_level(14);
  set_size(1);
  set_gender(2);
  add_money(921);
}
