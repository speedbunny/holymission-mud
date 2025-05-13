inherit "room/room";
object ob;
object board;

reset(arg) {
  if (!ob || !living(ob)) {
  ob = clone_object("players/silas/monster/guide");
  move_object(ob,this_object());
  }
    if (arg) return;

    set_light(1);
    short_desc = "Tourist Square";
    no_castle_flag = 0;
    long_desc = 
        "This is where the populace of F'ghant comes to have a good time. A rectangular\n"
        + "opening has been hewn out of the mountain to the north, bringing a spectacular\n"
        + "view of the chasm and the surrounding mountains to the people. Water rushes\n"
        + "down a waterfall, empties into a pool and then runs down into the chasm at\n"
        + "the northern end of the cavern. A small cabin sits in the middle of the room\n"
        + "and a sightseeing deck lies to the north.\n";
    items = ({
         "cabin","It's shaped like a phone booth, maybe you should investigate",
         "pool","It looks quite shallow, maybe you could enter it"
            });
    dest_dir = 
        ({
        "/players/silas/fghant/deck", "north",
        });
    smell = "A fresh breeze from the north brings you the smells of the forest.\n";
}
init() {
  ::init();
  add_action("enter","enter");
}

enter(str) {
  if (str=="pool") {
  write("You enter the pool.\n");
  this_player()->move_player("enters the pool#players/silas/fghant/pool");
  return 1;
  }
/* Herp: FIRST check cabin, then "What ya wanna enter" */
  else if (str=="cabin") {
  write("You enter the cabin.\n");
  this_player()->move_player("enters the cabin#players/silas/fghant/cabin3");
  return 1;
  }
  else {
  write("What do you want to enter?\n");
  return 1;
  }
}


