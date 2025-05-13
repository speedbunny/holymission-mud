inherit "room/room";

int window;

reset(arg) {
object bed;

  ::reset(arg);
  if(!arg) {
    short_desc="Bedroom";
    long_desc="You're in a warm and friendly bedroom. There is a window in "
            + "the east wall, and a door in the west wall. There are "
            + "sheepskins around the bed.\n";
    no_obvious_msg="";
    set_light(1);
    smell="There is sleep in the air.";
    items=({"wall","They are covered with tapestries, damping the sound",
            "window","@@window_status@@",
            "door","@@door_status@@",
            "curtains","They are red and thick",
            "sheepskins","They are white and look comfortable"});
    property=({"no_teleport"});
    if(!present("bed",this_object())) {
      bed=clone_object("players/cashimor/things/bed");
      move_object(bed,this_object());
    }    
  }
}

door_status() {
  if("players/cashimor/extend/floor"->query_door()) 
    return "The door is closed";
  return "The door is open";
}

window_status() {
  if(window) return "There are curtains hanging before it";
  return "There are curtains hanging next to it. Light streams into the room\n"
       + "through it, it looks out over the sea";
}

init() {
  if("players/cashimor/extend/floor"->query_door()) {
    write("Unfortunately, that room is closed for you at the moment.\n");
    move_object(this_player(),"room/church");
    return;
  }
  ::init();
  add_action("open_it","open");
  add_action("close_it","close");
  add_action("west_it","west");
  add_action("echo","echo");
}

west_it() {
  if("players/cashimor/extend/floor"->query_door()) {
    notify_fail("But the door is closed!\n");
    return 0;
  }
  this_player()->move_player("west#players/cashimor/extend/floor");
  return 1;
}

open_it(str) {
  if((!str)||((str!="door")&&(str!="curtains"))) {
    notify_fail("Open what?\n");
    return 0;
  }
  if(str=="curtains") {
    if(!window) {
      notify_fail("But the curtains are already open!\n");
      return 0;
    }
    write("You open the curtains.\n");
    say(this_player()->query_name()+" opens the curtains.\n");
    set_light(1);
    window=0;
    return 1;
  }
  if(!"players/cashimor/extend/floor"->query_door()) {
    notify_fail("But it is already open!\n");
    return 0;
  }
  "players/cashimor/extend/floor"->set_door(0);
  write("You open the door.\n");
  say(this_player()->query_name()+" opens the door.\n");
  return 1;
}

close_it(str) {
  if((!str)||((str!="door")&&(str!="curtains"))) {
    notify_fail("Close what?\n");
    return 0;
  }
  if(str=="curtains") {
    if(window) {
      notify_fail("But they are already closed!\n");
      return 0;
    }
    write("You close the curtains.\n");
    say(this_player()->query_name()+" closes the curtains.\n");
    set_light(-1);
    window=1;
    return 1;
  }
  if("players/cashimor/extend/floor"->query_door()) {
    notify_fail("But it is already closed!\n");
    return 0;
  }
  write("You close the door.\n");
  say(this_player()->query_name()+" closes the door.\n");
  "players/cashimor/extend/floor"->set_door(1);
  return 1;
}

door_knock() {
  tell_room(this_object(),"Someone knocks softly on the door.\n");
}

query_present() {
int i;
object all;

  all=all_inventory(this_object());
  for(i=0;i<sizeof(all);i++)
    if(living(all[i])) return 1;
}


echo (str) {
  if (str) tell_room (this_object(),str+"\n");
  return 1;
}
