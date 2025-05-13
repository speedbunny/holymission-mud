inherit "obj/treasure";

#define GM "guild/master"
#include "/players/sauron/std_defs.h"

int hands_washed, mouth_rinsed, is_medi;

void set_is_meditating(int i) {
  is_medi=i;
}

int query_is_meditating() {
  return is_medi;
}

set_hands_washed() {
  hands_washed=1;
}

query_hands_washed() {
  return hands_washed;
}

set_mouth_rinsed() {
  mouth_rinsed=1;
}

query_mouth_rinsed() {
  return mouth_rinsed;
}

start_meditate() { 
   set_is_meditating(1);
   add_action("do_nothing","",1);
   add_action("do_wakeup","wakeup");
   WRITE("You are one now with the void and can <concentrate> on the"
        +" deities.\n" );
   MOVEO(TO,ENV(TO));
}

int do_wakeup() {
   if(!query_is_meditating()) {
    return 0;
  }
  WRITE("You stop meditating and stand up.\n");
  say(lw(CTPN+" stops meditating and stands up.\n"));
  set_is_meditating(0);
  return 1;
}

int do_concen(string str){
  if(str=="on susano-o" || str=="on susano-O" || str=="on Susano-O") {
    if(TP->query_ghost() && TP->query_religion()=="Amaterasu") {
      WRITE("You concentrate on Susano-O...\n"
           +"Suddenly you feel new life floating into you.\n" );
      TP->remove_ghost();
      return 1;
    }
    WRITE("You concentrate on Susano-O ...\n"
         +"But nothing happens.\n");
      return 1;
  }
  WRITE("Amaterasu growls: Seek my centre of learning in a land to the"
       +" east mortal.\n");
  return 1;
}

int do_nothing(string str){
  if(query_is_meditating()) {
    WRITE("You cannot do this while being one with the void!\n"
         +"Type \"wakeup\" to wake up.....\n");
    return 1;
  }
}

void reset(int arg) {
  ::reset(arg);
  name="puri_check";
}

void init() {
  ::init();
  add_action("do_nothing","",1);
  add_action("do_wakeup","wakeup");
  add_action("do_concen","concentrate");
}
