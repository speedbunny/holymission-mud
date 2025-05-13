inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
reset() {

  ::reset();
      set_alias("annwn");
      set_name("annwn");
      set_race("fairy");
      set_short("annwn");
      set_long("This tiny little annwn is a type of fairy that loves the trees "+
	       "of the woods.  She is dancing among the leaves.\n");
      set_level(39+ random(10));
      set_al(200);
      set_gender(2);
      add_money(2500 + random(300));
}
