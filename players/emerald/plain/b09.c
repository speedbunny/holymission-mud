inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="The beach";
  long_desc="Clam shells are strewn over the beach.  Most of them are " +
            "broken or empty, their occupants long gone due to either the " +
            "hungry sea or the hungry seagulls.  But a few remain intact, " +
            "partially buried in the shifting sand or tangled in a mass " +
            "of seaweed.\n";

  dest_dir=({"/players/emerald/plain/b11","north",
             "/players/emerald/plain/b07","south",
             "/players/emerald/plain/b08","west",
             "/players/emerald/plain/b10","northwest",
             "/players/emerald/plain/b06","southwest",
           });

  items=({"shells","A special form of calcium carbonate",
          "beach","A white-sand beach",
          "sea","A sparkling clear blue sea",
          "seagulls","An ever-hungry seabird",
          "sand","Large grains of silica",
          "seaweed","Kelp and bladderwrack",
          "mass","A pile of green and black seaweed",
        });

  clone_list=({
    1,1,"clam","obj/monster", ({
      "set_name","clam",
      "set_race","mollusc",
      "set_ac",10,
      "set_level",9,
      "set_short","A clam",
      "set_long","A large grey clam lost on the beach.\n",
      "add_money",130,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
