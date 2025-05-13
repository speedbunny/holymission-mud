inherit "/room/room";

void reset (int arg) {

  if(arg) return;
  set_light(1);

  short_desc="The butcher shop";

  long_desc="This is the butcher shop for the town.  Sides of meat are " 
            "hanging from hooks in the ceiling.  The butcher himself is " +
            "standing behind a thick wooden table, his apron and hands " +
            "smeared with blood and guts.  A few satisfied customers are " +
            "leaving with wrapped packages of fresh meat.\n";

  dest_dir=({"/players/emerald/town/t10","south",
           });

  items=({"meat","Sides of meat waiting to be carved",
          "table","A really massive wooden table.  The top is rather worn",
  });
  clone_list=({
    1,1,"butcher","obj/monster", ({
      "set_name","butcher",
      "set_short","The town butcher",
      "set_long","He has a big smile on his face and waits for your order.\n",
      "set_level",40,
      "set_wc",18,
      "set_ac",13,
      "add_money",1000,
      "set_gender",1,
      "set_race","human",
      "set_alias", "butcher",
    }),
    -1,1,"knife","obj/weapon", ({
      "set_name","knife",
      "set_short","A butcher knife",
      "set_wc",5,
      "set_value",50,
      "set_weight",1,
    }),
    -1,1,"steak","obj/food", ({
      "set_name","steak",
      "set_short","A juicy steak",
      "set_value",45,
      "set_weight",1,
      "set_strength",10,
    }),
    -1,1,"apron","obj/armour", ({
      "set_name","apron",
      "set_short","A bloody apron",
      "set_long","The working garb of the butcher\n",
      "set_ac",1,
      "set_value",40,
      "set_weight",1,
    }),
  });
  ::reset(arg);
   replace_program("/room/room");

}
