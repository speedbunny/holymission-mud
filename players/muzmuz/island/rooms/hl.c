inherit "room/room";
reset (arg) {
  if (!arg) {::reset(arg);

       short_desc = "swamps";
        long_desc = "This is the northeastern corner of the swamps. You are near the coast.\n" +
                    "There are steep hills to the north.\n";

         dest_dir =({"players/muzmuz/island/rooms/gl","west",
                     "players/muzmuz/island/rooms/il","east",
                     "players/muzmuz/island/rooms/hm","south",
                            });

          items = ({"hills","Steep hills to the north",
                    "swamps","Huge moist swamps",
                    "coast","Too far away to see it",
                               });
set_light (1);
return 1; }}
