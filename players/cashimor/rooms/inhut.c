inherit "room/room";

object voorwerp;

reset(arg) {
  if(!arg) {
    set_light(1);
    short_desc="In a hut";
    long_desc="You're in a hut of a Hermit.\n";
    smell="A dusty air is here.";
    dest_dir=({"players/cashimor/rooms/hermit","out"});
  }
  if(!present("hermit",this_object())) {
    voorwerp=clone_object("players/cashimor/monsters/hermit");
    move_object(voorwerp,this_object());
  }
  if(!present("tag",this_object())) {
    voorwerp=clone_object("players/cashimor/objects/xp");
    move_object(voorwerp,this_object());
  }
}
