inherit "room/room";

void reset(int arg) {

  if (arg) return;

  set_light(1);

  short_desc="Village street";
  long_desc="You have reached the end of the street.  Several shops are " +
            "ready to steal, er, take your money for services they " +
            "provide. Off to the north lies the brewery and further to the " +
            "east are more shops.\n";

  items=({"street","A street in the village",
          "shops","Well, there's only one on this section.  It appears " +
                  "to be a brewery",
          "brewery","Buy a keg",
        });
  dest_dir=({"/players/emerald/good/shops/brew","north",
             "/players/emerald/good/shops/shop_street3","east",
           });

  ::reset();
  replace_program("/room/room");

}
