inherit "/room/room";

void reset(int arg) {

  if (arg) return;
  set_light(1);

  short_desc="On an island";

  long_desc="You are standing in the warm, shallow water of the sea.  The "+
            "volcanic island rises to a towering peak to the north of "+
            "here.  A huge cloud of volcanic ash hangs around the peak of "+
            "the island.  Strange rumbling noises emenate from the peak.\n";

  items=({"water","Blue sea water",
          "sea","A clear blue sea",
          "island","A big island, with palm trees, a volcano, and some "+
                   "dragons",
          "peak","It is obscured by a cloud of ash",
          "ash","A large cloud of volcanic ash",
        });

  dest_dir=({"/players/emerald/island/room/i4","northeast",
             "/players/emerald/island/room/i2","northwest",
             "/players/emerald/island/room/i3", "north",
           });

  clone_list=({
    1,1,"dragon","/players/emerald/island/obj/steel",0,
    2,1,"cancer","obj/monster",({
      "set_name","cancer",
      "set_level",2,
      "set_hp",60,
      "set_race","crustacean",
      "set_short","A big cancer",
      "set_long","You see a big cancer snapping at your legs.\n",
    }),
    -2,1,"claws","obj/weapon",({
      "set_name","claws",
      "set_class",4,
      "set_short","Cancer claws",
      "set_long","The claws of the cancer.\n",
      "set_value",25,
      "set_weight",1,
    }),
  });

  ::reset(arg);
  replace_program("/room/room");

}
