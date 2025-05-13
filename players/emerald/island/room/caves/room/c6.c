inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="A hidden passage";

 long_desc="Foul water reaches up to your knees in this cramped hidden "+
            "passage deep inside the volcano.  Green slime covers the "+
            "walls.  The cave leads on to the north, while to the south, "+
            "a horrifying heap of human skulls leads down further into the "+
            "volcano.\n";

  items=({"water","It reeks, and seems to be mildly acidic",
          "passage","A hidden passage through the volcano",
          "volcano","An active volcano",
          "slime","Nasty, icky, gooey green slime",
          "walls","Granite walls of volcanic origin",
          "cave","You are in a tiny, cramped cave",
          "heap","You could slide down the heap to the bottom",
          "knees","Your knobbly knees, covered in foul water",
          "skulls","They appear to be grinning at you",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/c7","north",
           });
    
  ::reset(arg);

}
void init() {
  ::init();
  add_action("do_slide","slide");
  add_action("do_slide","south");
}

do_slide(string str) {
  if(str!="heap") {
    notify_fail("Slide what?\n");
    return 0;
  }

  write("Ugh, you slide down the heap of skulls.\n");

  this_player()->move_player(
       "sliding down the skulls#players/emerald/island/room/caves/room/c5");
  return 1;
}
