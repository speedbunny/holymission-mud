inherit "obj/monster";
#include "/include/defs.h"

int fcount;

void reset(int arg)
{
::reset(arg);

    if (arg) return;
    fcount=0;
    set_name("trout");
    set_alt_name("fish");
    set_race("fish");
    set_short("A brook trout");
    set_long("This yellow-gold fish is spotted with red and yellow along its\n" 
           + "sides, and has faint black wavy lines along its back.\n\n");
    set_gender(1);
    set_level(1);
    set_hp(50);
    set_ac(0);
    set_wc(5);
    set_dead_ob(TO);
}

heart_beat() {
  if(++fcount>8) {
    random_move();
    fcount=0;
  }
  ::heart_beat();
}
