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
  call_out("_shifts",3);
  return::wear(arg);
}

_shifts() {
 if(query_worn()) {
string color;
switch(random(4)) {
  case 0:
    color="orange";
    break;
  case 1:
    color="red";
    break;
  case 2:
    color="blue";
    break;
  case 3:
    color="white";
    break;
}
  write("Your cloak shifts its color to " + color + ".\n");
  say(TP->query_name() + "'s cloak shifts its color to " + color + ".\n");
  call_out("_shifts",3);
  return 1;
 }
 else {
  return 1;
 }
}
