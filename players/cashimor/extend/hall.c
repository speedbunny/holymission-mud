inherit "room/room";

object key;

reset(arg) {
object door1,door2;

  ::reset(arg);
  if(!arg) {
    short_desc="Entrance hall";
    long_desc="This is the entrance hall of a little house near the sea. It "
            + "is protected from the wind. There is a doormat lying here.\n";
    set_light(1);
    items=({"knocker","It's a copper hand holding a ball",
            "house","It seems a good and nice shelter",
            "wind","The ever blowing sea wind",
            "doormat","It has the letters 'welcome' written on it"});
    smell="The air is salt here, probably caused by the sea.";
    dest_dir=({"room/vill_shore4","north"});
    if(!present("door",this_object())) {
      door1=clone_object("obj/door");
      door2=clone_object("obj/door");
      door1->set_dir("south");
      door2->set_dir("north");
      door1->set_code("c&h");
      door2->set_auto_unlock(1);
      door1->set_type("purple");
      door1->set_can_lock(1);
      door1->set_door(door2);
      door2->set_door(door1);
      door1->set_room("players/cashimor/extend/hall");
      door2->set_room("players/cashimor/extend/corridor");
      door1->set_closed(1);
      door1->set_locked(1);
      door1->set_both_status();
      door1->set_door_long("It's a green door and has a knocker on it.\n");
      door2->set_door_long("It's a normal green door.\n");
    }
  }
}

init() {
  ::init();
  add_action("knock_it","knock");
  add_action("search_it","search");
  add_action("hide_it","hide");
}

knock_it(str) {
  if((!str)||(str!="door")) {
    notify_fail("Knock what?\n");
    return 0;
  }
  write("You use the door knocker to knock on the door.\n");
  say(this_player()->query_name()+" knocks on the door.\n");
  "players/cashimor/extend/corridor"->door_knock();
  return 1;
}

search_it(str) {
  if((!str)||(str!="doormat")) return 0;
  if(!key) {
    key=clone_object("obj/key");
    key->set_code("c&h");
    key->set_type("purple");
    move_object(key,this_object());
    write("You find a key!\n");
    say(this_player()->query_name()+" finds a key under the doormat.\n");
    return 1;
  }
  write("You find nothing special.\n");
  say(this_player()->query_name()+" searches the doormat unsuccesfully.\n");
  return 1;
}

hide_it(str) {
object what;

  if((!str)||(str!="key")) {
    notify_fail("Hide what?\n");
    return 0;
  }
  what=present(str,this_player());
  if(!what) {
    notify_fail("Hide what?\n");
    return 0;
  }
  if(what!=key) {
    notify_fail("That key doesn't fit under the doormat.\n");
    return 0;
  }
  destruct(what);
  write("You hide the key under the doormat.\n");
  say(this_player()->query_name()+" hides a key under the doormat.\n");
  return 1;
}

walk_above() {
  tell_room(this_object(),"Someone walks on the balcony above you.\n");
}






