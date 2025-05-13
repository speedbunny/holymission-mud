inherit "/room/room";

void reset(int arg) {
  if(arg)return;

  set_light(1);
  short_desc="On an island";

  long_desc="You are standing on a plateau near the top of the volcano.  "+
            "The air is very hot and the gas emitted by the volcano nearly "+
            "causes you to fall unconscious.  The plateau drops off to "+
            "the north and east, leaving nothing but air between you and "+
            "the deep blue sea.\n";

  items=({"plateau","You are on a plateau almost at the top of the volcano",
          "top","The top of the volcano is not far away",
          "volcano","Yes, you are on a volcano.  It's quite active, too",
          "air","It is thick with ash particles",
          "gas","A foul gas emitted by the volcano"
          "sea","The sea is rather far below you.  Jumping could be "+
                "hazardous to your health",
        });

  dest_dir=({"/players/emerald/island/room/i22", "west",
             "/players/emerald/island/room/i19", "south",
           });

  clone_list=({
    1,1,"dragon","/players/emerald/island/obj/green",0,
    -1,1,"skin","obj/armour",({
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
