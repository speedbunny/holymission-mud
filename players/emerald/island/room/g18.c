inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc="In a cavern";
  long_desc="You are in a big cave inside the volcano.  The walls are made "+
            "of black stones and there are lighted torches fixed to the "+
            "walls.  You see a lot of little footprints leading back to "+
            "the southwest.\n";

  items=({"cave","The cave leads back to the southwest",
          "stones","Big black stones compose the walls",
          "torches","They are lighted and fixed to the walls",
          "walls","The walls are dark and made of black stones",
          "footprints","You see a lot of tiny gnomish footprints",
          "volcano","You are just inside the volcano",
        });

  dest_dir=({"/players/emerald/island/room/g13","southwest",
           });

  clone_list=({
    1,1,"rnkzrz","obj/monster",({
      "set_name","rnkzrz",
      "set_gender",1,
      "set_level",12,
      "set_short","Rnkzrz the Gnome",
      "set_race","gnome",
      "set_hp",230,
      "add_money",random(400),
    }),
    2,1,"sidril","obj/monster",({
      "set_name","sidril",
      "set_gender",1,
      "set_level",25,
      "set_hp",435,
      "set_race","gnome",
      "set_short","Sidril the Gnome",
      "add_money",random(1000),
    }),
    3,1,"nadja","obj/monster",({
      "set_name","nadja",
      "set_gender",2,
      "set_level",16,
      "set_race","gnome",
      "set_hp",400,
      "set_short","Nadja the Gnome",
      "add_money",random(550),
    }),
    -1,1,"warbag","/players/emerald/island/obj/warbag",0,
    -1,1,"knife","/players/emerald/island/obj/knife",0,
    -2,1,"warbag","/players/emerald/island/obj/warbag",0,
    -2,1,"knife","/players/emerald/island/obj/knife",0,
    -3,1,"warbag","/players/emerald/island/obj/warbag",0,
    -3,1,"knife","/players/emerald/island/obj/knife",0,
  });

  ::reset(arg);
  replace_program("/room/room");

}
