inherit "room/room";
 
#define NAME       "Qclxxiv"
#define TITLE      "Negus "
#define IFULLNAME  "Negus Qclxxiv"
#define DEST       "room/plane8"
#define ENTRANCE   "players/qclxxiv/entrance"
#define TO         this_object()
#define TP         this_player()
#define QN         query_name()
 
/*
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 */
object jjgen, ivgen;
mixed *quests;
 
void init_quest_array();

void reset(int arg) {
  if(arg) return;
 
  set_light(1);
  short_desc="A Giant 7-fingered leaf, rising fromout the ground";
  long_desc=
    "This giant 7-fingered leaf is the castle of " + TITLE + NAME +
    ". For generations and generations the Q's have domiciled here. "+
    "The ancient leaf is extremely large, yet still flourishing and "+
    "green, and has a strong magic feeling about it. The top reaches "+
    "so high you can see only the vague contours of it. The gates "+
    "are opened.\n";
  items=({
    "castle","@@short",
        });
#ifdef TESTSITE
  move_object(TO, DEST);
  /* force load */
  call_other("/players/qclxxiv/obj/drdlcks", "???");
  call_other("/players/qclxxiv/obj/qmunicator", "???");
  call_other("/players/qclxxiv/obj/ganjasoul", "???");
  call_other("/players/qclxxiv/qquest/themap", "???");
  call_other("/players/qclxxiv/copies/mytrace", "???");
#endif
  init_quest_array();
/*
  ivgen = clone_object("/players/qclxxiv/ivgen");
  move_object(ivgen, TO);
  jjgen = clone_object("/players/qclxxiv/jjgen");
  move_object(jjgen, TO);
*/
}
 
void init() {
  ::init();
  add_action("_enter", "enter");
}
 
int _enter(string str) {
  object maker;
 
  if(str=="gates" || str=="leaf" || str== "castle") {
#ifdef TESTSITE
    call_other(TP, "move_player", "into castle#" +ENTRANCE);
    move_object(TO, DEST);
    if(maker = find_player("qclxxiv")) {
      if(maker != TP) {
        tell_object(maker, ">>>>>"+ TP->QN+" entered the castle.\n");
      }
    }
#endif
    return 1;
  }
  if(!id(str))
    return 0;
  write("Dost thou mean 'enter gates'?\n");
#ifdef TESTSITE
  move_object(this_object(), DEST);
#endif
  return 1;
}
 
/* ******************************************************************** */
 
void init_quest_array() {
 
  quests=({
    ({
    "island_dragon", "Free the 7-fingered leaf of the Island Dragon!",
    "In the region of the Q's, inside the giant seven-fingered leaf,\n" +
    "since ages ago a terrible dragon lives, isolated in the most\n" +
    "beautiful part of the leaf. The local people there are still\n" +
    "hoping for a brave, wise, and persevering adventurer, to finally\n" +
    "free them from this ugly dragon.\n\n" +
    "Requires: Intelligence, Perseverance, Patience, and at to be at\n" +
    "least level 4.\n",
    65
    }),
         });
}
 
/*
void make_quest() {
  object q;
  int i;
 
  move_object(TO, "room/quest_room");
  for(i=0;i<sizeof(quests);i++) {
    if(!present(quests[i][0]), environment()) {
      q=clone_object("obj/quest_obj");
      q->set_id("quest");
      q->set_name(quests[i][0]);
      q->set_short_hint(quests[i][1]);
      q->set_hint(quests[i][2]);
      q->set_weight(quests[i][3]);
      q->add_quest();
    }
  }
#ifdef TESTSITE
  move_object(TO, DEST);
#else
  move_object(TO, "/players/qclxxiv/workroom");
#endif
}
*/

