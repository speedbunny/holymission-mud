inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A path in the countryside";

  long_desc="You are on a small footpath through the weeds.  The land " +
            "around you is flat, and you wonder to where it will lead.\n";

  dest_dir=({"/players/emerald/country/5","north",
             "/players/emerald/country/3","south",
           });

  items=({"path","An old path through the weeds",
          "footpath","An old path through the weeds",
          "weeds","Happy, healthy weeds growing by the side of the field",
        });

  clone_list=({
    1,1,"rabbit","obj/monster", ({
      "set_name","rabbit",
      "set_race","rabbit",
      "set_level",3,
      "set_long","A scared looking field rabbit.\n",
    }),
  });

  ::reset(arg);
   replace_program("/room/room");

}
