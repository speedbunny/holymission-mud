inherit "/room/room";

#include "/room/room_defs.h"
#define RELIGION "Illuvatar"

private string kneeler;

int move(string str) {
  if(!str)
    str=query_verb();
  if(str=="north" && kneeler==TP->RNAME) {
    writelw("You do not want to walk out on your knees. You must "+
            "rise first.\n");
    return 1;
  }
  return ::move(str);
}  

nomask int try_attack(object ob) {
  tell_object(ob, "You feel the eye of the gods burning angrily inside you.\n");
  say("A flash strikes " + ob->RNAME + ".\n", ob);
  ob->reduce_hit_point(random(100)+1);
  return 1;
}

void reset(int arg) {
  if(arg) return;
    
  set_light(1);
  short_desc="At the altar of the village church";
  long_desc=
    "You stand before the altar of "+ RELIGION +". You feel strongly "+
    "that this is a holy place, guarded by mighty gods. A small "+
    "kneeling-chair stands in a circle before the altar. Four big "+
    "candles are placed around it. To the north you can walk through "+
    "the aisle to the open portal of the church. Dead people have come "+
    "to the right place if they are in search of their former strength.\n";

  dest_dir=({
    HM_VILLAGE + "church1", "north",
  });

  items=({
    "altar","A high altar full of symbols rises before you. "+
      "It's surrounded by a holy aura",
    "symbols","Holy symbols used at mass. Only a priest here would "+
      "know what they mean",
    "candles","They are secured by your conscience",
    "gods","You can't see them but you know they're there nevertheless",
    "chair","A simple chair you can kneel on to pray to the gods",
    "kneeling-chair","A simple chair you can kneel on to pray to the gods",
    "circle","A circle is engraved in the ground. It must be a "+
      "symbol of some kind",
    "aisle","The aisle goes along the entire length of the church",
    "portal","It's always open to welcome visitors who search peace "+
      "and strength",
  });

  property=({ "no_fight", "no_steal", "has_fire" });
  smell="The smell of burning incense and candles hangs here.\n";
  ::reset(arg);
}

void init() {
  object hat;
  ::init();
  
  if(TP->query_religion()==RELIGION) {
    if(hat=present("helmet",TP)) {
      if(hat->query_worn())
        call_out("remove_hat",1);
    }
  }
  add_action("pray_it","pray");
  add_action("pray_it","regenerate");
  add_action("_kneel","kneel");
  add_action("_rise","rise");
  add_action("_rise","stand");
}

void remove_hat() {
  write("You take off your hat, respecting " + RELIGION + ".\n");
  say(lw(TP->NAME+" takes off "+
         TP->query_possessive() + " hat in the church.\n"));
  command("remove helmet", TP);
}

nomask status pray_it(string str) {
  string belief;

  belief = TP->query_religion();
  if(!belief) {
    if(kneeler != TP->RNAME) {
      writelw("If you want to become a follower of " + RELIGION+
              " then kneel first, before you begin your prayers.\n");
      return 1;
    }
    write("You are now a devout follower of " + RELIGION + ".\n");
    TP->set_religion(RELIGION);
    return 1;
  }

  if(belief != RELIGION) {
    notify_fail("You are not a follower of " + RELIGION + "!\n");
    return 0;
  }
  if(!TP->remove_ghost()) {
    if(kneeler != TP->RNAME) {
      writelw("If you want to be a devout follower of " + RELIGION+
              " then kneel first, before you begin your prayers.\n");
      return 1;
    }
    write("You send your prayers to heaven and feel relieved of "+
          "your burdens.\n");
    say(TP->NAME + " is lost in prayers.\n");
    return 1;
  }
  TP->remove_ghost();
  TP->set_smell("Smells as if just reborn.");
  return 1;
}

status _kneel(string str) {
  if(!str || str=="down") {
    if(TP->query_ghost()) {
      write("You are a ghost. You don't have knees.\n");
      return 1;
    }
    if(kneeler && kneeler!=TP->RNAME) {
      write("The kneeling-chair is occupied by "+ CAP(kneeler) +".\n");
      return 1;
    }
    write("You kneel down on the kneeling-chair.\n");
    say(TP->NAME + " kneels down.\n");
    kneeler = TP->RNAME;
    return 1;
  }
  return 0;
}

status _rise(string str) {
  if(!str || str=="up") {
    if(TP->RNAME != kneeler) {
      write("You're not kneeling.\n");
      return 1;
    }
    write("You rise up from the kneeling-chair.\n");
    kneeler = 0;
    return 1;
  }
  return 0;
}

void light_text(string str) {
  writelw("You hold the " + str + " into the holy candles of the "+
          "altar to light it.\n");
  say(lw(TP->NAME + " lights a " + str + ", using the holy candles "+
      "of the altar.\n"));
  if(TP->query_religion() == RELIGION) {
    writelw("You feel very bad about doing this at the altar of "+
            "your own god! His revenge might take you one day!\n");
  }
}
