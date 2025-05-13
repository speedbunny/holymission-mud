inherit "room/room";
reset (arg) {
  if (!arg) {::reset(arg);

       short_desc = "path";
        long_desc = "On the path. It leads further to the east and to the west. The hills north\n" +
                    "and south cannot be climbed from here.\n";

         dest_dir = ({"players/muzmuz/island/rooms/gi","west",
                      "players/muzmuz/island/rooms/ii","east",
                                  });

          items = ({"path","A stony path",
                    "hills","Little hills, but too steep to climb up",
                        });
set_light (1);
return 1; }}
