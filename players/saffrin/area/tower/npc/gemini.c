inherit "obj/monster";
#include "/players/saffrin/defs.h"

reset(){

  ::reset();
  set_name("gemini fairy");
  set_race("fairy");
  set_short("gemini fairy");
  set_alias("fairy");
  set_alt_name("gemini");
  set_long("This is a tiny gemini fairy with large sparkling amber "+
           "eyes.  She has long silver wings with violet tips.  Her "+
           "full lips are drawn up into a warm smile.  She is one of "+
           "a set of twins.\n");
  set_level(22);
  set_size(1);
  set_gender(2);
  add_money(3876);
}
