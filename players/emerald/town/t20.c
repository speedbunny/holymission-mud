inherit "/room/room";

void reset (int arg) {

  if(arg) return;
  set_light(1);

  short_desc="A side street";

  long_desc="This section of the street shows a little more traffic.  A " +
            "steady stream of people are passing in and out of the building " +
            "to the west.  The smell of good cooking is coming from the " +
            "northern side of the street.  There is a sign hanging out in " +
            "front of that building.\n";

  dest_dir=({"/players/emerald/town/inn","north",
             "/players/emerald/town/house3","south",
             "/players/emerald/town/t19","east",
             "/players/emerald/town/shop","west",
           });

  items=({"sign","A silver fox is painted on the sign",
          "street","A small side street",
          "people","Human beings, mostly",
          "building","A small, but busy shop",
        });
  ::reset(arg);
   replace_program("/room/room");

}
