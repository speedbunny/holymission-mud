inherit "/room/room";

void reset (int arg) {

  if(arg) return;
  set_light(1);

  short_desc="A rowdy brothel";

  long_desc="The hallway has ceased to be quiet.  Trouble in the form of " +
            "females has appeared on the horizon.  There doesn't appear to " +
            "be any place to hide, unless you duck into the next bedroom, " +
            "which might not be such a wise idea considering the type of " +
            "establishment.\n";

  dest_dir=({"/players/emerald/town/bu5","north",
             "/players/emerald/town/bu2","west",
           });

  items=({"bedroom","Do you REALLY want to go in there?",
        });

  clone_list=({
    1,2,"prostitute","obj/monster", ({
      "set_name","prostitute",
      "set_race","human",
      "set_long","A sleazy prostitute.  You'd better not double-cross her!\n",
      "set_level",30,
      "set_wc",18,
      "add_money",1400,
      "set_gender",2,
    }),
  });
  ::reset(arg);
   replace_program("/room/room");

}
