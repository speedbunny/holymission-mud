inherit "players/cashimor/inherit/sand";

reset(arg) {
object door1,door2;

  ::reset(arg);
  if(!arg) {
    short_desc="Corridor";
    long_desc="You are in the corridor of a house. It's rather empty here.\n"
            + "The remains of a ladder point to a hole in the ceiling.\n";
    dest_dir=({"players/cashimor/room/livingroom","north",
               "players/cashimor/room/trapdoor","up"});
    items=({"corridor","It is very empty",
            "ladder","Maybe it's climbable, but you never can be sure..",
            "house","It wasn't pretty, even in it's best days",
             "hole","It seems to be newer than the rest of the house"});
    if(!present("door",this_object())) {
      door1=clone_object("players/cashimor/inherit/sanddoor");
      door2=clone_object("players/cashimor/inherit/sanddoor");
      door1->set_dir("south");
      door2->set_dir("north");
      door1->set_code("jen");
      door2->set_code("jen");
      door1->set_type("sandstone");
      door2->set_type("sandstone");
      door1->set_can_lock(1);
      door2->set_can_lock(1);
      door1->set_door(door2);
      door2->set_door(door1);
      door1->set_room("players/cashimor/room/corridor");
      door2->set_room("players/cashimor/room/outside");
      door1->set_closed(1);
      door1->set_locked(1);
      door1->set_both_status();
      door1->set_door_long("It's a heavy, sturdy, old door.\n");
      door2->set_door_long("It's a heavy, damaged old door.\n");
    }
  }
}

init() {
  ::init();
  add_action("climb_it","climb");
}

climb_it(str) {
  if((!str)||(str!="ladder")) {
    notify_fail("Climb what?\n");
    return 0;
  }
  return command("up",this_player());
}
