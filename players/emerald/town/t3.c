inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A side street";

  long_desc="It seems as if everyone is out today.  The houses on either " +
            "side of the street appear to be deserted.  Instead of hearing " +
            "children laughing and dogs barking, only silence greets your " +
            "ears.  Well, not total silence.  You can hear the tapping of " +
            "boots on the paving cobbles, a rhythm that can only come from " +
            "the steady saunter of a policeman.\n";

  dest_dir=({"/players/emerald/town/t4","east",
             "/players/emerald/town/t2","west",
           });

  items=({"cobbles","Old paving cobbles, somewhat worn with age",
          "houses","Well-kept, if silent, houses",
  });

  clone_list=({
    1,2,"policeman","obj/monster", ({
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
