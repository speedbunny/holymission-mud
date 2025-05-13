inherit "/room/room";

void reset (int arg) {

  if(arg) return;
  set_light(1);

  short_desc="A rowdy brothel";

  long_desc="You have entered another bedroom in the brothel.  And it " +
            "appears to be in use at the moment.  Jumping out the window " +
            "would be a nice option, but they all seem to have iron bars " +
            "over them, probably to keep the men from escaping.\n";

  dest_dir=({"/players/emerald/town/bu7","south",
           });

  items=({"windows","They are covered with heavy iron bars",
          "window","It is protected with heavy iron bars",
          "bars","Nice, thick, iron bars",
        });

  clone_list=({
    1,1,"prostitute","obj/monster", ({
      "set_name","prostitute",
      "set_race","human",
      "set_long","A sleazy prostitute.  You'd better not double-cross her!\n",
      "set_level",30,
      "set_wc",18,
      "add_money",1400,
      "set_gender",2,
    }),
    2,1,"patron","obj/monster", ({
      "set_name","patron",
      "set_race","human",
      "set_long","A creepy lowlife looking for some action.\n",
      "set_level",40,
      "set_wc",20,
      "set_ac",15,
      "set_gender",1,
      "add_money",2000,
    }),
  });
  ::reset(arg);
   replace_program("/room/room");

}
