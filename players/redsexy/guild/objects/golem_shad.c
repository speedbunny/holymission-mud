#include "/players/redsexy/guild/crdefs.h"
#include "/players/redsexy/guild/functions.h"
#include "/players/redsexy/guild/formulae.h"

object master;
object golem;

void start_shadow(object mast, object gol) {
  object oldshad;

  master = mast;
  golem = gol;
  oldshad = shadow(master, 0);
  if(oldshad && oldshad->query_golem_shadow()) destruct(oldshad);
  shadow(master, 1);
}

int hit_player(int dam, int type) {
  object foe;

  if(!golem) {
    destruct(TO);
    return 1;
  }
  foe = master->query_attack();
  if(foe && (ENV(foe) == ENV(golem)) && (random(100) < DEF_CHANCE)) {
    TELL(master, "Your " + golem->NAME + " absorbs " + foe->NAME +
	 "'s blow!\n");
    say(golem->SHORT + " absorbs " + foe->NAME + "'s blow!\n", master);
    say(foe->NAME + " hits " + golem->NAME + ".\n");
    golem->hit_player(dam, type);
    return 0;
  }
  return (int)master->hit_player(dam, type);
}

query_golem_shadow() { return 1; }
