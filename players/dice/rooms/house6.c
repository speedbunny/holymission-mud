

inherit "room/room";
reset (arg) {

if (arg) return;

   set_light(0);
   no_castle_flag = 1;

   short_desc = "Cellar";
   long_desc =
     "You have entered the cellar of the house.\n"+
     "A dull smell is surrounding this place,\n"+
     "and dust is all over the place.\n"+
     "It's very messy here.\n";

   dest_dir = ({
      "players/dice/rooms/house1","up",
      "players/dice/rooms/house7","north",
      "players/dice/rooms/house8","south",
      "players/dice/rooms/house9","east",
      "players/dice/rooms/house10","west"
             });

   items =({
          "mess","pretty messy here aint it ???",
          "dust","Coaldust"
          
          });

   smell = "The stence of coaldust keep getting stronger and stronger, \n"+
           "and it comes from the north";
}
