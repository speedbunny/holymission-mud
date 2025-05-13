#include "/players/matt/defs.h"

int timer;
status alarmset;
object owner;

id(arg) { return arg == "watch" || arg == "alarm"; }
short() { return "A small pocket watch"; }
long() {
  string correct;

  if((timer / 60) == 1) correct = "";
  else correct = "s";
  write("This is a small silver watch on a chain.\n");
  write("The alarm currently shows " + (timer / 60) + " minute" +
	correct + ", " + (timer % 60) + " seconds left.\n");
  write("Commands:\n");
  write("  - set <minutes>: Sets the number of minutes,\n");
  write("  - alarm on:      Turns the alarm on\n");
  write("  - alarm off:     Turns the alarm off\n");
  write("     Enjoy!    - Matt\n");
}

init() {
  owner = TP;
  add_action("set", "set");
  add_action("alarm", "alarm");
  add_action("my_drop", "drop");
}

set(arg) {
  int val;
  string correct;

  if(!arg) {
    write("Syntax: set <minutes>\n");
    return 1;
  }
  sscanf(arg, "%d", val);
  if(val < 0) {
    write("The time must be positive.\n");
    return 1;
  }
  timer = val * 60;
  if(alarmset) set_heart_beat(1);
  if(val == 1) correct = "";
  else correct = "s";
  write("You set the alarm for " + val + " minute" + correct + ".\n");
  say(TP->NAME + " fiddles with " + TP->POS + " watch.\n");
  return 1;
}

alarm(arg) {
  if(arg == "on") {
    if(alarmset)
      write("The alarm is already on.\n");
    else {
      write("You turn the alarm on.\n");
      say(TP->NAME + " fiddles with " + TP->POS + " watch.\n");
      alarmset = 1;
      set_heart_beat(1);
    }
    return 1;
  }
  if(arg == "off") {
    if(!alarmset)
      write("The alarm is already off.\n");
    else {
      write("You turn the alarm off.\n");
      say(TP->NAME + " fiddles with " + TP->POS + " watch.\n");
      alarmset = 0;
      set_heart_beat(0);
    }
    return 1;
  }
}

my_drop(arg) {
  if(id(arg)) {
    write("You probably don't want to drop that.\n");
    write("If you want to get rid of it, just tell Matt.\n");
    return 1;
  }
}

heart_beat() {
  int i;
  object inv;
  
  if(timer <= 0) {
    TELL(owner, "Your watch starts beeping madly!\n");
    inv = all_inventory(ENV(owner));
    for(i = 0; i < sizeof(inv); i++)
      if(inv[i] != owner)
	TELL(inv[i], owner->NAME + "'s watch beeps loudly!\n");
  }
  else timer -= 2;
}

get() { return 1; }
drop() { return 1; }

query_auto_load() { return "/players/matt/objects/tools/alarmwatch:"; }
query_weight() { return 1; }


  
