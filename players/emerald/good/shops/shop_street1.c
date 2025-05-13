inherit "/room/room";

void reset(int arg) {

  if (arg) return;

  set_light(1);

  short_desc="Village street";
  long_desc="This is a small little mountain village nestled in the heart " +
            "of the Bridger mountain range.  The mountains are huge and " +
            "breathtaking.  Off to the east lies the village pub.\n";

  items=({"mountains","The mountians are beautiful",
          "village","It's tiny, but seems rather lively",
          "range","A range of snow and ice covered mountains",
          "pub","This is an old style pub, complete with a dragon on the sign",
        });

  dest_dir=({"/players/emerald/good/shops/shop_street2", "north",
             "/players/emerald/good/light/light14", "south",
             "/players/emerald/good/shops/pub","east",
           });

  ::reset();
  replace_program("/room/room");

}
