inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A road through the farmland";

  long_desc="You are almost to the gates of the town wall.  The walls " +
            "are not nearly so impressive as you first thought.  They " +
            "rise a mere twenty feet off the ground.  The town itself " +
            "does not appear to be very large, and you wonder what is " +
            "in the town that requires so much protection.\n";

  dest_dir=({"/players/emerald/country/20","north",
             "/players/emerald/country/18","southwest",
           });

  items=({"walls","Sturdy walls protecting the population of a town",
          "town","A decent-sized town",
          "wall","It is made of stone",
          "ground","It supports the weight of the walls",
          "gates","They are made of wood",
        });


  clone_list=({
    1,1,"peasant","obj/monster", ({
      "set_name","peasant",
      "set_race","human",
      "set_short","A peasant",
      "set_long","An able-bodied peasant farmer.\n",
      "set_gender",1,
      "set_level",20,
      "add_money",400,
    }),
  });

  ::reset(arg);
   replace_program("/room/room");

}
