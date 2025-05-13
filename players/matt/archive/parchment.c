#include "/players/matt/definitions"

id(arg) {
  return arg == "parchment";
        }

short() {
  return "An old, tattered parchment";
        }

long() {
  write("This is an extremely old piece of paper, surviving what must\n");
  write("have been eons of time. Though the writing is old and faded,\n");
  write("you could probably still read it.\n");
       }

get() { return 1; }

drop() {
  write("You drop the parchment.\n");
  say(TP->NAME + " drops " + TP->POS + " parchment.\n");
  TELLR(ENV(TP), "It crumbles to dust.\n");
  destruct(TO);
  return 1;
       }

init() {
  add_action("read", "read");
       }

read(arg) {
  if(id(arg)) {
    write("You read the parchment. It says:\n");
    write("    Greetings young adventurer. My name is Aeternus, a former\n");
    write("Summoner of old. I am writing this as I lay here, crippled\n");
    write("amidst a spent avalanche. The War is terrible, and I fear\n");
    write("I may be the only one to survive.\n");
    write("    I write to you, the hope of the future, so that you may\n");
    write("restore that which I regret may be lost by the time you read\n");
    write("this. The powers unleashed in the War have sundered our\n");
    write("source of strength, the Prism of Elements; you must find the\n");
    write("sundered pieces and somehow forge them back together to\n");
    write("restore us.\n");
    write("    I have buried some things away in the mountain circle.\n");
    write("I pray they are still there. Go now, and begin your search.\n");
    write("        - Aeternus\n\n");
    write("There is a map scrawled at the bottom of the parchment,\n");
    write("showing you where to dig.\n");
    return 1;
              }
          }
