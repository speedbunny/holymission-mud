inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="The beach just beyond the dunes";
  long_desc="Animal tracks emerge from the dunes and wander across the " +
            "beach towards the water.  They appear to have been made by a " +
            "medium-sized, four-footed animal.  The tracks meander between " +
            "the grass clumps and circle around the piles of shells " +
            "and detritus left by the last high tide.\n";

  dest_dir=({"/players/emerald/plain/b12","north",
             "/players/emerald/plain/b08","south",
             "/players/emerald/plain/b11","east",
             "/players/emerald/plain/d07","west",
             "/players/emerald/plain/b13","northeast",
             "/players/emerald/plain/d09","northwest",
             "/players/emerald/plain/b09","southeast",
             "/players/emerald/plain/d05","southwest",
           });

  items=({"tracks","Footprints in the sand",
          "dunes","Mounds of accumulated sand",
          "beach","A wide sandy beach",
          "water","The vast expanse of blue sea",
          "animal","The maker of the tracks",
          "clumps","Tuffets of grass growing between the dunes",
          "piles","Debris deposited by the tide",
          "shells","The former homes of marine animals",
          "detritus","Bits of this and that left behind by the passing tide",
        });

  clone_list=({
    1,1,"fox","obj/monster", ({
      "set_name","fox",
      "set_race","canine",
      "set_aggressive",1,
      "set_short","A red fox",
      "set_long","A red fox hunting for food on the beach.\n",
      "set_level",15,
      "add_money",200,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
