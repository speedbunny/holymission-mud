#include "/players/beelzebub/misc/defs.h"

start_heal() {
  call_out("heal_me", 2);
  }

drop() {return 1;}

id(a) {return a=="med_obj";}

init() {
  add_action("dont_block","",1);
}

dont_block(arg) { 
  switch(query_verb()) {
    case "say":
    case "who":
    case "look":
    case "l":
    case "score":
    case "i": 
    case "ninja":
    case "rwhere":
    case "wakeup":
       return;
    default:
       write("You are meditating, type 'wakeup' to finish.\n");
  }
  return 1;
}

heal_me() {
  environment()->heal_self(10);
  call_out("heal_me", 2);
}

