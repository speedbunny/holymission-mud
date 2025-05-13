inherit "obj/monster";
#include "/players/saffrin/defs.h"

reset(){

  ::reset();
  set_name("garden fairy");
  set_race("fairy");
  set_short("garden fairy");
  set_alias("fairy");
  set_alt_name("garden");
  set_long("This is a tiny garden fairy with large sparkling green "+
           "eyes.  She has long silver wings with violet tips.  Her "+
           "full lips are drawn up into a warm smile.\n");
  set_level(10);
  set_size(1);
  set_gender(2);
  add_money(541);
}
