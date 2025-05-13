inherit "obj/monster";
#include "/players/saffrin/defs.h"

reset(){

  ::reset();
  set_name("cancer fairy");
  set_race("fairy");
  set_short("cancer fairy");
  set_alias("fairy");
  set_alt_name("cancer");
  set_long("This is a tiny cancer fairy with large sparkling brown "+
           "eyes.  She has long silver wings with violet tips.  Her "+
           "full lips are drawn up into a warm smile.\n");
  set_level(21);
  set_size(1);
  set_gender(2);
  add_money(3443);
}
