inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A road through the farmland";

  long_desc="You can finally make out the destination at the end of this " +
            "road.  Rising above the crown of the hill are stone walls.  " +
            "They apparantly encircle a town of some sort.  From this " +
            "distance, it's impossible to decipher anything more about it.\n";

  dest_dir=({"/players/emerald/country/18","north",
             "/players/emerald/country/16","south",
           });

  items=({"walls","Sturdy walls protecting the population of a town",
          "town","You are too far away to see anything of the town",
          "road","A cobbled road",
          "hill","A large, low, flat hill",
        });


  ::reset(arg);
   replace_program("/room/room");

}
