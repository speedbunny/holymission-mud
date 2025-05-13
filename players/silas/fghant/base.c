

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Base of Chasm";
    no_castle_flag = 0;
    long_desc = 
        "This is a small room which has been hewn out of the rock by the villagers of\n"
        + "Keidall. The only item of interest here is a small cabin towards the back of\n"
        + "the room although a poster on one of the walls also catches your attention.\n";
    items = ({
         "cabin","It's shaped like a phone booth, maybe you should investigate",
         "poster","Welcome to Keidall, your home away from home!"
            });
    dest_dir = 
        ({
        "/players/silas/fghant/keidall1", "north",
        });
    smell = "A potpourri of nature's aromas enters your nose.\n";
}
init() {
  ::init();
  add_action("enter","enter");
}

enter(str) {
  if (str=="cabin") {
  write("You enter the cabin.\n");
  this_player()->move_player("enters the cabin#players/silas/fghant/cabin2");
  return 1;
  }
  else {
  write("What do you want to enter?\n");
  return 1;
  }
}


