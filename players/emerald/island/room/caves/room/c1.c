inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc = "A hidden passage";

  long_desc="This is a hidden passage inside the volcano.  The bottom "+
            "is covered with water, and slimy green fungus grows on the "+
            "walls.  The only exit is to the north.  A large crack is in "+
            "one wall.\n";

  items=({"bottom","Kneedeep water covers the bottom",
          "volcano","An active volcano, prone to errupting",
          "passage","A hidden passage in the volcano",
          "wall","There is a very large crack in the wall",
          "exit","The only obvious exit is to the north",
          "water","The water is dirty and and seems mildly acidic",
          "walls","Granite walls",
          "fungus","Green slimy fungus covers the walls",
          "crack","It's a small crack, but maybe you could enter it",
        });
 
  dest_dir=({"/players/emerald/island/room/caves/room/c2","north",
           });

  ::reset(arg);

}

void init() {
  ::init();
  add_action("do_enter","enter");
}

int do_enter(string arg) {
  if (arg!="crack") {
    notify_fail("Enter what?\n");
    return 0;
  }
  if(arg=="crack") {
    write("You squeeze through the crack in the wall.\n");   
    this_player()->move_player(
    "squeezing through a crack#/players/emerald/island/room/g25");
    return 1;
  }
}
