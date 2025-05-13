inherit "/room/room";

void reset (int arg) {

  if(arg) return;
  set_light(1);

  short_desc="The bakery";

  long_desc="It's a feast for the nose as well as the eyes and stomach " +
            "here.  Loaves and rounds of beautifully browned bread and " +
            "rolls are heaped to overflowing in bins.  The baker is busy " +
            "kneading up some dough for the next batch.  He looks rather " +
            "dusty from all the flour.\n";

  dest_dir=({"/players/emerald/town/t11","south",
           });

  items=({"bins","Wooden bins containing the fruits of the baker's labour",
          "loaves","The appropriate form for bread",
          "bread","A starchy food made of flour, water, and yeast",
          "rounds","An appropriate shape for bread",
          "dough","The unbaked version of bread",
          "rolls","They make your mouth water",
  });
  clone_list=({
    1,1,"baker","obj/monster", ({
      "set_name","baker",
      "set_short","A stout baker",
      "set_long","A friendly baker who bakes wonderful goodies.\n",
      "set_level",30,
      "set_gender",1,
      "set_race","human",
      "set_ac",15,
      "set_wc",13,
      "add_money",800,
    }),
    -1,1,"pin","obj/weapon", ({
      "set_name","rolling pin",
      "set_short","A rolling pin",
      "set_wc",2,
      "set_value",150,
      "set_alias","pin",
      "set_weight",2,
      "set_long","A heavy marble rolling pin",
    }),
    -1,1,"bread","obj/food", ({
      "set_name","bread",
      "set_short", "Fresh bread",
      "set_long","Crusty, warm, fresh bread.\n",
      "set_value",20,
      "set_weight",1,
      "set_strength",5,
      "set_eating_mess", "Your stomach is very pleased.\n",
    }),
  });
  ::reset(arg);
   replace_program("/room/room");

}
