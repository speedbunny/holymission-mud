inherit "/room/room";

void reset(int arg) {
  if (arg) return;

  set_light(1);
  short_desc="On an island";

  long_desc="You are very near the top of the volcano.  The air is thick "+
            "with flying ash particles.  A foul taste lingers in your "+
            "mouth from the polluted air.  A small path to the east and "+
            "south leads further up and down the volcano.  Far below you "+
            "to the north and west are the crashing waves of the sea.\n";

  items=({"top","The top of the volcano is not terribly far above you",
          "volcano","A rumbling and grumbling active volcano",
          "air","It is polluted with ash and foul gasses",
          "particles","Flying ash particles spewing from the volcano",
          "mouth","You eat with it.  It contains a tongue and some teeth",
          "path","It leads up and down the volcano",
          "waves","They are rather far below you",
          "sea","The crystal blue sea",
        });

  dest_dir=({"/players/emerald/island/room/i22", "up",
             "/players/emerald/island/room/i17", "down",
           });

  clone_list=({
    1,1,"red","/players/emerald/island/obj/red",0,
    -1,1,"dragonskin","obj/armour",({
      "set_name","dragonskin",
      "set_alias","skin",
      "set_type","armour",
      "set_ac",4,
      "set_short","A red dragonskin",
      "set_long","The excellent armour of the red volcano Dragon.\n",
      "set_value",3000,
      "set_weight",3,
    }),
    2,1,"green","/players/emerald/island/obj/green",0,
    -2,1,"skin","/obj/armour",({
      "set_name","dragonskin",
      "set_alias","skin",
      "set_type","armour",
      "set_ac",4,
      "set_short","A green dragonskin",
      "set_long","The excellent armour of the green volcano Dragon.\n",
      "set_value",1000,
      "set_weight",2,
    }),
  });

  ::reset(arg);
  replace_program("/room/room");

}
