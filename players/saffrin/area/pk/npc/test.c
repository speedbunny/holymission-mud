inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
reset(arg) {

  ::reset(arg);
  if (arg) return;
      set_alias("lunatic");
      set_name("Lunatic woman");
      set_race("woman");
      set_short("Lunatic woman");
      set_long("This lunatic is an inmate of the Elan Drac Asylum.  Her eyes "+
	       "are wildly bloodshot.  There is a small amount of dribble "+
               "running down her chin.\n");
      set_level(20 + random(15));
      set_al(-100);
      set_aggressive(1);
      set_gender(2);
      add_money(2500 + random(500));
      set_random_move();
}
