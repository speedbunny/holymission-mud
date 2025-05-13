/* Metaprat - automatically generated house room */

/* Save as: ROOMSDIR/house_3.c */

inherit "/room/room.c";

#define OWNER     "baer"
#define ROOMSDIR  "/players/"+OWNER+"/rooms/"
#define PREFIX    "house_"

reset(arg) {
   if (!arg) {
      no_castle_flag = 1;
      set_light(1);

      dest_dir =  ({
         ROOMSDIR+PREFIX+ "2", "south",
         ROOMSDIR+PREFIX+ "1", "west"
            });
      my_short_desc = "Bedroom";
      long_desc =
"This is Tuppy's Bedroom\n" +
"There is a big bed in the middle of the room.\n";
   }
}
