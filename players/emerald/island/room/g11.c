inherit "/room/room";
void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="In a cavern";
  long_desc="You are in a big cave in the volcano.  The walls are made of "+
            "black stones and there are lighted torches fixed to the "+
            "walls.  The air is really hot here.  There is a hot lake to "+
            "the north and some footprints leading back to the south.\n";

  items=({"cave","The cave leads further to the south",
          "stones","Big black stones compose the walls",
          "torches","They are lighted and fixed to the walls",
          "walls","The walls are dark and made of black stones",
          "footprints","You see a lot of tiny gnomish footsprints, "+
                      "leading to the south",
          "volcano","You are just inside the volcano",
          "lake","You see a little dark lake with hot steam coming from it"
        });

  dest_dir=({"/players/emerald/island/room/g9","south",
           });


  clone_list=({
    1,1,"dragon","/players/emerald/island/obj/black",0,
  });

  ::reset(arg);
  replace_program("/room/room");

}
