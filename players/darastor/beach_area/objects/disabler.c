/* Darastor's command disabler */
inherit "/obj/thing";
#include "/players/darastor/include/seaside.h"
int _comms(string str) {
  string VERB;
  int SET;
  VERB=query_verb();
  if((VERB=="say")||(VERB=="shout")||(VERB=="scream")) {
    tell_object(TP,"As soon as you open your mouth, you get a mouthful of water.\n");
  }
  else tell_object(TP,"You cannot do that while you are trying to stay afloat.\n");
  SET=1;
  return SET;
}
void reset(int arg) {
  set_name("disabler");
  set_weight(0);
  set_value(0);
}
void init() {
  ::init();
  add_action("_comms","",2);
} 
