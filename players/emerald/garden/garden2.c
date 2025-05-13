inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="Royal garden";
  long_desc="You are on a wonderful green on which some trees are " +
            "growing.  But what kind of tree are these?  You have never " +
            "seen these kinds of trees before.  To the west and south is " +
            "a wall, so the only way out is to the north or east.\n";

  items=({"trees", "Strange trees.  You have no idea what they are, " +
                   "but they are very pretty",
          "green","A swath of green grass in the garden",
          "wall","A high wall which borders the green",          
        });

  dest_dir=({"/players/emerald/garden/garden1", "north",
             "/players/emerald/garden/garden3", "east",
           });

  clone_list=({
    1,2,"squirrel","obj/monster", ({
      "set_name","squirrel",
      "set_short","A black and red squirrel",
      "set_long","The squirrel is accumulating nuts for the hard winter.\n",
      "set_race","mammal",
      "set_level",1,
      "set_al",-50,
      "set_wc",2,
      "set_ac",2,
    }),
    -1,1,"nut","obj/food", ({
      "set_name","hazelnut",
      "set_alias","nut",
      "set_short","A hazelnut",
      "set_long","This is a fresh and good looking hazelnut.\n",
      "set_value",50,
      "set_weight",1,
      "set_strength",5,
      "set_eater_mess","CRACK ... Hmmm ... You feel better now.\n",
      "set_eating_mess"," audibly eats a nut. CRACK !? Gnam ...\n",  
    }),
  });

  ::reset();
  replace_program("/room/room");

}
