inherit "/room/room";

void reset(int arg) {
  if (arg) return;

  set_light(1);
  short_desc="On an island";

  long_desc="You are standing on a plateau near the top of the volcano.  "+
            "The air is so full of ash that you can hardly see anything.  "+
            "If you look down, you can see over the tops of the palm trees "+
            "and out over the sea.  There is a strange growling sound "+
            "coming from somewhere around here.\n";

 items=({"sea","The clear blue sea",
         "plateau","A plateau near the summit of the volcano",
         "top","The top of the volcano",
         "volcano","An active volcano, spewing ash",
         "air","It is loaded with ash",
         "tops","The tops of waving palm trees",
         "trees","You can just see the tops of the palm trees",
       });

  dest_dir=({"/players/emerald/island/room/i12", "west",
             "/players/emerald/island/room/i14", "up",
           });

  ::reset(arg);
  replace_program("/room/room");

}
