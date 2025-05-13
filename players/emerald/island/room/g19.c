inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc="In a cavern";

  long_desc="You are in a big cave inside the volcano.  The walls are made "+
            "of black stones and there are lighted torches fixed to the "+
            "walls.  You see a lot of little footprints leading north and "+
            "south.  The air is extremely hot here.  To the east you can "+
            "see a steaming lake.\n";

  items=({"cave","The cave leads further to the north and south",
          "stones","Big black stones compose the walls",
          "torches","They are lighted and fixed to the walls",
          "walls","The walls are dark and made of black stones",
          "path","The path leads further to the north and south",
          "footpribts","You see a lot of tiny gnomish footprints, "+
                       "leading northand south",
          "volcano","You are just inside of it",
          "lake","You see a dark lake with hot steam coming from it"
        });

  dest_dir=({"/players/emerald/island/room/g24","north",
             "/players/emerald/island/room/g15","south",
           });

  clone_list=({
    1,1,"nadja","obj/monster",({
      "set_name","nadja",
      "set_gender",2,
      "set_level",16,
      "set_hp",315,
      "set_race","gnome",
      "set_short","Nadja the Gnome",
      "add_money",random(550),
    }),
    2,1,"zrandrilla","obj/monster",({
      "set_name","zrandrilla",
      "set_gender",2,
      "set_level",14,
      "set_hp",270,
      "set_race","gnome",
      "set_short","Zrandrilla the Gnome",
      "add_money",random(475),
    }),
    3,1,"xeril","obj/monster",({
      "set_name","xeril",
      "set_gender",1,
      "set_level",40,
      "set_hp",660,
      "set_race","gnome",
      "set_short","Xeril the Gnome",
      "add_money",random(2500),
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
