inherit "/room/room";
void reset(int arg) {
  if (arg) return;

  set_light(1);
  short_desc="On an island";

  long_desc="You are standing on top of a little sandbank.  To the west "+
            "is a strange volcanic island.  The sea around the sandbank "+
            "is deep and clear.  Sunlight glistens on the waves.  The "+
            "tranquility of this spot is broken by the rumblings of the "+
            "volcano.\n";

  items=({"sandbank","You could climb down it back into the sea",
          "top","The top of a little sandbank",
          "island","A volcanic island",
          "sea","The sea is deep and clear",
          "sunlight","It is bright and warm",
          "waves","Tiny wavelets in the sea",
          "spot","It's really quite nice here",
          "volcano","An active volcano, busy creating its island",
        });

  dest_dir=({"/players/emerald/island/room/i15", "west",
             "/players/emerald/island/room/i20","northwest"
           });

  ::reset(arg);


}
void init() {
  ::init();
  add_action("_climb","climb");
}
_climb(string str) {
  if(!str) {
    notify_fail("Climb what?\n");
    return 0;
  }
  if(str=="sandbank" || str=="down") {
    write("You climb down the sandbank into the sea.\n");
    this_player()->move_player("down#players/emerald/seaworld/room/sw10");
    return 1;
  }
}
