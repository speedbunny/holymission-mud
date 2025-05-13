/* PIT.C - Programmed by Ethereal Cashimor */
/* 280693: Started programming */

inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="The pit";
    long_desc="You've fallen on the bottom of the elevator shaft. This is a "
            + "dirty place.\n";
    smell="It stinks here.";
    set_light(1);
    items=({"bottom","It's very hard. Your body still aches",
            "shaft","There is an exit to the east right above you",
            "place","It's very dirty indeed"});
  }
}

init() {
  ::init();
  add_action("climb_it","climb");
}

climb_it(str) {
  if((!str)||(str!="shaft")) {
    notify_fail("Climb what?\n");
    return 0;
  }
  write("You climb out of the pit.\n");
  this_player()->move_player("up#room/wiz_hall");
  return 1;
}
