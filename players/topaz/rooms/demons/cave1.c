inherit "room/room";
reset(arg) {
  if(!arg) {

     short_desc = "A dark cavern";
     long_desc = "This cave makes you nervous.\n" +
                 "There is blood on the floor here.\n" +
                 "Maybe you should turn around and pretend you were\n" +
                 "here!\n";

      dest_dir = ({"players/topaz/rooms/demons/entrance","northwest",
                   "players/topaz/rooms/demons/cave2","south",
                   "players/topaz/rooms/demons/cave3","east",
 
                     });

     items =({"cave","It's pretty dark in here",
              "cavern","It's pretty dark in here",
              "blood","It is all over the floor",
              "floor","Covered with blood.  It's pretty sickening",
              "wall","A normal cave wall",
              "walls","They seem to be closing in on you",
              });
       set_light (1);
       smell = "Your nose is offended by what it finds here!";
return 1; }}
