#include "defs.h"

inherit "room/room";
/* Coded by: Brainsprain@holymission                                    */
/* This room is a generic object used to create an inn.  It heals at a  */
/* rate of 1 hit point per every 7 - con/10 at a cost of 4/cha/10 * hit */
/* points needed to max out.                                            */

/* Normal healing occurs one hp per every 10 heartbeats. */

int rate;                  /* Rate at which hp is recovered */ 
int cost;                  /* Cost to recover all lost hp   */
int pre;                   /* Beginning hit points          */
static status resting;     /* Is player resting             */
string still_resting;      /* String to be said if player is resting */
string full_heal;          /* String to be said if healing is not necessary */
string rest_msg;           /* Message player recieves when resting begins */
string stand_msg;          /* message player recieves when standing up */
string owner;              /* This is the name off the inn keeper */

/* sets the full_heal message */

void bleck() {
  TP->MOVEP("home#players/brainsprain/workroom");
  return;
}

void heal_me() {
  remove_call_out("heal_me");
  TP->reduce_hit_point(- 2);
  if(TP->query_max_hp() > TP->query_hp()){
  call_out("heal_me",rate);
  }
  return;
}

void set_full_heal(string arg) {
  full_heal = arg;
}

/* Sets the rate at which hit points are recovered */
void set_rate() {
  int temp;
  int preint;
  preint = TP->query_con();
#if 0
  temp = to_int(preint/10);
#else
  temp = preint/10;
#endif
  if(temp <= 1) {
    temp = 1;
  }
rate = 7 - temp;
}

/* Returns the rate of hit point recovery */
int query_rate() {
  return rate;
}

/* Sets the cost to recover all lost hit points */
void set_cost(int cst) {
  int temp1;
  int temp2;
#if 0
temp1 = to_int(this_player()->query_chr()/10);
#else
temp1 = this_player()->query_chr()/10;
#endif
  if(temp1 == 0) {
    temp1 = 1;
  }
  if(cst < 0) {
    cst = 0;
  }
  cost = (4/temp1) * cst;
}

/* Returns the cost to recover all lost hit points */
int query_cost() {
  return cost;
}

int _stand() {
  if(resting == 0){
  write("You are not resting!\n");
  return 1;
  }
  resting = 0;
  remove_call_out("heal_me");
  write(stand_msg+"\n");
  if(TP->query_hp() == TP->query_max_hp()) {
    set_cost(TP->query_max_hp() - pre);
  }
  else {
    set_cost(TP->query_hp() - pre);
  }
  call_other(TP, "add_money", -cost);
  TP->remove_property("resting",1);
  write(CAP(owner) + " says: That will be " + cost + " coins.\n");
  return 1;
}

/* Starts the player resting */
int _rest() {
  pre = TP->query_hp();
  set_rate();
  set_cost(TP->query_max_hp() - pre);
  if(query_cost() == 0){
    write(full_heal+"\n");
    return 1;
  }
  if (call_other(TP, "query_money", 0) < cost) {
    write("That costs " + cost + " gold coins, which you do not have.\n");
    return 1;
  }
  resting = 1;
  write(rest_msg+"\n");
  TP->add_property("resting",1);
    if(TP->query_max_hp() > TP->query_hp()){
      heal_me();
    }
    else {
      TP->reduce_hit_points(- (TP->query_max_hp() - pre));
      write("this line\n");
      _stand();
      return 1;
    }
    return 1;
}


void set_rest_msg(string str) {
  rest_msg = str;
}

void set_stand_msg(string str) {
  stand_msg = str;
}

void set_owner(string str) {
  owner = str;
}

void set_still_resting(string str){
still_resting = str;
}

int cmd_hook(string str) {
  string theverb;
  theverb = (string)query_verb();
  if(TP->query_property("resting")){
    if(resting) {
      if(!(TP->query_immortal())){
	if(theverb != "stand" && theverb != "wake" && theverb != "rest"
	   && theverb != "sleep"){ 
	  write(still_resting+"\n");
	  return 1;
	}
      }
    }
  }
}

void reset(int arg) {
  if(arg) return;
  resting = 0;
  set_light(1);
  short_desc = "An inn";
  long_desc = "An inn\n";
  set_full_heal("You are not in need of healing.");
  set_rate();
  set_cost(1);
  set_rest_msg("You lay down and begin to rest.");
  set_stand_msg("You stand up.");
  set_owner("brainsprain");
  property=({"no_fight"});
  set_still_resting("You wouldn't want to disturb yourself, you are resting!\n");
}

void init() {
  ::init();
  add_action("cmd_hook","",1); 
  add_action("bleck","home");
  add_action("_rest","rest");
  add_action("_rest","sleep");
  add_action("_stand","stand");
  add_action("_stand","wake");
}
