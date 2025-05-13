inherit "room/room";
reset(arg) {
  if(!arg) {::reset(arg);

    short_desc = "north coast";
     long_desc = "This is the north coast. To the west you see the end of this coast.\n" +
                 "You hear the wind blowing and you enjoy the gentle breeze blowing into\n" +       
                 "your face.\n";

     items = ({"coast","The north coast",
               "ocean","The blue ocean is very silent" });
    dest_dir = ({"players/muzmuz/island/rooms/da","west",
                 "players/muzmuz/island/rooms/eb","south",
                 "players/muzmuz/island/rooms/fa","east",
                    });
set_light (1);
return 1; }}
