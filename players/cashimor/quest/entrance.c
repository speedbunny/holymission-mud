/* ENTRANCE.C - Programmed by Ethereal Cashimor */
/* 080394: Started programming */

inherit "obj/treasure";
#include "/players/cashimor/include/general.h"

int rose,xp;

reset(arg) {
  if(!arg) {
    set_name("entrance");
  }
  set_short(0);
  rose=1;
  xp=0;
}

init() {
  add_action("search_it","search");
  add_action("enter_it","enter");
  add_action("cut_it","cut");
  add_action("cut_it","remove");
  add_action("read_it","read");
}

search_it() {
  if(random(MAX_STAT)<=this_player()->query_int()) {
    write("You find a dark entrance to a building.\n");
    say(this_player()->query_name()+" uncovers an entrance.\n");
    set_short("An entrance");
    set_long("The entrance is fully overgrown with bushes, ivy and\n"
           + "roses. You can barely make out a very dark opening.\n");
    return 1;
  }
  write("You find nothing special.\n");
  return 1;
}

enter_it(str) {
  if((!str)||((str!="entrance")&&(str!="opening"))||(!short())) {
    notify_fail("Enter what?\n");
    return 0;
  }
  write("You enter the entrance...\n");
  say(this_player()->query_name()+" enters the entrance.\n");
  if(rose) {
    write("You are scratched by the roses that are here.\n");
    this_player()->hit_player(random(HALF_HP));
  }
  this_player()->
   move_player("into the entrance#players/cashimor/quest/tunnel");
  return 1;
}

cut_it(str) {
  if((!str)||((str!="rose")&&(str!="roses"))||(!rose)) {
    notify_fail("Cut what?\n");
    return 0;
  }
  this_player()->add_exp(BASIC_XP);
  write("You remove the roses from the entrance...\n");
  say(this_player()->query_name()+" removes the roses from the\n"
    + "entrance.\n");
  if(random(MAX_STAT)>this_player()->query_dex()) {
    write("But cut yourself while doing it.\n");
    this_player()->hit_player(random(HALF_HP/2));
  }
  rose=0;
  return 1;
}

long(str) {
  ::long();
  if(!rose) { 
    write("The roses have been cut away from the entrance. At the\n"
        + "place where the roses were you can see some symbols on the\n"
        + "wall\n");
  }
}

get() {
  return 0;
}

read_it(str) {
  if((!str)||(str!="symbols")||(rose)) {
    notify_fail("Read what?\n");
    return 0;
  }
  if(random(MAX_STAT)>this_player()->query_int()) {
    notify_fail("You're unable to read the strange symbols.\n");
    return 0;
  }
  write("The strange symbols seem to convey a warning to you.\n");
  if(!xp) {
    this_player()->add_exp(BASIC_XP);
    xp=1;
  }
  say(this_player()->query_name()+" is frightened by the symbols\n"
    + "above the entrance.\n");
  return 1;
}










