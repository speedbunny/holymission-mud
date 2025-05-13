inherit "obj/armour";

#include "/include/defs.h"
#include "/players/redsexy/guild/formulae.h"

#define TEST      "/" + GM->query_dir(9) + "/test/"
#define BIN       "/" + GM->query_dir(9) + "/bin/"
#define TESTING   "/" + GM->query_dir(9) + "/testing/"
#define SPELL     "/" + GM->query_dir(9) + "/spells/"

int    hoodlevel;
object att;
object brooch;
object wisp;
object raven;
object *creatures;
status has_called;
status silent_move;
status did_quit;

int _cast_(string str) {

  int    i, j;
  string *spellname;
  string newstr;

  if(!str || str == "") {
    write("You must supply an arguement to cast.\n");
    return 1;
  }
  spellname = explode(str," ");
  i         = sizeof(spellname);
  if(i > 1) {
    for(j = 1; j < i; j++) {
      if(j == 1) {
        newstr = spellname[j];
      }
      else {
        newstr = newstr + " " + spellname[j];
      }
    }
  }

  if(file_size(SPELL + spellname[0] + ".c") > 0) {
    if((SPELL + spellname[0])->main(newstr)) {
      return 1;
    }
  }
  if(TP->IMM) {
    if(file_size(TESTING + spellname[0] + ".c") > 0) {
      if ((TESTING + spellname[0])->main(newstr)) {
        return 1;
      }
    }
  }
  write("You do not seem to know that spell!\n");
  return 1;
}

int _cast(string str) {
  if(find_call_out("_cast_") != -1) {
    write("You are already casting.\n");
    return 1;
  }
  call_out("_cast_",1,str);
  return 1;
}

int _filter(string str) {

  string theverb;

  theverb = (string)query_verb();

  if(theverb[0] == 39 || theverb[0] == 46)
    return 0;
  if(theverb[strlen(theverb)-1] == '.')
    return 0;

  if(theverb == "quit" || theverb == "dest")
    return 0;
  if(TP->IMM || TP->TESTP) {
    if(file_size(TEST + theverb + ".c") > 0) {
      if ((TEST + theverb)->main(str)) {
        return 1;
      }
    }
  }
  if(file_size(BIN + theverb + ".c") > 0) {
    if((BIN + theverb)->main(str)) {
      return 1;
    }
    else {
      return 0;
    }
  }
  if(theverb == "brooch/" || theverb == "brooch/") {
    (BIN+"bremote")->main(str);
    return 1;
  }
  return 0;
}

void reset(int arg) {
  ::reset(arg);
  if(arg)
    return;
  creatures = allocate(MAXCREATURES);
  set_id(GM->query_id(9));
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
  if(brooch)
    transfer(brooch, TP);
  else {
//    brooch = clone_object(OBJS + "brooch");
    brooch = clone_object("/" + GM->query_dir(9) + "/objects/brooch2");
    transfer(brooch, TP);
  }
  CD->do_chat(9, "You feel " + CAP(TP->RNAME) +
				 "'s mind connect to your Brooch causing it to vibrate.\n");

#if 0
  add_action("summon",        "summon");
  add_action("create",        "create");
  add_action("call",          "call");
  add_action("hood",          "hood");
  add_action("state",         "state");
  add_action("help",          "help");
  add_action("inspect",       "inspect");
  add_action("silence",       "silence");
  add_action("nospell",       "missile");
  add_action("nospell",       "shock");
  add_action("nospell",       "fireball");
  add_action("guild_changes", "quit");
  add_action("my_drop",       "drop");
  add_action("my_remove",     "remove");
  add_action("my_sell",       "sell");
#else
  add_action("_cast","cast");
  add_action("_filter","",1);
#endif
}

string rank() {
  if(TP->LEVEL <= 6)         return "a Guild Novice";
  if(TP->LEVEL <= 11)        return "a Guild Apprentice";
  if(TP->LEVEL <= 16)        return "a Guild Adept";
  if(TP->LEVEL <= 21)        return "a Guild Summoner";
  if(TP->LEVEL <= 26)        return "a High Guild Summoner";
  if(TP->RNAME == "matt")    return "the Guild Creator";
  if(TP->RNAME == "redsexy") return "the Guild Master";
  if(TP->IMM)                return "visiting for a spell";
  return "a Guild Master";
}

string extra_look() {
  string text;

  text = TP->NAME + " is a powerful Summoner.\n" +
         CAP(TP->PRO) + " stands before you, a mysterious black-clad figure\n" +
         "  whose eyes blaze with the secrets of the Planes.\n" +
         CAP(TP->PRO) + " is " + rank();
  return text;
}

int my_drop(string arg) {
  if(arg && id(arg)) {
    write("You cannot drop your Cloak.\n");
    return 1;
  }
  return 0;
}

int my_remove(string arg) {
  if(arg && id(arg)) {
    write("You cannot remove your Cloak.\n");
    return 1;
  }
  return 0;
}

int my_sell(string arg) {
  if(arg && id(arg)) {
    write("You cannot sell your Cloak.\n");
    return 1;
  }
  return 0;
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
      CD->do_chat(9, "You feel " + CAP(TP->RNAME) + "'s Presence drain " +
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
int query_silent()        { return silent_move; }
int query_summoner_wear() { return 1;           }

