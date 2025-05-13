#include "/players/matt/definitions"

string type, extra_string;

id(arg) {
  return arg == "prism" || arg == "diamond prism" ||
    arg == type + "diamond" || arg == type + " prism";
        }

short() {
  return CAP(type) + " prism (diamond)";
        }

long() {
  write("This is a beautiful hollow Prism whose exterior is made of\n");
  write("solid diamond. ");
  write(extra_string);
       }

get() { return 1; }

drop() {
  write("You drop the prism.\n");
  say(TP->NAME + " drops " + TP->POS + " Prism.\n");
  TELLR(ENV(TP), "It shatters into a thousand shards.\n");
  destruct(TO);
  return 1;
       }

reset(arg) {
  if(arg) return;
  type = "empty";
  extra_string = "It is empty, though you can probably fill it.\n";
           }

init() {
  add_action("fill", "fill");
       }

fill(arg) {
  string contents;
  if(id(arg)) {
    write("Fill prism with what?\n");
    return 1;
              }
  contents = ENV(TP)->query_diamond_fill();
  if(contents && arg == "empty prism with " + contents ||
     arg == "prism with " + contents) {
    if(type == "empty") {
      ENV(TP)->fill_it(TO);
      return 1;
                        }
    if(!present("emptydiamond", TP)) {
      write("The prism is already full.\n");
      return 1;
                                     }
                                      }
          }

set_type(arg) {
  type = arg;
  return 1;
              }
set_extra(arg) {
  extra_string = arg;
  return 1;
               }

query_weight() { return 1; }
