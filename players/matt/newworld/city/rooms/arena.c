inherit "room/room";

#include "/players/matt/defs.h"
#include "lw.h"

#define COST    1000
#define STANDS  (NWCITY + "rooms/stands")
#define RESP    30

status chal;
status fighting;
// int exp1;
// int exp2;
object glad1;
object glad2;
object shad1;
object shad2;

void reset(int arg);
void init();
string watching();
int interact_filt(object obj);
int read(string arg);
int rules(string arg);
int challenge(string arg);
void end_chal();
void start_battle();
int accept(string arg);
int leave(string arg);
void end_battle(object winner);
void do_shout(object winner, object loser);
void end_fight();
int living_filt(object obj);
int player_filt(object obj);
void catch_tell(string str);
void exit(object obj);
string query_glads();
object query_other_glad(object obj);
int dump(string arg);

void reset(int arg) {
  if(arg) return;
  STANDS->dummy();
  enable_commands();
  set_light(1);
  short_desc = "Dyolf's Arena";
  long_desc =
    "    You stand in the middle of a large Arena near the center of\n" +
    "the city. The ground is hard-packed earth, scarred and darkened\n" +
    "by the blood of the countless gladiators who fought before you.\n" +
    "Hundreds of spectators fill the stands surrounding the Arena.\n";
  no_obvious_msg = "    A sign, scratched and bloodied, is posted on " +
    "one wall.\n";
  items = ({
    "arena", "A large, oval-shaped Arena built for sport and profit",
    "Arena", "A large, oval-shaped Arena built for sport and profit",
    "ground", "The dusty ground shows signs of many fierce battles",
    "earth", "Hard-packed earth forms the fighting surface of the Arena",
    "spectators", "@@watching",
    "stands", "Several layers of stands surround the Arena",
    "sign", "A worn sign. You should read it",
    "wall", "One of the walls has a worn sign on it",
    "walls", "One of the walls has a worn sign on it",
  });
  property = ({ "no_teleport", "no_fight" });
}

void init() {
  ::init();
  if(!interactive(TP)) return;
  if(glad1 && present(glad1, TO)) {
    if(glad2 && present(glad2, TO)) {
      write("You see that " + glad1->NAME + " and " + glad2->NAME +
	    " are already in the arena, so you go to the stands " +
	    "to watch them.\n");
      TP->MOVEP("to watch the battle from the stands#" + STANDS);
      return;
    }
    else {
      glad2 = TP;
      end_fight();
//      if(glad2) exp2 = glad2->query_exp();
    }
  }
  else {
    glad1 = TP;
    end_fight();
//    if(glad1) exp1 = glad1->query_exp();
  }
  add_action("read", "read");
  add_action("rules", "rules");
  add_action("challenge", "challenge");
  add_action("accept", "accept");
  add_action("leave", "leave");
  if(TP->query_immortal()) add_action("dump", "dump");
}

string watching() {
  int i;
  int sizeinv;
  string msg;
  object *inv;
  object stands;

  stands = find_object(STANDS);
  msg = "You glance up at the hundreds of people in the stands, and ";
  inv = filter_array(all_inventory(stands), "interact_filt", TO);
  sizeinv = sizeof(inv);
  if(!sizeinv)
    msg += "can make out no familiar faces";
  else if(sizeinv == 1)
    msg += "can pick out " + inv[0]->NAME + "'s face";
  else {
    msg += "can pick out the familiar faces of ";
    for(i = 0; i < (sizeinv - 1); i++)
      msg += inv[i]->NAME + ", ";
    msg += "and " + inv[sizeinv]->NAME;
  }
  return lw(msg);
}

int interact_filt(object obj) {
  return interactive(obj);
}

