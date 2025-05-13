#include "/players/matt/definitions"

id(arg) {
  return arg == "chalk" || arg == "piece of chalk";
        }

short() {
  return "Chalk";
        }

long() {
  write("A small piece of white chalk.\n");
       }

get() { return 1; }
drop() {
  write("You drop the chalk.\n");
  say(TP->NAME + " drops a piece of chalk.\n");
  TELLR(ENV(TP), "It disintegrates and sinks into the ground.\n");
  destruct(TO);
  return 1;
       }
