/* FLOOR.C - Programmed by Ethereal Cashimor */
/* 210793: Bathroom added */
/* 140993: Curtain problem removed */

inherit "room/room";

int door,curtain;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="First floor";
    long_desc="You're on the first floor of a cozy house. It's still empty "
            + "here. Light comes in from the north. There is a door to the "
            + "east and a curtain to the south.\n";
    set_light(1);
    smell="The smell of the sea is strong here.";
    dest_dir=({"players/cashimor/extend/corridor","down",
               "players/cashimor/extend/balcony","north"});
    items=({"house","It's really very cozy",
            "light","It seems to come from a balcony",
            "curtain","@@curtain_status@@",
            "door","@@door_status@@"});
  }
}

query_door() {
  return door;
}

query_curtain() {
  return curtain;
}

set_door(how) {
  if(how) {
    tell_room(this_object(),"The door is closed from the other side.\n");
    door=1;
    return;
  }
  tell_room(this_object(),"The door is opened from the other side.\n");
  door=0;
}

set_curtain(how) {
  if(how) {
    tell_room(this_object(),"The curtain is closed from the other side.\n");
    curtain=1;
    return;
  }
  tell_room(this_object(),"The curtain is opened from the other side.\n");
  curtain=0;
}

door_knock() {
  tell_room(this_object(),"You hear someone knocking on the door.\n");
}

door_status() {
  if(door) return "The door is closed";
  return "The door is open";
}

curtain_status() {
  if(curtain) return "The curtain is closed";
  return "The curtain is open";
}

init() {
  ::init();
  add_action("open_it","open");
  add_action("close_it","close");
  add_action("knock_it","knock");
  add_action("east_it","east");
  add_action("south_it","south");
}

east_it() {
  if(door) {
    notify_fail("The door is closed.\n");
    return 0;
  }
  this_player()->move_player("east#players/cashimor/extend/bedroom");
  return 1;
}

south_it() {
  if(curtain) {
    notify_fail("The curtain is closed.\n");
    return 0;
  }
  this_player()->move_player("south#players/cashimor/extend/bathroom");
  return 1;
}

close_it(str) {
  if(!str) {
    notify_fail("Close what?\n");
    return 0;
  }
  if(str=="curtain") {
    if(curtain) {
      notify_fail("But the curtain is already closed!\n");
      return 0;
    }
    curtain=1;
    write("You close the curtain.\n");
    say(this_player()->query_name()+" closes the curtain.\n");
    return 1;
  }
  if(str!="door") {
    notify_fail("Close what?\n");
    return 0;
  }
  if(door) {
    notify_fail("But the door is already closed!\n");
    return 0;
  }
  door=1;
  write("You close the door.\n");
  say(this_player()->query_name()+" closes the door.\n");
  return 1;
}

open_it(str) {
  if(!str) {
    notify_fail("Open what?\n");
    return 0;
  }
  if(str=="curtain") {
    if(!curtain) {
      notify_fail("But the curtain is already open!\n");
      return 0;
    }
    if("players/cashimor/extend/bathroom"->query_present()) {
      notify_fail("The curtain refuses to open.\n");
      return 0;
    }
    curtain=0;
    write("You open the curtain.\n");
    say(this_player()->query_name()+" opens the curtain.\n");
    return 1;
  }
  if(str!="door") {
    notify_fail("Open what?\n");
    return 0;
  }
  if(!door) {
    notify_fail("But the door is already open!\n");
    return 0;
  }
  if("players/cashimor/extend/bedroom"->query_present()) {
    notify_fail("The door refuses to open.\n");
    return 0;
  }
  write("You open the door.\n");
  say(this_player()->query_name()+" opens the door.\n");
  door=0;
  return 1;
}
  
knock_it(str) {
  if((!str)||(str!="door")) {
    notify_fail("Knock what?\n");
    return 0;
  }
  write("You knock on the door.\n");
  say(this_player()->query_name()+" knocks on the door.\n");
  "players/cashimor/extend/bedroom"->door_knock();
  return 1;
}





