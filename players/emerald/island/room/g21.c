inherit "/room/room";
void reset(int arg) {

  if(arg) return;

  set_light(1);
  short_desc="In a cavern";
  long_desc="You are in a big cave inside the volcano.  The walls are "+
            "made of black stones and there are lighted torches fixed to "+
            "the walls.  You see a lot of little footprints leading "+
            "northeast and south.\n";

  items=({"cave","The cave leads further to the northeast and south",
          "stones","Big black stones compose the walls",
          "torches","They are lighted and fixed to the walls",
          "walls","The walls are dark and made of black stones",
          "footprints","You see a lot of tiny gnomish footprints",
          "volcano","You are inside the volcano",
        });

  dest_dir=({"/players/emerald/island/room/g25","northeast",
             "/players/emerald/island/room/g16","south",
            });

  clone_list=({
    1,1,"xentran","obj/monster",({
      "set_name","xentran",
      "set_gender",1,
      "set_level",12,
      "set_hp",230,
      "set_race","gnome",
      "set_short","Xentran the Gnome",
      "add_money",random(400),
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
    -1,1,"warbag","/players/emerald/island/obj/warbag",0,
    -1,1,"knife","/players/emerald/island/obj/knife",0,
    -2,1,"warbag","/players/emerald/island/obj/warbag",0,
    -2,1,"knife","/players/emerald/island/obj/knife",0,
  });

  ::reset(arg);
  replace_program("/room/room");

}
