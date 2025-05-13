inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);

  short_desc="In a cavern";
  long_desc="You are in a big cave inside the volcano.  The walls are made "+
            "of black stones and there are lighted torches fixed to the "+
            "walls.  Thousands of tiny footprints lead east and west.  "+
            "A really odd sound comes from the east.\n";

  items=({"cave","The cave leads further to the east and west",
          "stones","Big black stones lying on the ground",
          "torches","They are lighted and fixed to the walls",
          "walls","The walls are dark and made of black stones",
          "footprints","You see a lot of tiny gnomish footprints",
          "volcano","You areinside the volcano",
        });

  dest_dir=({"/players/emerald/island/room/g25","west",
             "/players/emerald/island/room/g27","east",
           });


  clone_list=({
    1,1,"dragon","/players/emerald/island/obj/copper",0,
  });

  ::reset(arg);
  replace_program("/room/room");

}
