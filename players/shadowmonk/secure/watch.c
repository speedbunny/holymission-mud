inherit "/obj/armour";

#include "lw.h"
#include "/players/matt/defs.h"

#define TICK "/obj/tick"

drop(arg) {
  if(!arg) {
    write("As you drop the watch, someone walks by and steps on it!\n");
    say(TP->SNAME + " drops " + TP->POS + " watch, and you accidentally " +
	"step on it.\n");
  }
  destruct(TO);
  return 1;
}

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("small watch");
  set_alias("watch");
  set_short("Small watch");
  set_long("This is a magical black watch. Commands are:\n" +
	   "  - reboot:    Shows you time left until reboot\n" +
	   "  - localtime: Shows you the local Mud time\n\n" +
	   "Enjoy!  - Matt\n");
  set_type("watch");
  set_ac(0);
  set_weight(1);
  set_value(100);
}

init() {
  ::init();
  if(!living(ENV(TO))) destruct(TO);
  worn = 1;
  worn_by = TP;
  add_action("show_reboot", "reboot");
  add_action("show_time", "localtime");
}

show_reboot(arg) {
  if(!arg) {
    write("You look at your watch.\n");
    say(TP->NAME + " looks at " + TP->POS + " watch.\n");
    return TICK->qry_timer();
  }
}

show_time(arg) {
  if(!arg) {
    write("You look at your watch.\n");
    say(TP->NAME + " looks at " + TP->POS + " watch.\n");
    write("The local time is " + ctime(time()) + ".\n");
    return 1;
  }
}

