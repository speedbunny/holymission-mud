inherit "room/room";
reset (arg) {
  if (!arg) {::reset(arg);

     short_desc = "swamps";
      long_desc = "At eastern edge of the swamps. You are near the coast and it is less hot\n" +
                  "than inside. It is still very moist here.\n";

     dest_dir = ({"players/muzmuz/island/rooms/hl","north",
                  "players/muzmuz/island/rooms/hn","south",
                  "players/muzmuz/island/rooms/gm","west",
                  "players/muzmuz/island/rooms/im","east",
                          });

       items =({"swamps","Huge moist swamps",
                "coast","Too far away to see it",
                         });
set_light (1);
return 1; }}
