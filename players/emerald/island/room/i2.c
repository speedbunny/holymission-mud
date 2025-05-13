inherit "/room/room";

void reset(int arg){
  if (arg) return;

  set_light(1);
  short_desc="On an island";
  long_desc="You are standing on a sandy beach.  The sun shines overhead "+
            "and you feel like staying here for a while.  A few palm trees "+
            "grow to the north.  A big black rock blocks the beach to the "+
            "west.  The omnipresent rumbling of the volcano disturbs the "+
            "serenity of this place.\n";

  items=({"rock","A big black rock",
          "trees","Small palm trees growing at the back of the beach",
          "beach","The sand is soft and white",
          "sun","Looking directly at the sun will ruin your vision",
          "volcano","You are on a volcanic island",
          "place","A nice, tranquil beach",
        });

  dest_dir=({"/players/emerald/island/room/i1", "southeast",
             "/players/emerald/island/room/i6", "north",
             "/players/emerald/island/room/i3", "east",
           });

  clone_list=({
    1,1,"beer","obj/alco_drink",({
      "set_name","beer",
      "set_short","A bottle of beer",
      "set_long","A bottle of beer.\n",
      "set_drinking_mess"," quaffs a bottle of beer.\n",
      "set_drinker_mess","It's a little sandy.\n",
      "set_weight",1,
      "set_value",10,
      "set_strength",2,
      "set_empty_container","bottle",
    }),
  });

  ::reset(arg);
  replace_program("/room/room");

}
