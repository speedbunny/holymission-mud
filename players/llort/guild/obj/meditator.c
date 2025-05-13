#include "../tune.h"
object magesoul;

set_dur(dur,soul) {
  if(!soul) return;
  call_out("heal_me",HEAL_TIME);
  call_out("dest_me",dur);
  soul->set_meditate(1);
  magesoul=soul;
}

drop() { return 1; }

id(a) { return a=="soul"; }

init() {
  add_action("nil","",1);
}

/* ########	the input comes here if the mage is meditating 	######## */

nil(arg) { 
  switch(query_verb()) {
    case "whisper":
    case "who":
    case "look":
    case "l":
    case "score":
    case "i": 
    case "mage":
    case "help":
    case "hp":
       return;
    case "wake_up":
       if(!environment()->query_immortal()) return 1;
       dest_me();
       break;
    default:
       write("You can't do that while meditating.\n");
  }
  return 1;
}

heal_me() {
  environment()->heal_self(HEAL_RATE);
  call_out("heal_me",HEAL_TIME);
}

dest_me() {
  tell_room(environment(environment()),environment()->query_name()+
      " awakes and rises. "+capitalize(environment()->query_pronoun())+
      " looks refreshed.\n");
  magesoul->set_meditate(0);
  destruct(this_object());
  return 1;
}
