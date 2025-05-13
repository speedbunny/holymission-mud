inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="Inside a huge doorway";

  long_desc="You are standing underneath a huge doorway.  To the north you "+
            "can see some big shadows and there are terrible sounds "+
            "floating down to your ears.  You shiver in fear.  Above the "+
            "doorway in an inscription.\n";

  items=({"doorway","The doorway makes the beginning of some terrible place",
          "shadows","They look really enormous",
          "inscription","It reads, 'Stay out or die!'",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/ci48","north",
             "/players/emerald/island/room/caves/room/ci46","down",
           });

  ::reset(arg);
  replace_program("/room/room");

}
