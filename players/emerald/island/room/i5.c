inherit "/room/room";

void reset(int arg) {

 if (arg) return;

 set_light(1);
 short_desc="On an island";

 long_desc="You are climbing the side of the volcano.  The air is filled "+
           "with flying ash particles and the volcano continues its "+
           "eternal rumbling.  A few palm trees bravely grow to the east.\n";

 items=({"volcano","An active volcano, and you are climbing it",
         "side","You are on the side of a volcano",
         "air","It is contaminated by volcanic ash",
         "particles","Bit of volcanic ash",
         "trees","They are quite tall",
       });

  dest_dir=({"/players/emerald/island/room/i11", "north",
             "/players/emerald/island/room/i6", "down",
           });

  clone_list=({
    1,1,"dragon","/players/emerald/island/obj/blue",0,
    -1,1,"skin","obj/armour",({
      "set_name","dragonskin",
      "set_alias","skin",
      "set_type","armour",
      "set_ac",4,
      "set_short","A blue dragonskin",
      "set_long","The excellent armour of the blue volcano Dragon.\n",
      "set_value",2000,
      "set_weight",2,
    }),
  });

  ::reset(arg);
  replace_program("/room/room");

}
