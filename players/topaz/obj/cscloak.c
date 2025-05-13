inherit "obj/armour";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("cloak");
    short_desc="A Color shifting cloak";
    long_desc="This cloak seems to continuously shift colors as you look at it.\n" +
              "It radiates a strange energy.\n";
    set_alias("color shifting cloak");
    set_type("cloak");
    set_ac(1);
    set_weight(1);
    set_value(800);
  }
return 1;
}

int wear(string arg) {
  set_heart_beat(1);
  return::wear(arg);
}

int remove(string arg) {
  set_heart_beat(0);
  return::remove(arg);
}

int drop(string arg) {
  set_heart_beat(0);
  return::drop(arg);
}

void heart_beat() {
  write("Your cloak shifts color.\n");
  say(TP->query_name() + "'s cloak shifts color.\n");
}
