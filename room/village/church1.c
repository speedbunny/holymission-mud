inherit "/room/room";

#include "/room/room_defs.h"
#define RELIGION "Illuvatar"

int lamp_is_lit, list_length;
private static int reboot_time, time_from_reset, last_reset_cycle;

void reset(int arg) {
  if(time_from_reset)
    last_reset_cycle = time() - time_from_reset;
  time_from_reset = time();

  if(arg) return;
  set_light(1);
  short_desc = "The village church";
  long_desc =
    "You are in the church of the village. It is a craftly built wooden "+
    "building with many decorations. The aisle leads south to the altar. "+
    "Several colourful glass windows let through a serene light. Wooden "+
    "benches for the churchgoers to hear mass or to pray in stand in "+
    "rows at both sides of the aisle. This church provides the service "+
    "of reviving the dead. The deceased come to church and pray at the "+
    "altar. The church portal to the north stands always open. A small "+
    "door in the east wall leads to the churchyard. You feel the peace "+
    "and holiness of this place and you are sure the gods would punish "+
    "the sacrilege of shedding blood here.\n";

  dest_dir = ({
    HM_VILLAGE + "square2", "north",
    HM_VILLAGE + "churchyard1", "east",
    HM_VILLAGE + "church2", "south",
  });

  items = ({
    "church","This is a church consecrated to " + RELIGION, 
    "building","The building isn't that big, but seems to be able to "+
       "hold many people",
    "decorations","Holy paintings decorate the wall and the roof is "+
       "painted like the sky",
    "paintings","@@display_clock@@",
    "glass","It's real glass, painted in colourful patterns",
    "window","Tall but narrow windows, holding coloured glass",
    "light","The light fills the church serenely, but shines brighter "+
      "at the paintings",
    "benches","Simple wooden benches",
    "rows","Two perfect rows of benches are separated by the aisle",
    "aisle","The aisle leads south to the altar",
    "altar","A beautiful altar, consecrated to "+ RELIGION +". Take "+
       "a closer look at it",
    "portal","The thick wooden portal got stuck in its current position", 
    "door","A small wooden door engraved with skulls",
    "skulls","They all have a cynical grin about them",
    "clock","@@_clock",
  });
		
  property = ({ "has_fire", "no_fight", "no_steal" });
  smell = "The holy smell of burning incence from the altar is mixed with "+
          "fresh worldly air from outside.\n";

  reboot_time = time();
  ::reset(arg);
}

void init() {
  object hat;

  ::init();
  if(TP->query_religion() == RELIGION) {
    if(hat = present("helmet", TP)) {
      if(hat->query_worn())
        call_out("remove_hat", 1);
    }
  }
  
  add_action("pray_it", "pray");
  add_action("pray_it", "regenerate");
}

void remove_hat() {
  write("You take off your hat, respecting "+RELIGION+".\n");
  say(lw(TP->NAME + " takes off " + TP->query_possessive()+
      " hat in the church.\n"));
  command("remove helmet", TP);
  }

nomask status pray_it(string str) {
  string belief;

  belief = TP->query_religion();
  if(!belief) {
    writelw("If you want to become a follower of " + RELIGION + 
            ", then send your prayers to heaven from the holiness "+
            "of the altar.\n");
    return 1;
  }

  if(belief != RELIGION) {
    notify_fail("You are not a follower of "+RELIGION+"!\n");
    return 0;
  }

  if(TP->query_ghost()) {
    write("Pray at the altar, so "+ RELIGION +" will be closer to "+
          "your prayers.\n");
    return 1;
  }

  writelw("You feel that your prayers have reached " + RELIGION + "."+
          "Maybe some time you'll smile as you notice his reward to your "+
          "devotion.\n");
  say(TP->NAME + " sits down and prays.\n");
  return 1;
}

nomask int try_attack(object ob) {
  tell_object(ob, "You feel the eye of the gods burning angrily inside you.\n");
  say("A flash strikes " + ob->RNAME + ".\n", ob);
  ob->reduce_hit_point(random(100)+1);
  return 1;
}

string _clock(string str) {
  int i, j;
  string current_time;
 
  current_time = "The clock shows ";
  i = time() - reboot_time;
  j = i / 86400;
  if(j == 1)
    current_time += "1 day ";
  else if(j > 0)
    current_time += j + " days ";
  i -= j * 86400;
  j = i / 3600;
  if(j == 1)
    current_time += "1 hour ";
  else if(j > 0)
    current_time += j + " hours ";
  i -= j * 3600;
  j = i / 60;
  if(j == 1)
    current_time += "1 minute ";
  else if(j > 0)
    current_time += j + " minutes ";
  i -= j * 60;
  if(i == 1)
    current_time += "1 second";
  else if(i > 0)
    current_time += i + " seconds";
  if(!TP->query_lord())
    return current_time;
  current_time += ".\nTime since reset is " + (time() - time_from_reset) +
    " seconds.\n";
  if(last_reset_cycle)
    current_time += "Reset cycle: " + last_reset_cycle + "\n";
  current_time += "Free block list length: " + list_length;
  return current_time;
}
 
void xyzzy() {
  write("Everything shimmers.\n");
  write("You wake up elsewhere...\n");
  call_other(TP, "move_player", "elsewhere#room/test");
  return;
}
 
int prevent_look_at_inv(string str) {
  return str != 0;
}
 
int query_drop_castle() {
  return 1;
}
 
void light_text(string str) {
  writelw("You hold the " + str + " into the holy candles of the "+
          "altar to light it.\n");
  say(lw(TP->NAME + " lights a " + str + "," +
      "using the holy candles of the altar.\n"));
  if(TP->query_religion() == RELIGION) {
    writelw("You feel very bad about doing this at the altar of "+
            "your own god! His revenge might take you one day!\n");
  }
}

