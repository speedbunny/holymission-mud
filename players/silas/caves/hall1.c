

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Hall of Wizards";
    no_castle_flag = 0;
    long_desc = 
        "A lavish hall extends north and south as far as the eye can see. The floor\n"
        + "is covered with colored tiles and you see various openings in the walls up\n"
        + "ahead. In the western wall you can see a shimmering portal. A sign on one\n"
        + "of the walls beckons you to look at it.\n";
    items = ({
         "sign","BEWARE! Attacking the wax likenesses will cause them to come to life!",
         "portal","A portal with shimmering blue light emanating from it",
    });
    dest_dir = 
        ({
        "/players/silas/caves/hall2", "north",
        });
    smell = "Fresh, fragrant air revitalizes your senses.\n";
}
init() {
  ::init();
  add_action("enter","enter");
}

enter(str) {
  if (str=="portal") {
     write("You enter the portal and emerge elsewhere.\n");
     this_player()->move_player("steps through the portal#players/silas/caves/stunnel4");
     return 1;
  }
  else {
  write("What do you want to enter?\n");
  return 1;
  }
}

query_light() {
    return 1;
}
