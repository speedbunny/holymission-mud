inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A side street";

  long_desc="This is quiet side street away from the hustle and bustle of " +
            "the market.  There doesn't appear to be very much activity " +
            "here.  There is a business of some kind to the north of you, " +
            "and a nosy policeman looking over your shoulder.\n";

  dest_dir=({"/players/emerald/town/wwright","north",
             "/players/emerald/town/t3","east",
             "/players/emerald/town/t1","west",
           });

  items=({"street","A small street in the town",
          "business","Most likely the shop of a local craftsman",
  });

  clone_list=({
    1,1,"policeman","obj/monster", ({
      "set_name","policeman",
      "set_race","human",
      "set_alias","police",
      "set_short","A nosy policeman",
      "set_long","This guy is out looking for trouble, his own, mainly.\n",
      "set_level",35,
      "set_wc",15,
      "set_gender",1,
    }),
  });
  ::reset(arg);
   replace_program("/room/room");

}
