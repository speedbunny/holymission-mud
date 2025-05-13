inherit "obj/monster";
#include "/players/saffrin/defs.h"

reset(){

  ::reset();
  set_name("aries fairy");
  set_race("fairy");
  set_short("aries fairy");
  set_alias("fairy");
  set_alt_name("aries");
  set_long("This is a tiny aries fairy with large sparkling emerald "+
           "eyes.  She has long silver wings with violet tips.  Her "+
           "full lips are drawn up into a warm smile.\n");
  set_level(12);
  set_size(1);
  set_gender(2);
  add_money(764);
}
