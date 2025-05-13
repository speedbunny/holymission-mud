inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A road through the farmland";

  long_desc="The track opens up here into a full-fledged road.  It wends " +
            "its way up to the north and disappears to the southeast over " +
            "a little hill.  On either side of you lie fields of barley " +
            "and rye.\n";

  dest_dir=({"/players/emerald/country/14","north",
             "/players/emerald/country/8","southeast",
             "/players/emerald/country/6","west",
           });

  items=({"road","A cobbled road",
          "fields","Small fields of grain",
          "hill","It rises to the southeast",
        });


  ::reset(arg);
   replace_program("/room/room");

}
