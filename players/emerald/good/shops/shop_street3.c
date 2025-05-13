inherit "/room/room";

void reset(int arg) {

  if (arg) return;

  set_light(1);

  short_desc="Village street";
  long_desc="This is the one and only intersection in the village.  A " +
            "side street branches off the main village street to the " +
            "west.  There appears to be a shop to the north.  A strange " +
            "and unusual plant is setting in the window.\n";

  items=({"shop","This is the little shop of Animal's horrors",
          "plant","It appears to be grinning at you in a rather " +
                  "disconcerting manner",
          "street","You are standing in it.  Didn't your mother tell " +
                   "you not to stand in the middle of the street?!?",
          "village","A quaint little mountain village",
          "intersection","The village has a total of TWO streets!",
          "window","A really weird plant is setting in it",
        });
  dest_dir=({"/players/emerald/good/shops/shop_street4","west",
             "/players/emerald/good/shops/shop_street2", "south",
             "/players/emerald/good/shops/shop","north",
           });

  ::reset();
  replace_program("/room/room");

}
