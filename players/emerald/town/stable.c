inherit "/room/room";

void reset (int arg) {

  if(arg) return;
  set_light(1);

  short_desc="The stable";

  long_desc="This is the town stable.  Most of the stalls are empty right " +
             "now, but the smell of horses still lingers in the air.  " +
             "Piles of hay for fodder and straw for bedding are stacked " +
             "neatly along one wall.  Sacks of oats sit near the door, and " +
             "there is a large water trough in the middle of the building.\n";
  dest_dir=({"/players/emerald/town/t19","south",
           });


  items=({"hay","Fresh hay that smells wonderful",
          "oats","Food for the horses",
          "trough","Where the animals go to drink",
          "sacks","Bags holding the oats",
          "piles","Piles of hay and straw",
          "stalls","Individual compartments for keeping the horses",
          "straw","The bedding for the animals",
        });
  clone_list=({
    1,1,"groom","obj/monster", ({
      "set_name","groom",
      "set_level",24,
      "set_wc",13,
      "set_ac",13,
      "add_money",400,
      "set_race","human",
      "set_short","A tired groom",
      "set_gender",1,
    }),
    2,2,"horse","obj/monster", ({
      "set_name","horse",
      "set_short","A horse",
      "set_level",28,
      "set_wc",15,
    }),
  });
  ::reset(arg);
   replace_program("/room/room");

}
