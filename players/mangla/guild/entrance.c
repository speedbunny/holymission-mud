#include "/players/mangla/defs.h"
inherit "room/room";

string room;
int gd;

int no_clean_up() {
  return 1;
}

int id(string str) { return str=="entrance"; }

void reset(int arg) {

  ::reset(arg);
  if (arg) return;

  short_desc = "A shimmering entrance to the north";
  long_desc = "You get a feeling of Power and force floating " +
              "through your mind.\n";
  gd = GM->query_number("jedi");
  room = "players/mangla/guild/room";
  MOVE(TO,"players/redsexy/jedi/areas/island/other/t2");
}

void init() {
  add_action("move","north");
} 

int move(string str) {

  if (!str && query_verb()=="north" || str=="north") {
     TP->MOVEP("north#"+room);
     return 1;
  }
}
