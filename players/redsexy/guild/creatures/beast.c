inherit "obj/monster";

#include "/players/redsexy/guild/crdefs.h"
#include "/players/redsexy/guild/formulae.h"
#include "/players/redsexy/guild/functions.h"

int capacity;
object att, master;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Beast");
  set_alt_name("beast");
  set_alias("beast of burden");
  set_level(1);
  set_ep(0);
  set_no_fight(1);
}

init() {
  ::init();
  if(!master) destroy_me(1);
  add_action("btake", "btake");
  add_action("bgive", "bgive");
  add_action("bdrop", "bdrop");
  add_action("binv",  "binv");
  add_action("ban",   "ban");
  add_action("my_give", "give");
}  

hit_player() {
  if(TP && living(TP) && (TP != TO) && (ENV(TP) == ENV(TO))) {
    write("The Beast explodes in a bright flash of light!\n" +
	  "You feel biting pain as shards embed themselves " +
	  "in your flesh.\n");
    if(TP != master)
      TELL(master, TP->NAME + " has destroyed your Beast!\n");
    TELLRS(ENV(TO), SHORT + " explodes, impaling " + TP->SNAME +
	   " with jagged shards!\n", TP, master, TO);
    TP->HIT(BEAST_DAM);
    destroy_me(1);
    return 1;
  }
}

heart_beat() { set_heart_beat(0); }

btake(arg) {
  int i, numcoins;
  string dummy, proper, ishort;
  object inv, item;
  if(TP != master) return;
  if(arg) {
    if((sscanf(arg, "%d %s", numcoins, dummy) == 2) &&
       (dummy == "coins")) {
      if(numcoins <= TP->query_money()) {
	if(numcoins > 0) {
	  CHECK_ATTACK();
	  CHECK_GHOST();
	  CHECK_ARM();
	  CHECK_SP(BEAST_TAK_SP);
	  TP->add_money(- numcoins);
	  if(numcoins == 1) proper = " coin";
	  else proper = " coins";
	  write("Your Beast takes " + numcoins + proper + ".\n");
	  say(TP->NAME + " gives " + numcoins + proper + " to " +
	      TP->POS + " Beast.\n");
	  TO->add_money(numcoins);
	  return 1;
	}
	write("You must specify a positive amount.\n");
	return 1;
      }
      write("You do not have that much money.\n");
      return 1;
    }
    item = present(arg, TP);
    if(item) {
      CHECK_ATTACK();
      CHECK_GHOST();
      CHECK_ARM();
      CHECK_SP(BEAST_TAK_SP);
      ishort = item->SHORT;
      switch(TRANS(item, TO)) {
        case 0:
	  write("Your Beast takes " + ishort + ".\n");
	  say(TP->SNAME + " gives " + ishort + " to " +
	      TP->POS + " Beast.\n");
	  return 1;
	  break;
	case 1:
	  write(ishort + " is too heavy for your Beast.\n");
	  return 1;
	  break;
	default:
	  write("You cannot seem to give " +
		ishort + " to your Beast.\n");
	  return 1;
	  break;
      }
    }
    write("You are not carrying that.\n");
    return 1;
  }
  write("Syntax: btake <item>\n");
  return 1;
}

bgive(arg) {
  int i, numcoins;
  string dummy, proper;
  object inv, item;
  if(TP != master) return;
  if(arg) {
    if(arg == "all") {
      inv = all_inventory(TO);
      if(!sizeof(inv)) {
	write("You are not carrying anything.\n");
	return 1;
      }
      for(i = 0; i < sizeof(inv); i++)
	if(inv[i]->NAME) bgive(inv[i]->NAME);
      if(TO->query_money() > 0) bgive(TO->query_money() + " coins");
      return 1;
    }
    if((sscanf(arg, "%d %s", numcoins, dummy) == 2) &&
       (dummy == "coins")) {
      if(numcoins <= TO->query_money()) {
	if(numcoins > 0) {
	  CHECK_ATTACK();
	  CHECK_GHOST();
	  CHECK_ARM();
	  CHECK_SP(BEAST_GIV_SP);
	  if(numcoins == 1) proper = " coin";
	  else proper = " coins";
	  TO->add_money(- numcoins);
	  write("Your Beast gives " + numcoins + proper + " to you.\n");
	  say(SHORT + " gives " + numcoins + proper + " to " +
	      TP->OBJ + ".\n");
	  TP->add_money(numcoins);
	  return 1;
	}
	write("You must specify a positive amount.\n");
	return 1;
      }
      write("Your Beast is not carrying that much money.\n");
      return 1;
    }
    item = present(arg, TO);
    if(item) {
      CHECK_ATTACK();
      CHECK_GHOST();
      CHECK_ARM();
      CHECK_SP(BEAST_GIV_SP);
      switch(TRANS(item, TP)) {
        case 0:
	  write("Your beast gives " + item->SHORT + " to you.\n");
	  say(SHORT + " gives " + item->SHORT + " to " +
	      TP->OBJ + ".\n");
	  return 1;
	  break;
	case 1:
	  write("You are carrying too much.\n");
	  return 1;
	  break;
	default:
	  write("Your Beast cannot seem to give you " +
		item->SHORT + ".\n");
	  return 1;
	  break;
      }
    }
    write("Your Beast is not carrying that.\n");
    return 1;
  }
  write("Syntax: bgive <item>\n");
  return 1;
}

