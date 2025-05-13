inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="In the orc caves";

  long_desc="You are wandering through the orc caves.  A distinctive dark "+
            "red substance colours the walls, bones are scattered about "+
            "the floor, and a horrible reek fills the air.  A strange "+
            "noise comes from the west.  It sounds like someone snoring.\n";

  items=({"caves","The caves of the orcs",
          "substance","Dried blood",
          "walls","Stone walls nicely decorated with blood",
          "bones","The midly-gnawed on bones of former adventurers",
          "floor","The floor is covered with old bones",
          "air","It stinks here",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/ci6","south",
             "/players/emerald/island/room/caves/room/ci9","northeast",
             "/players/emerald/island/room/caves/room/ci8","west",
           });

  smell="The place reeks of rot and decay.";

  clone_list=({
    1,3,"shaman","/players/emerald/island/room/caves/obj/shaman",0,
    -1,1,"mace","/players/emerald/island/room/caves/obj/mace",0,
    -1,1,"robe","obj/armour",({
      "set_name","black robe",
      "set_alias","robe",
      "set_short","A black robe",
      "set_long","A long, black robe.\n",
      "set_weight",1,
      "set_ac",1,
      "set_type","cloak",
      "set_value",75,
    }),
  });

  ::reset(arg);
  replace_program("/room/room");

}
