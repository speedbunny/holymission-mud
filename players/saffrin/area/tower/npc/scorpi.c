inherit "obj/monster";
#include "/players/saffrin/defs.h"

reset(){

  ::reset();
  set_name("scorpio fairy");
  set_race("fairy");
  set_short("scorpio fairy");
  set_alias("fairy");
  set_alt_name("scorpio");
  set_long("This is a tiny scorpio fairy with large sparkling dark brown "+
           "eyes.  She has long silver wings with violet tips.  Her "+
           "full lips are drawn up into a warm smile.\n");
  set_level(17);
  set_size(1);
  set_gender(2);
  add_money(1698);
}
