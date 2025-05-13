inherit "room/room";
reset(arg) {
  if(!arg) {

     short_desc = "A small tunnel";
     long_desc = "The music from the room to the east spills out into this\n" +
                 "room.  It's eerie sound digs deep into your soul, making\n" +
                 "you want to dance and puke at the same time.  A brightly\n" +
                 "lit hall opens up to the south.\n";

      dest_dir = ({"players/topaz/rooms/demons/cave10","south",
                   "players/topaz/rooms/demons/cave5","west",
                   "players/topaz/rooms/demons/cave8","east",
 
                     });

     items =({"tunnel","This tunnel is almost comforting",
              "hall","You feel drawn to it, it is so nice",
              });
       set_light (1);
       smell = "You smell smoke.";
return 1; }}
