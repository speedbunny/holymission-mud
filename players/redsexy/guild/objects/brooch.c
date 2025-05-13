inherit "obj/armour";

#include "lw.h"
#include "/players/redsexy/guild/gmp.h"
#include "/players/redsexy/guild/obdefs.h"
#include "/players/redsexy/guild/formulae.h"
#include "/players/redsexy/guild/functions.h"
#include "/players/redsexy/guild/arrays.h"
int broochpower;

string linestatus;

object att;

#include "/players/redsexy/guild/spells/broochspells"

reset(arg) {
  ::reset(arg);
  if(arg) return;
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
  if(TP->query_guild() != GD) destroy_me();
  if(!TO->query_worn() && !TP->query_immortal()) {
    worn = 1;
    worn_by = TP;
  }
  if(!linestatus) linestatus = " ON";
  if(broochpower > MAXBP) broochpower = MAXBP;

  add_action("brooch",    "brooch");
  add_action("bremote",   "bremote");
  add_action("bron",      "bron");
  add_action("draw",     "draw");
  add_action("broff",     "broff");
  add_action("drawhp",    "drawhp");
  add_action("drawsp",    "drawsp");
  add_action("storehp",   "storehp");
  add_action("storesp",   "storesp");
  add_action("my_drop",   "drop");
  add_action("my_remove", "remove");
  add_action("my_sell",   "sell");
}

init_arg(arg) {
  status line_off;
  sscanf(arg, "%d*%d", broochpower, line_off);
  if(line_off) linestatus = "OFF";
  else linestatus = " ON";
}

my_drop(arg) {
  if(arg && id(arg)) {
    write("You cannot drop your Brooch.\n");
    return 1;
  }
}

my_remove(arg) {
  if(arg && id(arg)) {
    write("You cannot remove your Brooch.\n");
    return 1;
  }
} 

my_sell(arg) {
  if(arg && id(arg)) {
    write("You cannot sell your Brooch.\n");
    return 1;
  }
}

add_bp(arg) {
  broochpower += arg;
  return 1;
}

set_line(arg) {
  linestatus = arg;
  return 1;
}

destroy_me(silent) {
  if(!silent) {
    write("Your Brooch dissolves, setting free the Elements within.\n");
    say("The Elements escape from " + TP->SNAME + "'s Brooch!\n");
  }
  destruct(TO);
  return 1;
}

tell_others(filt, msg) {
  int i;
  object *valid;
  valid = filter_array(users(), filt, TO, TP);
  for(i = 0; i < sizeof(valid); i++)
    TELL(valid[i], msg);
  return 1;
}

guild_list(obj1, obj2) {
  return (obj1->query_guild() == GD) &&
    (obj1->query_invis() <= obj2->LEVEL);
}
guild_comm(obj1, obj2) {
  object otherbrooch;
  otherbrooch = present("guildbrooch", obj1);
  return (obj1->query_guild() == GD) &&
    otherbrooch && (otherbrooch->query_line() == " ON");
}
guild_notify(obj1, obj2) {
  object otherbrooch;
  otherbrooch = present("guildbrooch", obj1);
  return (obj1->query_guild() == GD) &&
    (obj2->query_invis() <= obj1->LEVEL) && otherbrooch &&
    (otherbrooch->query_line() == " ON") && (obj1 != obj2);
}

query_auto_load() {
  status line_off;
  if(linestatus == "OFF") line_off = 1;
  return "players/redsexy/guild/objects/brooch:" +
    broochpower + "*" + line_off;
}
drop() { return 1; }
remove() { return 1; }
query_bp() { return broochpower; }
query_max_bp() { return MAXBP; }
query_line() { return linestatus; }
query_summoner_wear() { return 1; }