bdrop(arg) {
  int i, numcoins;
  string dummy, proper;
  object inv, item, money;
  if(TP != master) return;
  if(arg) {
    if(arg == "all") {
      inv = all_inventory(TO);
      if(!sizeof(inv)) {
	write("You are not carrying anything.\n");
	return 1;
      }
      for(i = 0; i < sizeof(inv); i++)
	if(inv[i]->NAME) bdrop(inv[i]->NAME);
      if(TO->query_money() > 0) bdrop(TO->query_money() + " coins");
      return 1;
    }
    if((sscanf(arg, "%d coins", numcoins) == 2) &&
       (dummy == "coins")) {
      if(numcoins <= TO->query_money()) {
	if(numcoins > 0) {
	  CHECK_ATTACK();
	  CHECK_GHOST();
	  CHECK_ARM();
	  CHECK_SP(BEAST_DRP_SP);
	  money = clone_object("obj/money");
	  money->set_money(numcoins);
	  MOVE(money, ENV(TO));
	  TO->add_money( - numcoins);
	  if(numcoins == 1) proper = " coin";
	  else proper = " coins";
	  write("Your Beast drops " + numcoins + proper + ".\n");
	  say(SHORT + " drops " + numcoins + proper + ".\n");
	  return 1;
	}
	write("You must specify a positive amount.\n");
	return 1;
      }
      write("Your Beast is not carrying that much money.\n");
      return 1;
    }
    item = present(arg, TO);
    if(item) {
      CHECK_ATTACK();
      CHECK_GHOST();
      CHECK_ARM();
      CHECK_SP(BEAST_DRP_SP);
      if(TRANS(item, ENV(TO))) {
	write("Your Beast cannot seem to drop " +
	      item->SHORT + ".\n");
	return 1;
      }
      write("Your Beast drops " + item->SHORT + ".\n");
      say(SHORT + " drops " + item->SHORT + ".\n");
      return 1;
    }
    write("Your Beast is not carrying that.\n");
    return 1;
  }
  write("Syntax: bdrop <item>\n");
  return 1;
}

ban(arg) {
  if(TP != master) return;
  if(id(arg)) {
    CHECK_ATTACK();
    CHECK_GHOST();
    CHECK_INTOX();
    CHECK_ARM();
    CHECK_SP(BEAST_BAN_SP);
    write("You banish your Beast of Burden.\n");
    say(TP->SNAME + " gestures towards " + TP->POS +
	" Beast, banishing it to its own Plane.\n");
    destroy_me(1);
    return 1;
  }
}

my_give(arg) {
  string dummy;
  if(TP != master) return;
  if(sscanf(arg, "%s to beast", dummy) ||
     sscanf(arg, "%s to beast of burden", dummy)) {
    write("That is not the way to give things to your Beast.\n");
    return 1;
  }
}

make_me(obj) {
  master = obj;
  capacity = BEAST_CAP;
  set_short(master->SNAME + "'s Beast of Burden");
  set_long("A huge lumbering Beast that paws the ground impatiently.\n" +
	   "It belongs to " + master->SNAME + ".\n");
  set_level(master->LEVEL);
  set_str(master->STR);
  write("You chant the words of Summoning.\n");
  write("A Beast of Burden materializes before you.\n");
  say(master->NAME + " traces burning symbols in the air and " +
      "calls out:\n");
  say("'Te arcesso ut feras meum onerum!'\n" +
      "A Beast of Burden materializes, making the ground " +
      "shift under its weight.\n");
  return 1;
}

move_me(silent) {
  int i;
  object inv;
  if(ENV(TO) != ENV(master)) {
    if(ENV(TO)->has_drink(TO)) {
      TELL(master, "Your Beast drops the drinks to follow you.\n");
      inv = all_inventory(TO);
      for(i = 0; i < sizeof(inv); i++)
	if(inv[i]->query_drink()) destruct(inv[i]);
    }
    if(!silent)
      TELLRS(ENV(TO), SHORT + " follows " + master->OBJ + ".\n", TO);
    MOVE(TO, ENV(master));
    if(!silent) {
      TELL(master, "Your Beast lumbers in.\n");
      TELLRS(ENV(TO), SHORT + " lumbers in.\n", master, TO);
    }
  }
  return 1;
}

destroy_me(silent) {
  int i;
  object inv;
  if(!silent) {
    if(master) TELL(master, "Your Beast vanishes.\n");
    TELLRS(ENV(TO), SHORT + " vanishes.\n", master, TO);
  }
  inv = all_inventory(TO);
  for(i = 0; i < sizeof(inv); i++)
    destruct(inv[i]);
  destruct(TO);
  return 1;
}

query_carried() {
  int i, weight;
  object inv;
  inv = all_inventory(TO);
  for(i = 0; i < sizeof(inv); i++)
    weight += inv[i]->query_weight();
  return weight;
}
query_cap() { return capacity; }
query_show_short() { return 1; }
query_creature() { return "beast"; }
 
