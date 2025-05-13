inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="In a cavern";

  long_desc="You are in a big cave inside the volcano.  The walls are made "+
            "of black stones and there are lighted torches fixed to the "+
            "walls.  Heavy stones are lying on the ground and there is a "+
            "small path leading further east and west.  You can hear "+
            "some voices coming from the east.\n";

  items=({"cave","The cave leads further to the east and west",
          "stones","Big black stones lying on the ground",
          "torches","They are lighted and fixed to the walls",
          "walls","The walls are dark and made of black stones",
          "ground","The ground is full of dark stones",
          "path","The path is dark and leads further to the east and west",
          "volcano","You are inside the volcano",
        });

  dest_dir=({"/players/emerald/island/room/g5","west",
             "/players/emerald/island/room/g7","east"
           });

  clone_list=({
    1,1,"rnzzrik","obj/monster",({
      "set_name","rnzrrik",
      "set_gender",1,
      "set_level",35,
      "set_hp",495,
      "set_short","Rnzrrik the Gnome",
      "set_race","gnome",
      "add_money",random(2000),
    }),
    2,1,"hnzzwnzz","obj/monster",({
      "set_name","hnzzwnzz",
      "set_gender",1,
      "set_level",38,
      "set_hp",640,
      "set_race","gnome",
      "set_short","Hnzzwnzz the Gnome",
      "add_money",random(2900),
    }),
    -1,1,"warbag","/players/emerald/island/obj/warbag",0,
    -1,1,"knife","/players/emerald/island/obj/knife",0,
    -2,1,"warbag","/players/emerald/island/obj/warbag",0,
    -2,1,"knife","/players/emerald/island/obj/knife",0,
  });

  ::reset(arg);
  replace_program("/room/room");

}
