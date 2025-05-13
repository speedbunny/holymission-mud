inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="In the secret orc chambers";

  long_desc="You are wandering through the secret orc caves.  The corridor "+
            "is dark and silent.  Far to the south, light streams into "+
            "the passage.  The wall to the west appears broken into some "+
            "sort of door.  Light appears in the cracks around the door.\n";

  items=({"caves","The secret orc caves",
          "corridor","The corridor is dark to the north",
          "light","There is light to the south and west",
          "passage","The southern passage has light farther down it",
          "wall","It contains a door",
          "door","A door in the western wall",
          "cracks","The door does not fit snugly",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/ci31","north",
             "/players/emerald/island/room/caves/room/ci30","west",
             "/players/emerald/island/room/caves/room/ci28","south",
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
