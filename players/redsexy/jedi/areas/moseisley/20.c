inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);
  short_desc="Ambrose's Creamery.";
  long_desc="You have entered a stone hut, which smells badly of cows and manure! "+
            "Wooden racks line the length of this room, and there are a number of "+
            "wooden stools nailed to the ground where people can sit and milk the "+
            "animals that normally dwell here\n\n";

  dest_dir=({"/players/redsexy/jedi/areas/moseisley/21","north",
           });
  
  items=({"racks","These racks look as if they are here to keep the cows in place",
          "stools","Three legged stools, nailed to the ground where people can sit and milk cows.",
          "animals","The animals that normally dwell in here are cows",
         });

  clone_list=({
    1,1,"farmer","obj/monster", ({
      "set_name","farmer",
      "set_long","A sand farmer from Mos Eisley, proabably here to do some trade.\n",
      "set_race","human",
      "set_level",20,
      "set_gender",1,
      "add_money",1000,
      "set_wc",15,
      "set_ac",12,
    }),
    -1,1,"rake","obj/weapon", ({
      "set_name","rake",
      "set_short","The rake of a desert farmer, it looks as if it could be used as a weapon",
      "set_wc",3,
      "set_value",500,
      "set_weight",1,
    }),
    2,2,"cow","obj/monster", ({
      "set_name","cow",
      "set_race", "cow",
      "set_long","The cow looks up at you with dreamy brown eyes.\n",
      "set_level",10,
      "set_ac",5,
      "set_wc",7,
      "set_gender",2,
    }),
    3,1,"ambrose","obj/monster", ({
      "set_name","ambrose",
      "set_race", "human",
      "set_long","Ambrose wears a flowing milk-maid dress and has bunched up black hair.\n",
      "set_level",15,
      "set_ac",10,
      "set_wc",14,
      "set_gender",2,
    }),
 });

  ::reset();
   replace_program("/room/room");

}


