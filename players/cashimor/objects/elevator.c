/* ELEVATOR.C - Programmed by Ethereal Cashimor */
/* 240693: Started programming */

inherit "room/room";
#include "/obj/lw.h"
#define EMPTY    "You're surrounded by dark, oppressing walls on all sides."
#define MINLEVEL 0
#define MAXLEVEL 6

int level;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="The elevator";
    long_desc="You're on a wooden platform with a iron construction in the "
            + "middle. The platform is hanging in a shaft, suspended by a "
            + "chain. @@outlook@@\n";
    set_light(1);
    smell="The air is very cold here.";
    items=({"platform","It is very sturdy, but a little bit instable",
            "chain","The chain leads up into the darkness",
            "walls","They seem to get closer slowly",
            "bottom","Further down is impossible",
            "entrance","Anything would be better than this place",
            "cellar","Probably a place where you can expect an archwizard",
            "opening","It is beautifully decorated with small statues",
            "church","The church of Illuvatar",
            "shaft","It looks dark and menacing",
            "attic","Dusty, but better than this platform",
            "construction","It consists of a wheel and a chain"});
    level=4;
  }
}

init() {
  ::init();
  add_action("enter_it","enter");
  add_action("east_it","east");
}

enter_it(str) {
  if(str) {
    if((str=="gate")&&(level==6)) return east_it();
    if((str=="opening")&&(level==4)) return east_it();
    if((str=="entrance")&&(level==0)) return east_it();
  }
  notify_fail("Enter what?\n");
  return 0;
}

east_it() {
  switch(level) {
    case 0:
      this_player()->move_player("east#room/wiz_hall");
      return 1;
    case 4:
      this_player()->move_player("east#room/church");
      return 1;
    case 6:
      this_player()->move_player("east#room/attic");
      return 1;
    default:
      return 0;
  }
}

outlook() {
  switch(level) {
    case 0:
      return "The platform is at the bottom of the shaft. To the east you can "
           + "see the entrance to a kind of cellar.";
    case 4:
      return "The patform is in the middle of the shaft. To the east is an "
           + "opening to the church.";
    case 6:
      return "You're at the top of the shaft. The chain is attached to a "
           + "large construction above you and a gate leads east to the attic "
           + "of the church.";
    default:
      return "You're surrounded by dark, oppressing walls on all sides.";
  }
}

raise_platform() {
  if(level==MAXLEVEL) {
    tell_room(this_object(),lw("The platform jerks upward, but falls back "
            + "again because it's already at the top.\n"));
    return 0;
  }
  tell_room(this_object(),"The platform moves upward.\n");
  level++;
  return 1;
}

lower_platform() {
  if(level==MINLEVEL) {
    tell_room(this_object(),lw("The chain relaxes a little, but the platform "
            + "is already at the bottom.\n"));
    return 0;
  }
  tell_room(this_object(),"The platform moves downward.\n");
  level--;
  return 1;
}

query_level() {
  return level;
}


