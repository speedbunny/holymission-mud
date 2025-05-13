

inherit "room/room";
reset (arg) {


if (arg) return;

   set_light(0);
   no_castle_flag = 1;

   short_desc = "Cellar";
   long_desc =
     "This is the southern part of the cellar.\n"+
     "A slight smell is coming from the north,\n"+
     "dust is all over the place.\n"+
     "It's very messy here.\n";

   dest_dir = ({
      "players/dice/rooms/house6","north"
             });

   items =({
          "mess","pretty messy here aint it ???",
          "dust","Coaldust"
          });

   smell = "The stence of coaldust is slight here, \n"+
           "and it comes from the north\n";
}
