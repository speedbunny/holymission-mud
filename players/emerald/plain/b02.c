inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="The beach by the Ilkin Forest";
  long_desc="The leafy branches of the thick and impenetrable Ilkin Forest "+
            "hang over the sandy beach to the west and south.  They " +
            "provide a welcome amount of shade in contrast to the warm " +
            "sunshine.  A few scrufty bushes grow in front of the " +
            "trees.  Shells and weeds litter the beach to the waterline, " +
            "where the waves roll in at a steady rate.\n";

  dest_dir=({"/players/emerald/plain/b04","north",
             "/players/emerald/plain/b03","east",
             "/players/emerald/plain/b05","northeast",
             "/players/emerald/plain/d01","northwest",
             "/players/emerald/plain/b01","southeast",
           });

  items=({"branches","Thick, black, twisted branches of ancient trees",
          "forest","A haven for evil",
          "beach","A wide white-sand beach",
          "shade","It is nice and cool",
          "bushes","They are covered in long thorns",
          "trees","Old, gnarled trees",
          "shells","The former homes of marine animals",
          "weeds","Plants thrown up by the action of the waves",
          "waterline","The current edge of the water and land",
          "waves","Deep blue waves with white crests",
        });

  clone_list=({
    1,1,"squirrel","obj/monster", ({
      "set_name","squirrel",
      "set_race","rodent",
      "set_short","A squirrel",
      "set_long","A squirrel which has ventured out of the forest.\n",
      "set_level",9,
      "add_money",75,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
