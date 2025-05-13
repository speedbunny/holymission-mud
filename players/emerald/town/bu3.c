inherit "/room/room";

void reset (int arg) {

  if(arg) return;
  set_light(1);

  short_desc="A rowdy brothel";

  long_desc="You are in a bedroom in the brothel.  The bed looks rather " +
            "comfortable, and you suspect it of having seen much use.  The " +
            "bed also seems to have a ready and waiting occupant.\n";

  dest_dir=({"/players/emerald/town/bu1","west",
           });

  items=({"bed","If only the bed could talk..",
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
  });
  ::reset(arg);
   replace_program("/room/room");

}