int read(string arg) {
  if((arg != "sign") && (arg != "worn sign")) return 0;
  write("You read the sign on the wall. On it is scrawled:\n\n" +
	"This is the Arena of Dyolf City, where some vent their\n" +
	"frustrations and prove their might, and others find shame\n" +
	"and disgrace. Only two people at a time in the arena, but\n" +
	"others can watch; to see who's watching, you just have to\n" +
	"'look at spectators'. The commands are:\n" +
	"  - rules:     gives you the rules of the battle\n" +
	"  - challenge: challenges the other player to a battle\n" +
	"  - accept:    accepts the challenge\n" +
	"  - leave:     leaves the Arena\n" +
	"Remember, NO REFUNDS!\n");
  return 1;
}

int rules(string arg) {
  if(arg) return 0;
  write("The battles cost " + COST + " coins per player. The most\n" + 
	"important thing to note is that NEITHER PLAYER CAN ACTUALLY\n" +
	"DIE IN BATTLE, UNLESS POISON IS USED. Once a battle is\n" +
	"initiated by a player issuing the 'accept' command, the\n" +
	"battle must continue until one player has been defeated.\n" +
	"Leaving the Arena during a battle is a forfeit.\n");
  return 1;
}

int challenge(string arg) {
  object temp;

  if(arg) return 0;
  if(fighting) write("You are already engaged in battle!\n");
  else if(chal)
    write("There is already a challenge awaiting acceptance.\n");
  else if(!(glad1 && glad2))
    write("There is no one to challenge!\n");
  else if(TP->query_money() < COST)
    write("You don't have enough money! (The cost is " + COST + " coins.\n");
  else {
    if(TP == glad2) {
      temp = glad1;
      glad1 = TP;
      glad2 = temp;
    }
    TP->add_money(-COST);
    write("You challenge " + glad2->NAME + " to a battle.\n");
    TELL(glad2, lw(glad1->NAME + " challenges you to a battle. You have " +
	 RESP + " seconds to respond.\n"));
    TELLR(STANDS, lw(glad1->NAME + " challenges " + glad2->NAME + " to " +
	  "a battle!\n"));
    call_out("end_chal", RESP);
    chal = 1;
  }
  return 1;
}

void end_chal() {
  TELL(glad1, glad2->NAME + " has decided not to accept.\n");
  TELL(glad2, "Your time to accept the challenge is up.\n");
  TELLR(STANDS, "The time to accept the challenge expires.\n");
  TELLR(TO, "Booing erupts from the spectators!\n");
  chal = 0;
}

void start_battle() {
  property -= ({ "no_fight" });
  shad1 = clone_object(NWCITY + "objects/arena_shad");
  shad1->start_shadow(glad1);
  shad2 = clone_object(NWCITY + "objects/arena_shad");
  shad2->start_shadow(glad2);
}

int accept(string arg) {
  if(arg) return 0;
  if(!chal) write("No challenge has been given.\n");
  else if(TP == glad1)
    write("You cannot accept your own challenge!\n");
  else if(TP->query_money() < COST)
    write("You don't have enough money! (The cost is " + COST + " coins.\n");
  else if(TP == glad2) {
    chal = 0;
    fighting = 1;
    TP->add_money(-COST);
    write("You accept " + glad1->NAME + "'s challenge.\n" +
	  "LET THE BATTLE BEGIN!!\n");
    TELL(glad1, TP->NAME + " accepts your challenge!\n" +
	 "LET THE BATTLE BEGIN!!\n");
    TELLR(STANDS, glad2->SNAME + " accepts " + glad1->SNAME + "'s " +
	  "challenge!\n");
    TELLR(TO, "Cheers erupt from the spectators all around you!\n");
    remove_call_out("end_chal");
    start_battle();
  }
  else return 0;
  return 1;
}

int leave(string arg) {
  if(arg) return 0;
  TP->MOVEP("from the Arena#" +
	    NWCITY + "rooms/mainst04");
  return 1;
}

