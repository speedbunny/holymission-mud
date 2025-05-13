inherit "/room/room";

void reset (int arg) {

  if(arg) return;
  set_light(1);

  short_desc="A rowdy brothel";

  long_desc="Whoops!  You have to duck to avoid the undergarments flying " +
            "through the air.  This place appears to be a rather lively " +
            "brothel.  Seductively clad women are lounging about on " +
            "divans, while slant-eyed men with money clenched in their " +
            "fists are lining up for their services.  A stairway in the " +
            "corner leads to the upper floors of this house of pleasure " +
            "and corruption.\n";

  dest_dir=({"/players/emerald/town/t17","west",
             "/players/emerald/town/bu1","up",
           });

  items=({"divan","A velvet-covered lounge",
         "divans","Velvet-covered lounges",
          "stairway","It winds majestically up to the second floor",
        });

  clone_list=({
    1,4,"prostitute","obj/monster", ({
      "set_name","prostitute",
      "set_race","human",
      "set_long","A sleazy prostitute.  You'd better not double-cross her!\n",
      "set_level",30,
      "set_wc",18,
      "add_money",1400,
      "set_gender",2,
    }),
    2,7,"patron","obj/monster", ({
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
