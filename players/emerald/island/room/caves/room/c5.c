inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="A hidden passage";

  long_desc="The bottom of the passage has disappeared underneath "+
            "murky water which reaches to your hips.  Moving is difficult "+
            "because of all the water.  Green fungus coats the walls.  The "+
            "passage continues to the south.  A huge heap of human skulls "+
            "blocks the way to the north.\n";

  items=({"bottom","It cannot be seen through the murky water",
          "water","The water is dirty and mildy acidic",
          "walls","Granite walls covered in green fungus",
          "passage","A hidden passage in the volcano",
          "hips","Your hips",
          "heap","A massive pile of human skulls.  They seem well-packed "+
                 "together.  It might be possible to climb up it",
          "fungus","Really disgusting green fungus",
          "skulls","Their empty eye sockets stare at your menacingly",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/c4","south",
           });

  ::reset(arg);

}    

void init() {
  ::init();
  add_action("do_climb","climb");
}

int do_climb(string arg) {
  if(!arg) {
    notify_fail("Climb what?\n");
    return 0;
  }
  if(arg=="heap") {
    write("You climb the grisly heap of human skulls.\n");
    this_player()->move_player(
    "climbing up the skulls#players/emerald/island/room/caves/room/c6");
    return 1;
  }
}
