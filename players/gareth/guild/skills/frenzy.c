#include "/players/gareth/define.h"

frenzy() {
  object shadow;
  int lasting;

  if(TP->query_ghost()) {
    write("You suddenly realize that this was a great mistake.\n" +
          "The whole room is spinning around you.\n" +
          "You decide to run as far as you can to leave this place.\n");
    TP->run_away();
    TP->run_away();
    write("As you feel your mind clearing you decide to rest for a moment.\n");
    return 1;
  }

  if(TP->query_level() < 18) {
    write("You are not strong enough yet.\n");
    return 1;
  }
  if (!TP->query_attack()) {
      write(" But you are not fighting anyone.\n");
      return 1;
  }
  if (TP->berzerk_shad()) {
     write("You are as berzerk as anyone can be.\n");
     return 1;
  }
  if(TP->block_shad()) {
        write("You cannot berzerk whilst you are blocking.\n");
        return 1;
        }

  if (TP->query_spell_points()<40) {
     write("You are too tired to go berzerk.\n");
     return 1;
  }

    write("You turn into a rampaging FRENZY!!\n");
    TP->restore_spell_points(-40);
    say(TPN+" turns into a raging berzerker!!\n");
    lasting=(50 + TP->query_level() + TP->query_con());
    shadow = CO("/players/gareth/guild/skills/berzerk_shad");
    shadow->start_shadow(TP,lasting,"berzerk_shad");
    return 1;
}
