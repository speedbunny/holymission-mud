inherit "room/room";
reset(arg) {
  if(!arg) {

     short_desc = "A narrow crevice";
     long_desc = "This is a narrow crevice.\n" +
                 "You just barely fit in here.\n" +
                 "\n" +
                 "'Claustrophobia' would be a good way to describe your\n" +
                 "feelings now!\n";

      dest_dir = ({"players/topaz/rooms/tower/towerdoor","north",
                   "players/topaz/rooms/demons/cave3","south",
 
                     });

     items =({"crevice","Hardly any room at all in here",
              });
       set_light (0);
       smell = "You smell stale air.";
return 1; }}
