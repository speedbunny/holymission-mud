inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="In the secret orc chambers";

  long_desc="You are sneaking through the secret orc caves.  The corridor "+
            "leads into darkness to the north, while to the south, light "+
            "enters the passage.  It is completely, deathly silent here.\n";

  items=({"caves","The secret orc caves",
          "corridor","It is dark to the north",
          "light","Illumination",
          "passage","The southern passage is lit",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/ci29","north",
             "/players/emerald/island/room/caves/room/ci26","south",
           });

  clone_list=({
    1,1,"shaman","/players/emerald/island/room/caves/obj/shaman",0,
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
