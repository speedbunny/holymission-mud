inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A side street";

  long_desc="You have reached the end of the street.  There are a few trees " +
            "shading the houses with their dark green leaves.  It is much " +
            "more peaceful and tranquil here than in front of the " +
            "alchemist's shop.  It seems to be a nice place to sit and rest " +
            "for a while.\n";

  dest_dir=({"/players/emerald/town/t8","west",
           });

  items=({"trees","Old oaks.  Their branches are too high for climbing",
          "street","A small side street",
          "leaves","Large green oak leaves",
          "houses","Normal houses inhabited by normal people",
  });

  ::reset(arg);
   replace_program("/room/room");

}
