inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc="On a prairie";

  long_desc="The small prairie is surrounded by the peaks of huge "+
            "mountains.  A dark forest begins to the north, while the "+
            "prairie continues to the south, east, and west.  Small bushes "+
            "dot the ground, mixed with tall grass.  A cloud of yellow "+
            "vapour hangs in the air.\n";


  items=({"prairie","A small prairie on the plateau of the volcano",
          "peaks","The peaks of volcanic mountains",
          "mountains","Tall, volcanic mountains",
          "forest","A dark forest of firs and oaks",
          "bushes","Their leaves show signs of nibbling",
          "grass","Thick, lush grass",
          "cloud","A cloud of volcano gasses",
          "vapour","Volcano gasses",
          "air","The air is almost pure up here",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/p8","east",
             "/players/emerald/island/room/caves/room/p6","west",
             "/players/emerald/island/room/caves/room/p3","south",
             "/players/emerald/island/room/caves/room/f3","north",
           });

  ::reset(arg);
  replace_program("/room/room");

}
