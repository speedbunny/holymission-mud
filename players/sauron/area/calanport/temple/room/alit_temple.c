inherit "room/room";

#include "/players/sauron/std_defs.h"
#define RIGHT_AL ((int)this_player()->query_alignment() > 99)

int pray_to_god() {
  if(TPREL=="Alitist") {
    WRITE("You pray to your God.\n");
    say(lw(CTPN+" prays to "+HIS+" God.\n"));
    if(TP->query_ghost())
      TP->remove_ghost();
    return 1;
  }
  if(!RIGHT_AL) {
    TELLR(TO,lw("A voice booms: You are too evil to worship me.\n"));
    return 1;
  }
  TELLR(TO,lw("A voice booms: You do not follow me.\n"));
  return 1;
}

void reset(int arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc="Alitist Temple";
    long_desc="This is an Alitist temple. It's well lit from a glowing in the"
             +" walls, and there is a large sacrificial altar in the south"
             +" wall. Perhaps you should sacrifice something on it?\n";
    dest_dir=({
      "players/moonchild/guild/room","northeast"
    });
    items=({
      "temple","A temple to the good barbarian God, Alit",
      "walls","They glow with the light of good",
      "altar","You should probably sacrifice something on it"
    });
  }
}

void init() {
    ::init();
    add_action("pray_to_god", "pray");
}
