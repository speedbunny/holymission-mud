inherit "/room/room";

void reset (int arg) {

  if(arg) return;
  set_light(1);

  short_desc="A rowdy brothel";

  long_desc="The upstairs is even more rowdy than the downstairs of this " +
            "place.  And this is just the hallway!  What appears to be a " +
            "pile of pillows in the corner has a few legs sticking out of " +
            "it, and you never knew that pillows could giggle.  But even " +
            "if those two are occupied, there's probably still someone " +
            "around to entertain you if you wish.\n";

  dest_dir=({"/players/emerald/town/bu3","east",
             "/players/emerald/town/bu2","north",
             "/players/emerald/town/bu8","west",
             "/players/emerald/town/brothel","down",
           });

  items=({"pillows","They are suspiciously moving around more than " +
                    "you'd think pillows would be able to",
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
