inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A side street";

  long_desc="The street hasn't become any more lively as you progress down " +
            "the cobbled pavement.  Everything is very quiet.  And would " +
            "you believe it?  There are even more policemen here than " +
            "before!\n";

  dest_dir=({"/players/emerald/town/police","east",
             "/players/emerald/town/t3","west",
           });

  items=({"pavement","It is made of worn cobbles",
          "street","A small side street",
  });

  clone_list=({
    1,4,"policeman","obj/monster", ({
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
