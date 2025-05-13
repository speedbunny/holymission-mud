/* WHEEL.C - Programmed by Ethereal Cashimor */
/* 240693: Started programming */
/* 280693: New errors */
/* 240793: Galadriel: property no_hide added */
/* 300893: process_string verwijderd */
/* 051094: Added skill-system for massive enjoyment */

inherit "obj/thing";
#include "/obj/lw.h"
#include "/players/cashimor/include/skills.h"
#define DAMAGE_EACH_LEVEL 5

int level,local;

reset(arg) {
  if(!arg) {
    set_name("wheel");
    set_short("An iron wheel");
    set_long("This is an iron wheel with a chain attached to it. It can be "
           + "used to raise and lower the elevator by turning it right or "
           + "left.\n");
    set_can_get(0);
  }
}

long(str) {
  if(str=="shaft") {
    write(lw("You look into the shaft and you see that the elevator is "
        + elevator()+" you.\n"));
    return;
  }
  ::long();
  if(!local) {
    write("It is mounted near the shaft of the elevator.\n");
    return;
  }
  write("It is mounted in the middle of the platform.\n");
}

/* Galadriel: thieves cannot hide the wheel */
query_property(arg) {
  return arg == "no_hide";
}

elevator() {
  if(check_elevator(0)) return "at the same level as";
  if("players/cashimor/rooms/elevator"->query_level()<level) return "below";
  return "above";
}

init() {
  ::init();
  add_action("turn_it","turn");
  if(!local) add_action("west_it","west");
  if(!local) add_action("jump_it","jump");
}

turn_it(str) {
string dir;
int tmp;

  if(!str) {
    notify_fail("Turn what?\n");
    return 0;
  }
  if(str=="wheel") {
    notify_fail("Turn wheel in which direction (left or right)?\n");
    return 0;
  }
  if(sscanf(str,"wheel %s",dir)!=1) {
    notify_fail("Turn what how?\n");
    return 0;
  }
  tmp=SS_PLACE->check_skill(this_player(),SS_BEND_BARS_LIFT_GATES,SS_ROUTINE);
  switch(tmp) {
    case SS_ABSOLUTE_FAILURE:
      write("You lose control over the wheel and it moves the wrong way.\n");
      say(this_player()->query_name()+" loses control over the wheel.\n");
      if(dir=="left") {
        dir=="right";
      }
      else {
        dir=="left";
      }
      break;
    case SS_FAILURE:
      write("You fail to turn the wheel.\n");
      say(this_player()->query_name()+" fails to turn the wheel.\n");
      return 1;
    case SS_PARTIAL_SUCCESS:
      write("You manage to move the wheel, but it falls back.\n"); 
      say(lw(this_player()->query_name()
           + " manages to move the wheel, but it falls back.\n"));
      return 1;
    case SS_NEAR_SUCCESS:
      write(lw("You manage to move the wheel slightly, but the platform "
             + "doesn't move.\n"));
      say(lw(this_player()->query_name()+" manages to move the wheel "
           + "slightly, but the platform doesn't move.\n"));
      return 1;
    case SS_SUCCESS:
      break;
    case SS_ABSOLUTE_SUCCESS:
      write("You only use your little finger to turn the wheel.\n");
      say(lw(this_player()->query_name()+" uses only "
           + this_player()->query_possessive()
           + " little finger to turn the wheel.\n"));
      break;
  }
  if(dir=="left") {
    say(this_player()->query_name()+" turns the wheel left.\n");
    write("You turn the wheel left.\n");
    if("players/cashimor/rooms/elevator"->lower_platform()) {
      if(local) return 1;
      write("You feel that you lower the elevator.\n");
    }
    check_elevator(1);
    return 1;
  }
  if(dir=="right") {
    say(this_player()->query_name()+" turns the wheel right.\n");
    write("You turn the wheel right.\n");
    if("players/cashimor/rooms/elevator"->raise_platform()) {
      if(local) return 1;
      write("You feel that you raise the elevator.\n");
    }
    check_elevator(1);
    return 1;
  }
  notify_fail("Turn wheel how?\n");
  return 0;
}

check_elevator(verbose) {
  if(local) return;
  if("players/cashimor/rooms/elevator"->query_level()==level) {
    if(verbose) tell_room(environment(this_object()),lw("A platform arrives "
                        + "on this floor in the elevatorshaft.\n"));
    return 1;
  }
  return 0;
}
 
set_level(i) {
  level=i;
}

id(str) {
  if(str=="wheel") return 1;
  if((str=="shaft")&&(!local)) return 1;
}

set_local() {
  local=1;
}

west_it() {
  if(!check_elevator(0)) {
    write(lw("You'd fall into the shaft if you did that, but if you really "
           + "want to do that, just type 'jump shaft'\n"));
    return 1;
  }
  this_player()->move_player("west#players/cashimor/rooms/elevator");
  return 1;
}

jump_it(str) {
int damage,elevator;
string location;

  if((!str)||(str!="shaft")) {
    notify_fail("Jump where?\n");
    return 0;
  }
  if(check_elevator(0)) {
    notify_fail("You can't do that while the elevator is here.\n");
    return 0;
  }
  elevator="players/cashimor/rooms/elevator"->query_level();
  if(elevator>level) {
    damage=level+1;
    location="players/cashimor/rooms/pit";
  }
  else {
    damage=level-elevator;
    location="players/cashimor/rooms/elevator";
  }
  write("You jump into the shaft. AAAaaargh.\n");
  say(this_player()->query_name()+" jumps into the shaft.\n");
  this_player()->move_player("into the shaft#"+location);
  this_player()->hit_player(damage*DAMAGE_EACH_LEVEL,2);
  return 1;
}





