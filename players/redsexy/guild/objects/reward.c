#include "/players/redsexy/defs.h"

id(arg) {
  return arg == "pendant" || arg == "silver pendant";
        }

short() {
  return "Silver Pendant";
        }

long() {
  write("    This is a small pendant crafted of pure silver, a small\n");
  write("reward for returning the Summoners to the world. It allows\n");
  write("you to change your pretitle at will; just type:\n");
  write(" - pret        To view current pretitle\n");
  write(" - pret none   To remove your pretitle\n");
  write(" - pret <new>  To change your pretitle to <new>\n");
  write("    Enjoy.   - Matt\n");
       }

query_auto_load() { return "players/redsexy/guild/objects/reward:"; }
get() { return 1; }
drop() { return 1; }

init() {
  add_action("my_drop", "drop");
  add_action("pret", "pret");
       }

my_drop(arg) {
  if(id(arg)) {
    write("Just ask Matt if you want to get rid of your Pendant.\n");
    return 1;
              }
             }

pret(arg) {
  if(!arg) {
    if(TP->query_pretitle() && TP->query_pretitle() != "") {
      write("Your current pretitle is \"" + TP->query_pretitle() + "\".\n");
      return 1;
                                                           }
    write("You have no pretitle.\n");
    return 1;
           }
  if(arg == "none") {
    TP->set_pretitle("");
    write("You remove your pretitle.\n");
    return 1;
                    }
  TP->set_pretitle(arg);
  write("You set your pretitle to \"" + arg + "\".\n");
  return 1;
          }
