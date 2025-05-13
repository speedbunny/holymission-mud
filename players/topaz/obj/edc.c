#define TP     environment(this_object())
#define CAP    capitalize
#define NAME   query_name()
#define RNAME  query_real_name()
#define POS    query_possessive()

int id(string arg) {
    return arg == "sender" || arg == "doll sender";
        }

string query_auto_load() {
  return "players/topaz/to/sender2:";
                  }

string short() {
  return CAP(TP->RNAME) + "'s Doll Sender";
        }

void long() {
  write("    This Doll Sender belongs to " + TP->NAME + ".\n");
  write("This is an doll sender.\n");
  write("It can send a doll to someone else.\n");
       }

int get() {
  return 1;
      }

int drop() {
  return 1;
       }

void init() {
  add_action("senderhelp", "senderhelp");
  add_action("send_object", "send");
       }

int senderhelp() {
  write("Syntax for this sender is:\n\n");
  write(" - send <player> doll\n\n");
  return 1;
             }

int send_object(string arg) {
  string player;
  string sobj;
  object receiver;
  object doll;
  if(sscanf(arg, "%s %s", player, sobj) == 2) {
    receiver = (find_player(player));
    if(receiver) {
        transfer(doll=clone_object("/players/moonchild/wedding/ring"),receiver);
        write("You sent " + receiver->NAME + " a razor.\n");
	  say(TP->NAME + " sends an object with " +
	      TP->POS + " object sender.\n");
        tell_object(receiver, TP->NAME + " sent you a ring.\n");
	  return 1;
      }
      write("Cannot find that player.\n");
      return 1;
    }
    write("Type senderhelp for help.\n");
    return 1;
}
