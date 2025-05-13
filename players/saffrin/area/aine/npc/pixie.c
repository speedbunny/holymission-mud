inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
reset() {

  ::reset();
      set_alias("pixie");
      set_name("pixie");
      set_race("fairy");
      set_short("pixie");
      set_long("This tiny little pixie is a type of fairy that has tiny "+
	       "wings on her back.  She is flutteringly around you.\n");
      set_level(33+ random(10));
      set_al(200);
      set_gender(2);
      add_money(2500 + random(100));
}
