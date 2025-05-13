#include "/players/matt/definitions"

object owner;

id(arg) {
  return arg == "scroll";
        }

short() {
  return "Scroll";
        }

long() {
  write("    This is a rolled-up scroll, sealed with black wax.\n");
  write("You should give it to Matt as soon as possible.\n");
       }

get() { return 1; }
drop() { return 1; }
query_auto_load() { return "players/matt/guild/objects/scroll:"; }

init() {
  add_action("break_it", "break");
  add_action("give", "give");
       }

break_it(arg) {
  if(arg == "seal") {
    if(TP->RNAME == "matt") {
      write("You break the seal.\n");
      say(TP->NAME + " breaks the seal on the scroll.\n");
      write("Remember to:\n");
      write(" - add " + owner->SNAME + " to the lore.\n");
      write(" - link rooms/mountains/circle to guild/rooms/anteroom\n");
      write(" - put " + owner->SNAME + "'s name on the guildroom plaque.\n");
      write(" - put " + owner->SNAME + "'s name on the questions list.\n");
      say(TP->NAME + " unrolls the scroll, then reads it thoughtfully.\n");
      return 1;
                            }
    write("Only Matt can break the seal.\n");
    return 1;
                    }
  write("Break what?\n");
  return 1;
           }

give(arg) {
  object master;
  if(arg == "scroll to matt") {
    master = find_player("matt");
    if(master && (ENV(master) == ENV(TP))) {
      write("You give the scroll to Matt.\n");
      say(TP->NAME + " gives the scroll to Matt.\n");
      owner = TP;
      MOVE(TO, master);
      return 1;
                                           }
    write("Matt is not here.\n");
    return 1;
                              }
          }
