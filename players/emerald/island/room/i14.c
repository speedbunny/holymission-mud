inherit "/room/room";

void reset(int arg) {
  if (arg) return;

  set_light(1);
  short_desc="On an island";
  long_desc="A small path leads up and down the side of the volcano.  The "+
            "air is thick with flying ash, making it difficult to see the "+
            "path.  To the east and south is a long drop down to the "+
            "crashing waves of the sea.\n";

  items=({"path","It leads further up and down the volcano",
          "air","It reeks of volcanic gasses and is full of ash",
          "ash","Flying ash particles threaten to choke you",
          "waves","Their foamy tips break on the rocks of the island",
          "sea","The clear blue sea",
        });

  dest_dir=({"/players/emerald/island/room/i13", "down",
             "/players/emerald/island/room/i19", "up",
           });

  clone_list=({
    1,1,"dragon","/players/emerald/island/obj/red",0,
    -1,1,"skin","obj/armour",({
      "set_name","dragonskin",
      "set_alias","skin",
      "set_type","armour",
      "set_ac",4,
      "set_short","A red dragonskin",
      "set_long","The excellent armour of the red volcano Dragon.\n",
      "set_value",3000,
      "set_weight",3,
    }),
  });

  ::reset(arg);
  replace_program("/room/room");

}
