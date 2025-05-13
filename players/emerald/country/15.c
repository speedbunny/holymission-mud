inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A road through the farmland";

  long_desc="Fields of ripening grain surround you on both sides.  Far " +
            "off in the distance to the east is a line of trees," +
            " probably marking a watercourse.  The road is beginning to rise "+
            "slightly in elevation to the north.\n";

  dest_dir=({"/players/emerald/country/16","north",
             "/players/emerald/country/14","south",
           });

  items=({"fields","Beautiful fields of grains",
          "trees","Aspens and willows",
          "road","A cobbled road",
        });


  ::reset(arg);
   replace_program("/room/room");

}