void end_battle(object winner) {
  int i;
  object loser;
  object *inv;

  if(glad1 == winner) loser = glad2;
  else loser = glad1;
  inv = filter_array(all_inventory(TO), "living_filt", TO);
  for(i = 0; i < sizeof(inv); i++) {
    inv[i]->stop_fight();
    inv[i]->stop_fight();
    inv[i]->stop_hunter(1);
  }
  TELL(winner, "You deal the killing blow to " + loser->NAME + ".\n" +
       CAP(loser->PRO) + " falls to the dusty ground, defeated.\n");
  TELL(loser, "You gasp as you fall to the dusty ground, defeated.\n");
  TELLR(STANDS, lw(winner->NAME + " deals a fatal blow, and " + 
	loser->NAME + " falls to the dusty ground in defeat.\n"));
  TELL(winner, "The arena's owner, a short, hairy man, walks up to you.\n" +
       "Owner says: Congratulations, kid.\n" +
       "Owner gives you " + (COST * 2) + " gold coins, then walks away.\n");
  say(lw("The arena's owner, a short, hairy man, walks up to " +
	 winner->SNAME + " and gives " + winner->OBJ + " something, " +
	 "then leaves.\n"), winner);
  winner->add_money(COST * 2);
  do_shout(winner, loser);
  end_fight();
}
       
void do_shout(object winner, object loser) {
  int i;
  object *players;

  players = filter_array(users(), "player_filt", TO);
  for(i = 0; i < sizeof(players); i++)
    tell_object(players[i], lw(winner->NAME + "'s triumphant battle-cry " +
		"echoes across the lands!\n"));
  write_file(LOGS + "arena.log", CAP(winner->RNAME) + " (level " +
	     winner->LEVEL + ") defeated " + CAP(loser->RNAME) +
	     " (level " + loser->LEVEL + ") on " + ctime(time()) + ".\n");
}

void end_fight() {
  if(shad1) destruct(shad1);
  if(shad2) destruct(shad2);
  fighting = 0;
  if(!query_property("no_fight")) property += ({ "no_fight" });
}

int living_filt(object obj) {
  return living(obj);
}

int player_filt(object obj) {
  return (ENV(obj) != TO);
}
  

void catch_tell(string str) {
  TELLR(STANDS, lw("Arena-> " + str));
}

void exit(object obj) {
  if(fighting && interactive(obj)) {
    if(((obj == glad1) && glad2) || ((obj == glad2) && glad1)) {
      TELL(obj, "You automatically forfeit the battle by leaving " +
	   "the Arena.\n");
      if(obj == glad1) end_battle(glad2);
      else if(obj == glad2) end_battle(glad1);
    }
    else end_fight();
  }
  else if(chal && interactive(obj)) {
    if((obj == glad1) || (obj == glad2)) {
      TELLR(TO, "The challenge is aborted. The crowd jeers!\n");
      chal = 0;
      remove_call_out("end_chal");
    }
  }
  if(obj == glad1) {
//    glad1->add_experience(exp1 - glad1->query_exp());
    glad1 = 0;
  }
  else if(obj == glad2) {
//    glad2->add_experience(exp2 - glad2->query_exp());
    glad2 = 0;
  }
  return;
}

string query_glads() {
  if(glad1 && glad2) {
    if(fighting)
      return glad1->NAME + " and " + glad2->NAME + " are fighting in " +
	"the arena below";
    return glad1->NAME + " and " + glad2->NAME + " are in the arena " +
      "below";
  }
  if(glad1)
    return glad1->NAME + " is in the arena below.\n";
  if(glad2)
    return glad2->NAME + " is in the arena below.\n";
  return "The arena below is empty";
}

object query_other_glad(object obj) {
  if(obj == glad1) return glad2;
  else return glad1;
}

int dump(string arg) {
  if(arg) return 0;
  write("glad1: ");
  if(glad1) write(glad1->NAME + "\n");
  else write("None.\n");
  write("glad2: ");
  if(glad2) write(glad2->NAME + "\n");
  else write("None.\n");
  if(chal) write("There is a challenge pending.\n");
  if(fighting) write("Fight in progress.\n");
  return 1;
}
    
