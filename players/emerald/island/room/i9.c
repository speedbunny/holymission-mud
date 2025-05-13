inherit "/room/room";

void reset(int arg) {
  if (arg) return;

  set_light(1);
  short_desc="On an island";

  long_desc="The sun shines down on the beach, its heat reflected by the "+
            "white sand.  A stand of palm trees grows to the west.  A few "+
            "footsteps are discernible in the sand, and an odd noise comes "+
            "from the east.\n";

  items=({"sun","Don't look directly at the sun, you'll go blind",
          "beach","The beautiful beach of the island",
          "sand","Soft white sand",
          "trees","Tall palm trees, swaying in the breeze",
          "footsteps","They aren't yours",
        });

  dest_dir=({"/players/emerald/island/room/i8","west",
             "/players/emerald/island/room/i15","east",
           });

  ::reset(arg);
  replace_program("/room/room");

}
