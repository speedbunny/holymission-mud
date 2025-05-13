/* PIT.C, Programmed by Ted */
/* 270593: Ethereal Cashimor: heart_beat bug fixed */
/* 230793: Galadriel: some typos fixed and new hurt message */

inherit "room/room";

int climbing;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(0);
    short_desc="Bottom of Pit";
    long_desc="You are at the bottom of a pit. The walls are made from the "
            + "rough cut rock of the mountain.\n";
    items = ({"walls","It looks like you might be able to climb up the\n"
                    + "side of the pit if you are light and strong",
              "wall","It looks like you might be able to climb up the\n"
                    + "side of the pit if you are light and strong"
    });
    smell="The smell of death lingers here.";
  }
}

init() {
  ::init();
  add_action("climb"); add_verb("climb");
}

climb(str) {
  if(!str) {
    notify_fail("Climb what?\n");
    return 0;
  }
  if((str!="wall")&&(str!="walls")) {
    notify_fail("Climb what?\n");
    return 0;
  }
  if(climbing) {
    notify_fail("Someone else is blocking the way.\n");
    return 0;
  }
  if(this_player()->query_guild()==1) {
    write("You easily climb up the side of the pit.\n");
    say(this_player()->query_name()+" climbs up the side of the pit.\n");
    this_player()->move_player("up#players/ted/frost/cave13");
    return 1;
  }
  if(this_player()->query_ghost()) {
    write("You drift up the side of the pit.\n");
    this_player()->move_player("up#players/ted/frost/cave13");
    return 1;
  }
  if(this_player()->query_weight()>(3+this_player()->query_level()/4)) {
    write("You are carrying too much stuff!\n");
    say(this_player()->query_name()+" tries to climb the wall, but slips "
      + "back down.\n");
    return 1;
  }
  write("You begin to climb up the wall of the pit.\n");
  say(this_player()->query_name()+" begins to climb the wall of the pit.\n");
  climbing=1;
  call_out("climb_it",3);
  return 1;
}

climb_it() {
  climbing=0;
  if(random(100)>42) {
    tell_room(this_object(),this_player()->query_name()+" slips and falls\n"
            + "back to the floor!\n", this_player());
    tell_object(this_player(),"You slip and fall back to the floor, that hurts!\n");
    this_player()->hit_player(6);
    return;
  }
  tell_object(this_player(),"You climb out of the pit.\n");
  this_player()->move_player("out of the pit#players/ted/frost/cave13");
}

