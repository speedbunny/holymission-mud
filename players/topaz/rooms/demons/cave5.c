inherit "room/room";
reset(arg) {
  if(!arg) {

     short_desc = "A small tunnel";
     long_desc = "This tunnel seems well used.  The demons must have some\n" +
                 "reason that they come back here a lot.  It is still very\n" +
                 "bright here from the bonfire but it gets darker to the\n" +
                 "west.  From the east you hear some very strange music.\n";

      dest_dir = ({"players/topaz/rooms/demons/cave4","north",
                   "players/topaz/rooms/demons/cave6","west",
                   "players/topaz/rooms/demons/cave9","east",
 
                     });

     items =({"cave","What a scary cave",
              });
       set_light (1);
       smell = "You smell smoke coming from the north.";
return 1; }}
