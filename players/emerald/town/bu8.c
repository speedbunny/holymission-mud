inherit "/room/room";

void reset (int arg) {

  if(arg) return;
  set_light(1);

  short_desc="A rowdy brothel";

  long_desc="You are in one of the many bedrooms in the brothel.  It seems " +
            "as if more than one of the girls use this room, judging by " +
            "the amount of clothing heaped up in the corners.  Since it " +
            "appears that there are two sets of everything, you guess that " +
            "they are identical twins.\n";

  dest_dir=({"/players/emerald/town/bu1","east",
           });

  items=({"clothing","Lots and lots of clothing, mainly frilly",
        });

  clone_list=({
    1,2,"prostitute","obj/monster", ({
      "set_name","prostitute",
      "set_race","human",
      "set_long","One of a set of identical twins.\n",
      "set_level",30,
      "set_wc",18,
      "add_money",1400,
      "set_gender",2,
    }),
  });
  ::reset(arg);
   replace_program("/room/room");

}
