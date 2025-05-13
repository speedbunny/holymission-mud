

inherit "room/room";
reset (arg) {


if (arg) return;

   set_light(0);
   no_castle_flag = 1;

   short_desc = "Cellar";
   long_desc =
     "This is the western part of the cellar.\n"+
     "A slight smell from the east.\n"+
     "dust is all over the place.\n"+
     "It's very messy here.\n";

   dest_dir = ({
      "players/dice/rooms/house6","east"
             });

   items =({
          "mess","Pretty messy here aint it ???",
          "dust","Coaldust.",
          "coaldust","Dust spread by coles.",
          "smell","Smells like coals here."
          });

   smell = "The stence of coaldust is slight here, \n"+
           "and it comes from the east\n";
}
