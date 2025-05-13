#include "/players/matt/defs.h"

object target;

id(arg) { return "Imp"; }
short() { return "A grimy little imp"; }
long() { write("A grimy little imp staring at you mischievously.\n"); }

init() {
  add_action("annoy", "annoy");
  add_action("dest_me", "destruct");
  add_action("dest_me", "clear");
  add_action("dest_me", "id");
  add_action("dest_me", "id");
}

heart_beat() {
  if(target) {
    if(ENV(target) != ENV(TO)) {
      TELLR(ENV(TO), "Imp scurries away.\n");
      MOVE(TO, ENV(target));
      TELLR(ENV(TO), "Imp arrives.\n");
    }
      TELL(target, get_chat());
  }
}

annoy(arg) {
  if(TP->RNAME != "redsexy") return;
  set_heart_beat(1);
  target = find_player(arg);
  if(target) {
    write("You send the Imp after " + target->NAME + ".\n");
    return 1;
  }
  write("The Imp can't find that player.\n");
  return 1;
}

dest_me(arg) {
  if(id(arg) && (TP->RNAME != "redsexy")) return 1;
}

get_chat() {
  switch(random(10)) {
    case 0: return "EEEEEEEEEEEEEEEEheheheheheheheeee!!\n"; break;
    case 1: return "The imp bites your kneecap!\n"; break;
    case 2: return "Imp says: Aren't I annoying??\n"; break;
    case 3: return "Imp says: Ha ha, catch me if you can!\n"; break;
    case 4: return "Imp leers at you.\n"; break;
    case 5: return "Imp pees on your foot!\n"; break;
    case 6: return "The imp cackles with glee.\n"; break;
    case 7: return "The imp dances around.\n"; break;
    case 8: return "YAHAHAHAAAAAAAAaaaaaaaaaaaaaa!\n"; break;
    case 9: return "Imp says: You fool!\n"; break;
    }
}

