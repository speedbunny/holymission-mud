inherit "room/room";

object bath;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Bathroom";
    long_desc="This is the bathroom. It's decorated with tiles with blue "
            + "pictures on it. There is a curtain in the north wall.\n";
    set_light(1);
    smell="This room smells very fresh.";
    items=({"bathroom","It's a nice, though cold looking bathroom",
            "tiles","They are white and blue",
            "curtain","@@door_status@@",
            "pictures","Mostly of ships, trees, apples, and the like"});
    if(!bath) {
      bath=clone_object("players/cashimor/things/bath");
      move_object(bath,this_object());
    }
    property=({"no_teleport"});

  }
}

door_status() {
  if("players/cashimor/extend/floor"->query_curtain()) 
    return "The curtain is closed";
  return "The curtain is open";
}

init() {
  if("players/cashimor/extend/floor"->query_curtain()) {
    write("Unfortunately, that room is closed for you at the moment.\n");
    move_object(this_player(),"room/church");
    return;
  }
  ::init();
  add_action("open_it","open");
  add_action("close_it","close");
  add_action("north_it","north");
}

north_it() {
  if("players/cashimor/extend/floor"->query_curtain()) {
    notify_fail("But the curtain is closed!\n");
    return 0;
  }
  this_player()->move_player("north#players/cashimor/extend/floor");
  return 1;
}

open_it(str) {
  if((!str)||(str!="curtain")) {
    notify_fail("Open what?\n");
    return 0;
  }
  if(!"players/cashimor/extend/floor"->query_curtain()) {
    notify_fail("But it is already open!\n");
    return 0;
  }
  "players/cashimor/extend/floor"->set_curtain(0);
  write("You open the curtain.\n");
  say(this_player()->query_name()+" opens the curtain.\n");
  return 1;
}

close_it(str) {
  if((!str)||(str!="curtain")) {
    notify_fail("Close what?\n");
    return 0;
  }
  if("players/cashimor/extend/floor"->query_curtain()) {
    notify_fail("But it is already closed!\n");
    return 0;
  }
  write("You close the curtain.\n");
  say(this_player()->query_name()+" closes the curtain.\n");
  "players/cashimor/extend/floor"->set_curtain(1);
  return 1;
}

query_present() {
int i;
object all;

  all=all_inventory(this_object());
  for(i=0;i<sizeof(all);i++)
    if(living(all[i])) return 1;
}
