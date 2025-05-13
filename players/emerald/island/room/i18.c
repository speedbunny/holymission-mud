inherit "/room/room";
void reset(int arg) {
  if (arg) return;

  set_light(1);
  short_desc="On an island";

  long_desc="You have reached the top of the volcano.  Below you is the "+
            "glowing-red lava chamber, where the Dragonlord likes to take "+
            "his lava baths.  There is also a big nest perched on the "+
            "side of the chamber.\n";


  items=({"top","The very top of the volcano",
          "volcano","You are standing on top of an active volcano",
          "chamber","The lava chamber of the volcano",
          "nest","It's HUGE",
          "side","A big nest is on one side of the chamber",
        });

  dest_dir=({"/players/emerald/island/room/i19", "down",
           });

  clone_list=({
    1,1,"dragon","/players/emerald/island/obj/baby",0,
    -1,1,"skin","obj/armour",({
      "set_name","dragonskin",
      "set_alias","skin",
      "set_type","armour",
      "set_ac",3,
      "set_size",2,
      "set_short","A baby dragonskin",
      "set_long","The armour of the cute baby Dragon.\n",
      "set_value",400,
      "set_weight",1,
    }),
  });

  ::reset(arg);
  replace_program("/room/room");
}
