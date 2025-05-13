inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
reset(arg) {

  ::reset(arg);
  if (arg) return;
      set_alias("lunatic");
      set_name("Lunatic man");
      set_race("man");
      set_short("Lunatic man");
      set_long("This lunatic is an inmate of the Elan Drac Asylum.  His eyes "+
	       "are wildly bloodshot.  There is a small amount of dribble "+
               "running down his chin.\n");
      set_level(20 + random(10));
      set_al(-100);
      set_aggressive(1);
      set_gender(1);
      add_money(2500 + random(500));
}
