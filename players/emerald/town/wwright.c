inherit "/room/room";

void reset (int arg) {

  if(arg) return;
  set_light(1);

  short_desc="A side street";

  long_desc="Achoo!  You sneeze from all the sawdust in the air.  Golden " +
            "beams of sunlight shining through the window illuminate the " +
            "sawdust into a golden fog.  There is a woodwright happily " +
            "hammering away on a table.  Curls of wood shavings litter the " +
            "floor, and the sawdust coats everything.\n";

  dest_dir=({"/players/emerald/town/t2","south",
           });

  items=({"shavings","Wood shavings from planing something into smoothness",
          "wood","Small curls of shaved wood",
           "sawdust","Lots and lots of sawdust",
           "table","A beautiful oaken table with finely turned legs",
  });

  clone_list=({
    1,1,"woodwright","obj/monster", ({
      "set_name","woodwright",
      "set_alias","wright",
      "set_race","human",
      "set_short","A happy woodwright",
      "set_long","This is a master craftsman when it comes to woodworking.\n",
      "set_level",25,
      "set_wc",15,
      "set_ac",15,
      "set_gender",1,
      "add_money",500,
    }),
    -1,1,"hammer","obj/weapon", ({
      "set_name","hammer",
      "set_short","A hammer",
      "set_wc",2,
      "set_weight",2,
      "set_value",60,
    }),
  });
  ::reset(arg);
   replace_program("/room/room");

}
