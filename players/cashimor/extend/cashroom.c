inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Cashimor's workroom";
    long_desc="This is Cashimor's workroom. It's rather empty and "
            + "undecorated, because he doesn't want to be diverted from his "
            + "work. There is, however, a large window overlooking the sea in "
            + "the east wall. There is a note hanging on the wall.\n";
    items=({"workroom","It has a good working atmosphere",
            "window","Apart from a very pretty view on the sea, the window\n"
                   + "provides enough light to work by",
            "sea","The sea is blue, sometimes a dolphin jumps out of it",
            "note","Something is written on it",
            "wall","Blank and white"});
    smell="The room is very clean.";
    dest_dir=({"players/cashimor/extend/corridor","west"});
    set_light(1);
  }
}

door_knock() {
  tell_room(this_object(),"Someone knocks on the door.\n");
}

init() {
  ::init();
  add_action("rpurr_it","rpurr");
  add_action("read_it","read");
}

read_it(str) {
  if((!str)||(str!="note")) {
    notify_fail("Read what?\n");
    return 0;
  }
  write("The note reads: Additional command defined in this room:\n"
      + "rpurr <person>: to remote purr to someone.\n");
  say(this_player()->query_name()+" reads the note on the wall.\n");
  return 1;
}

rpurr_it(str) {
object who;

  if(!str) {
    notify_fail("Rpurr who?\n");
    return 0;
  }
  who=find_living(str);
  if(!who) {
    notify_fail("Rpurr who?\n");
    return 0;
  }
  tell_object(who,"You hear "+this_player()->query_name()+" purring in the distance.\n");
  write("Ok.\n");
  return 1;
}
