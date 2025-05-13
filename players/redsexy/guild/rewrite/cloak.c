inherit "obj/armour";

#include "/include/defs.h"
#include "/players/redsexy/guild/formulae.h"

#define BIN       "/" + GM->query_dir(9) + "/bin/"
#define SPELL     "/" + GM->query_dir(9) + "/spells/"

status has_called;
status silent_move;
status did_quit;
int hoodlevel;
object att;
object brooch;
object raven;
object wisp;
object *creatures;

int _actions_(string strSpell, string strArgs, int intTestDir) {

  switch(intTestDir) {
  case 0:
    return (BIN + strSpell)->main(strArgs);
    break;
  case 1:
    return (BIN + strSpell)->main(strArgs);
    break;
  }
  return 0;
}

int _actions(string strArgs) {

  int     intDelay;
  string  theverb;

  intDelay = 0;
  theverb = (string)query_verb();

  if(theverb[0] == 39 || theverb[0] == 46)
    return 0;

  if(theverb[strlen(theverb)-1] == '.')
    return 0;

  if(theverb == "quit" || theverb == "dest")
    return 0;


  if(file_size(BIN + theverb + ".c") > 0) {
    intDelay = (BIN + theverb)->query_delay();
    if(intDelay == 0) {
      return (BIN + theverb)->main(strArgs);
    }
    else {
      if(find_call_out("_actions_") != -1) {
        write("You are already casting.\n");
        return 1;
      }
      call_out("_actions_", 1, theverb, strArgs, 0);
      return 1;
    }
  }
  if(theverb == "brooch/" || theverb == "br/") {
    return (BIN + "bre")->main(strArgs);
  }
  return 0;
}

int id(string str) {
    return (str=="sumsoul" || str=="guildsoul");
}

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
   creatures = allocate(MAXCREATURES);
   set_short("Black Cloak");
   set_long("A black hooded Cloak marking its wearer as a Summoner.\n");
   set_alias("cloak");
   set_type("guildcloak");
   set_weight(0);
}



init() {
     add_action("_actions","",1);

  if(!TO->query_worn() && !TP->query_immortal()) {
    worn = 1;
    worn_by = TP;
  }
  brooch = present("guildbrooch", TP);
  if(brooch) MOVE(brooch, TP);
  else {
    brooch = clone_object("/players/redsexy/guild/rewrite/brooch");
    transfer(brooch, TP);
  }
  CD->do_chat(9,"[>>><<<] "+CAP(TP->RNAME)+"'s mind connects to yours.  Your brooch begins to vibrate.\n");
}

extra_look() {
  string text;
  text = TP->SNAME + " is a powerful Summoner.\n" +
    CAP(TP->PRO) + " stands before you, a mysterious black-clad figure\n" +
    "  whose eyes blaze with the secrets of the Planes.\n" +
    CAP(TP->PRO) + " is " + rank();
  return text;
}

string rank() {
  if(TP->LEVEL <= 6) return "a Guild Novice";
  if(TP->LEVEL <= 11) return "a Guild Apprentice";
  if(TP->LEVEL <= 16) return "a Guild Adept";
  if(TP->LEVEL <= 21) return "a Guild Summoner";
  if(TP->LEVEL <= 26) return "a High Guild Summoner";
  if(TP->RNAME == "matt") return "the Guild Creator";
  if(TP->RNAME == "redsexy") return "the Master-Summmoner";
  if(TP->IMM) return "visiting for a spell";
  return "a Guild Master";
}

my_drop(arg) {
  if(arg && id(arg)) {
    write("You cannot drop your Cloak.\n");
    return 1;
  }
  return 0;
}

my_remove(arg) {
  if(arg && id(arg)) {
    write("You cannot remove your Cloak.\n");
    return 1;
  }
  return 0;
}

my_sell(arg) {
  if(arg && id(arg)) {
    write("You cannot sell your Cloak.\n");
    return 1;
  }
  return 0;
}

int set_hoodlevel(int arg){
 if(arg > 0) {
    hoodlevel = arg;
  }
  else {
    hoodlevel = 0;
  }
  return hoodlevel;
}

int set_silent_move(int arg){
 if(arg > 0) {
    silent_move = 1;
  }
  else {
    silent_move = 0;
  }
  return silent_move;
}

int time_guild_soul() {

  status calmed;
  int    i;
  object att;

  has_called = 0;
  att        = TP->query_attack();
 
  for(i = 0; i < MAXCREATURES; i++) {
    if(creatures[i]) {
      if(TP->query_ghost()) {
        creatures[i]->destroy_me();
        return 1;
      }
      creatures[i]->move_me(silent_move);
      switch(creatures[i]->query_creature()) {
      case "golem":
        if((creatures[i]->query_exp() > 0)
             && (att != creatures[i])) {
          TP->add_exp(creatures[i]->query_exp());
          creatures[i]->set_ep(0);
        }
        break;
      case "attacker":
        calmed = creatures[i]->query_calmed();
        if(creatures[i]->query_attack()
          || (att && !calmed)) {
          creatures[i]->beat(1);
        }
        else {
          creatures[i]->beat(0);
        }
        if((creatures[i]->query_exp() > 0) && (att != creatures[i])) {
          TP->add_exp(creatures[i]->query_exp());
          creatures[i]->set_ep(0);
        }
        break;
      default:
        write("ERROR in time_guild_soul!\n");
        break;
      } // switch(creatures[i]->query_creature())
    } // if(creatures[i])
 write ("testing");
  } // for(i = 0; i < MAXCREATURES; i++)
  return 1;
}

void guild_changes() {

  int i;

  if(did_quit)
    return;
  if(wisp)
    wisp->destroy_me(silent_move);
  if(raven)
    raven->destroy_me(silent_move);
  for(i = 0; i < MAXCREATURES; i++) {
    if(creatures[i])
      creatures[i]->destroy_me(silent_move);
    if(brooch)
      CD->do_chat(9, "[>>><<<] You feel " + CAP(TP->RNAME) + "'s Presence drain " +
                     "from your Brooch as your minds disconnect.\n");
    if(query_verb() != "quit") {
      if(brooch)
        brooch->destroy_me(1);
      write_file("/players/redsexy/logfiles/guild_leave",
                 CAP(TP->RNAME) + " left on " + ctime(time()) + ".\n");
    }
    did_quit = 1;
  } // for(i = 0; i < MAXCREATURES; i++)
}

int drop(string arg)      { return 1;           }
int remove(string arg)    { return 1;           }
int query_hoodlevel()     { return hoodlevel;   }
int query_silent()        { return silent_move; }
int query_summoner_wear() { return 1;           }

