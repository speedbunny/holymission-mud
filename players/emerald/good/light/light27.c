inherit "/room/room";

void reset(int arg) {

  if (arg) return;

  set_light(1);

  long_desc="An extremely large gopher lives in this hole. He is probably " +
            "the biggest gopher around. He digs tunnels everywhere under " +
            "the earth. One day he will tunnel a veritable world here.\n";

  short_desc="The home of the gopher";

  dest_dir=({"players/emerald/good/light/light12","up",
           });

  items=({"hole","It is large enough to accomodate several gophers",
          "earth","You are in it",
          "tunnels","The home of the gopher",
        });

  clone_list=({
    1,1,"gopher","obj/monster", ({
      "set_name", "large gopher",
      "set_alias", "gopher",
      "set_race", "rodent",
      "set_level", 15,
      "set_al", 500,
      "set_short", "A large gopher",
      "set_long", "The gopher is the biggest you have ever seen.\n",
      "set_ac", 7,
      "set_wc", 15,
    }),
    -1,1,"skin","obj/armour", ({
      "set_name", "skin",
      "set_alt_name","gopher skin",
      "set_short", "The skin of a large gopher",
      "set_long","This skin is worn as a cloak.\n",
      "set_ac", 1,
      "set_type", "cloak",
      "set_value", 500,
      "set_weight", 3,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
