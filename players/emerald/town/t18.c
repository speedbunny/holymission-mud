inherit "/room/room";

void reset (int arg) {

  if(arg) return;
  set_light(1);

  short_desc="A side street";

  long_desc="This is a quiet side street in the northern section of town.  " +
            "A few well-dressed people are passing by you, sedately walking " +
            "to whatever their destinations might be.  A few people are " +
            "leading horses in obvious need of shoeing.\n";

  dest_dir=({"/players/emerald/town/t14","east",
             "/players/emerald/town/t19","west",
           });

  items=({"street","A small side street",
          "people","They appear to not be of the poorer classes",
          "horses","They need better shoes",
  });

  ::reset(arg);
   replace_program("/room/room");

}
