/* STRIKER.C, Programmed by Whisky */
/* 270593: Ethereal Cashimor: looking for a bug and revamp */

#include "/obj/lw.h"
#define DAMAGE 15
#define AMOUNT 10

int timer,counter;

short() {
  return "A blue Striker";
}

long() {
  write(lw("This is a new kind of weapon. You can use it beside your general "
         + "weapon during a battle. If you are attacked by a monster, just "
         + "type <strike> a few times during the fight. But this weapon can "
         + "only be used several times. And beware to attack other players "
         + "with this weapon.\n"));
}

init() {
  add_action("do_kill","strike");
}

id(str) { 
  return str == "striker"; 
}

do_kill(str) {
object victim;
string player_name,victim_name;
int how_hard;

  if(str) return;
  if(!present(this_object(),this_player())) {
    notify_fail("You're not carrying the striker!\n");
    return 0;
  }
  if (!this_player()->query_attack()) {
    write("You aren't hunted by anybody.\n");
    return 1;
  }
  if(timer) {
    write("You can't be that fast.\n");
    return 1;
  } 
  victim=this_player()->query_attack();
  if(counter++>=AMOUNT) {
    write("Suddenly your striker gets hot and falls to ashes.\n");
    destruct(this_object());
    return 1;
  }
  say(lw(this_player()->query_name()+" strikes "+victim->query_name()
       + " to hash.\n"));
  write("You are striking "+victim->query_name()+" extremely hard.\n");
  victim->hit_player(DAMAGE);
  timer=1;
  call_out("strike_again",1);
  return 1;
}

strike_again() {
  timer=0;
}

query_weight() { 
  return 1; 
}

get() { 
  return 1; 
}

query_value() { 
  return DAMAGE*AMOUNT; 
}





