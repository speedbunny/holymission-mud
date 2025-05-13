inherit "obj/armour";

#include "/players/redsexy/guild/obdefs.h"
#include "/players/redsexy/guild/formulae.h"
#include "/players/redsexy/guild/functions.h"
#include "/players/redsexy/guild/arrays.h"

status has_called;
status silent_move;
status did_quit;

int gnum;
int max_stats;
int hoodlevel;

string groom;
string dir;
string helpdir;
string roomdir;
string obdir;
string crdir;
string sanctuary;

object att;
object brooch;
object raven;
object *creatures;

#include "/players/redsexy/guild/spells/cloakspells"

reset(arg) {
  ::reset(arg);
  if(arg) return;
   gnum = 9;
   groom = "/players/redsexy/guild/room";
   max_stats = GM->query_levels(gnum);
   dir = "/players/matt/guild" + "/";
   helpdir = dir + "help/";
   roomdir = dir + "rooms/";
   obdir = dir + "objects/";
   crdir = dir + "creatures/";
   sanctuary = roomdir + "roof";
   creatures = allocate(MAXCREATURES);
   set_id(GM->query_id(gnum));
   set_short("Black Cloak");
   set_long("A black hooded Cloak marking its wearer as a Summoner.\n");
   set_alias("cloak");
   set_type("guildcloak");
   set_weight(0);
}

init() {
  ::init();
  if(!TO->query_worn() && !TP->query_immortal()) {
    worn = 1;
    worn_by = TP;
  }
  brooch = present("guildbrooch", TP);
  if(brooch) MOVE(brooch, TP);
  else {
    brooch = clone_object(obdir + "brooch");
    transfer(brooch, TP);
  }
  brooch->tell_others("guild_notify", "You make a connection with" + TP->NAME +
		      "'s Mind and your brooch vibrates .\n");
int _filter(string str) {

    string theverb;

    theverb = (string)query_verb();

    if(theverb[0] == 39) return 0;
    if(theverb == "quit" || theverb == "dest") return 0;
    if(file_size(BINDIR + theverb + ".c") > 0)
        if ((BINDIR + theverb)->main(str))
            return 1;
        else return 0;
        }
    return 0;
}

extra_look() {
  string text;
  text = TP->SNAME + " is a powerful Summoner.\n" +
    CAP(TP->PRO) + " stands before you, a mysterious black-clad figure\n" +
    "  whose eyes blaze with the secrets of the Planes.\n" +
    CAP(TP->PRO) + " is " + rank();
  return text;
}

rank() {
  if(TP->LEVEL <= 6) return "a Guild Novice";
  if(TP->LEVEL <= 11) return "a Guild Apprentice";
  if(TP->LEVEL <= 16) return "a Guild Adept";
  if(TP->LEVEL <= 21) return "a Guild Summoner";
  if(TP->LEVEL <= 26) return "a High Guild Summoner";
  if(TP->RNAME == "matt") return "the Guild Creator";
  if(TP->RNAME == "redsexy") return "the Arch-Summmoner";
  return "a Guild Master";
}

my_drop(arg) {
  if(arg && id(arg)) {
    write("You cannot drop your Cloak.\n");
    return 1;
  }
}

my_remove(arg) {
  if(arg && id(arg)) {
    write("You cannot remove your Cloak.\n");
    return 1;
  }
}

my_sell(arg) {
  if(arg && id(arg)) {
    write("You cannot sell your Cloak.\n");
    return 1;
  }
}

time_guild_soul() {
  status calmed;
  int i;
  object att;
  has_called = 0;
  att = TP->query_attack();
  for(i = 0; i < MAXCREATURES; i++)
    if(creatures[i]) {
      if(TP->query_ghost()) {
	creatures[i]->destroy_me();
	return;
      }
      creatures[i]->move_me(silent_move);
      switch(creatures[i]->query_creature()) {
        case "golem":
	  if((creatures[i]->query_exp() > 0) &&
	     (att != creatures[i])) {
	    TP->add_exp(creatures[i]->query_exp());
	    creatures[i]->set_ep(0);
	  }
	  break;
	case "attacker":
	  calmed = creatures[i]->query_calmed();
	  if(creatures[i]->query_attack() ||
	     (att && !calmed))
	    creatures[i]->beat(1);
	  else creatures[i]->beat(0);
	  if((creatures[i]->query_exp() > 0) && (att != creatures[i])) {
	    TP->add_exp(creatures[i]->query_exp());
	    creatures[i]->set_ep(0);
	  }
	  break;
      }
    }
  return 1;
}

guild_changes() {
  int i;
  if(did_quit) return;
  if(raven) raven->destroy_me(silent_move);
  for(i = 0; i < MAXCREATURES; i++)
    if(creatures[i]) creatures[i]->destroy_me(silent_move);
  if(brooch) brooch->tell_others("guild_notify", "You feel " + TP->NAME +
				 "'s Presence drain from your Brooch as your minds disconnect.\n");
  if(query_verb() != "quit") {
    if(brooch) brooch->destroy_me(1);
    write_file("/players/matt/logfiles/guild_leave",
	       CAP(TP->RNAME) + " left on " + ctime(time()) + ".\n");
  }
  did_quit = 1;
}

drop() { return 1; }
remove() { return 1; }
query_silent() { return silent_move; }
query_summoner_wear() { return 1; }

