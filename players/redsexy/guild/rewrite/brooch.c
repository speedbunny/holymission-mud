inherit "obj/armour";

#include "/include/defs.h"
#include "/players/redsexy/guild/formulae.h"

int    broochpower;
object att;

void reset(int arg) {
  ::reset(arg);
  if(arg)
    return;
  set_name("brooch");
  set_short("Brooch");
  set_long("    An intricately crafted Brooch of Summoners. Within the\n" +
	         "large blue jewel set in its center you can see the four\n" +
	         "Elements swirl in a complicated dance.\n");
  set_type("guildbrooch");
  set_weight(0);
}

init() {
  ::init();
  if(TP->query_real_guild() != GM->query_number("summoner")
         && !TP->IMM)
    destroy_me();
  if(!TO->query_worn() && !TP->IMM) {
    worn = 1;
    worn_by = TP;
  }
  if(broochpower > MAXBP)
    broochpower = MAXBP;

  add_action("my_drop",   "drop");
  add_action("my_remove", "remove");
  add_action("my_sell",   "sell");
}

int my_drop(string arg) {
  if(arg && id(arg)) {
    write("You cannot drop your Brooch.\n");
    return 1;
  }
  return 0;
}

int my_remove(string arg) {
  if(arg && id(arg)) {
    write("You cannot remove your Brooch.\n");
    return 1;
  }
  return 0;
} 

int my_sell(string arg) {
  if(arg && id(arg)) {
    write("You cannot sell your Brooch.\n");
    return 1;
  }
  return 0;
}

int add_bp(int arg) {
  broochpower += arg;
  return broochpower;
}

int set_bp(int arg) {
  if(arg > 0) {
    broochpower = arg;
  }
  else {
    broochpower = 0;
  }
  return broochpower;
}

int query_bp()     { return broochpower; }
int query_max_bp() { return MAXBP;      }

int destroy_me(int silent) {
  if(!silent) {
    write("Your Brooch dissolves, setting free the Elements within.\n");
    say("The Elements escape from " + TP->SNAME + "'s Brooch!\n");
  }
  destruct(TO);
  return 1;
}

int drop(string arg)      { return 1;          }
int remove(string arg)    { return 1;          }
int query_summoner_wear() { return 1;          }
