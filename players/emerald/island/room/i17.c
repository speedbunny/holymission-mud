inherit "/room/room";

void reset(int arg) {
  if (arg) return;

  set_light(1);
  short_desc="On an island";

  long_desc="You are standing on a plateau near the top of the volcano.  "+
            "The air is so full of ash particles that you can hardle see "+
            "anything.  A small dark cavern is to the north, while the "+
            "plateau continues further to the south.  The plateau is "+
            "bounded by rocks to the east and high bushes to the west.\n";

  items=({"plateau","A plateau high up on the side of the volcano",
          "top","You are almost at the top of the volcano",
          "volcano","You are on a volcanic island",
          "air","It is choked with ash",
          "particles","Tiny particles of volcanic ash fill the air",
          "cavern","A delicious aroma wafts out of the cavern",
          "rocks","Mounds of ancient basalt from old lava flows",
          "bushes","They are thick and thorny",
        });

  dest_dir=({"/players/emerald/island/room/i21", "up",
             "/players/emerald/island/room/i12", "south",
             "/players/emerald/island/room/i16", "down",
             "/players/emerald/island/room/bar","north",
           });

  clone_list=({
    1,1,"dragon","/players/emerald/island/obj/blue",0,
     -1,1,"skin","obj/armour",({
      "set_name","dragonskin",
      "set_alias","skin",
      "set_type","armour",
      "set_ac",4,
      "set_size",3,
      "set_short","A blue dragonskin",
      "set_long","The excellent armour of the blue volcano Dragon.\n",
      "set_value",2000,
      "set_weight",2,
    }),
    2,1,"mushroom","obj/food",({
      "set_name","mushroom",
      "set_short","A big mushroom",
      "set_long","A delicious looking brown mushroom.\n",
      "set_eater_mess","MMMMMMMmmmmmm.\n",
      "set_eating_mess"," eats a brown mushroom.\n",
      "set_strength",8,
      "set_value",20,
      "set_weight",1,
    }),
  });

  ::reset(arg);
  replace_program("/room/room");

}
