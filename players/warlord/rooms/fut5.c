

inherit "room/room";
object o1,o2;


reset(arg) {
if (!o1) {o1=clone_object("players/warlord/monsters/garg");
move_object(o1,this_object());}
if (!o2) {o2=clone_object("players/warlord/monsters/garg");
move_object(o2,this_object());}
    if (arg) return;

    set_light(1);
    short_desc = "A storage room";
    long_desc = 
        "You have entered the sorceror's fairly large storage room. You notice a couple\n"+
     " of Gargoyles guarding the items in the room. There is a sign\n"+
        " on the wall that says: Danger do not go Southwest!!!\n";
    items =
          ({
           "sign","The room southwest has dangers beyond your comprehension",
          });
    dest_dir = 
        ({
        "players/warlord/rooms/fut4", "northeast",
        "players/warlord/rooms/fut6", "east",
        "players/warlord/rooms/fut7", "southeast",
        "players/warlord/rooms/fut8", "southwest",
        });
}
init() {::init();
  add_action("southwest","southwest");
  add_action("southeast","southeast");}

southwest() {
  if(present("gargoyle")) {tell_room(this_object(), "Gargoyle says: NO MORTAL SHALL PASS !!!\n");
  return 1;
}
return !this_player()->move_player("southwest#players/warlord/rooms/fut8");
}
southeast() {
  if (present("gargoyle")) {tell_room(this_object(), "Gargoyle says: NO MORTAL SHALL PASS !!!\n");
  return 1;
}
return !this_player()->move_player("southeast#players/warlord/rooms/fut7");
}
