/* Metaprat - automatically generated house room */

/* Save as: ROOMSDIR/house_0.c */

inherit "/room/room.c";

#define OWNER     "bgs"
#define ROOMSDIR  "/players/"+OWNER+"/rooms/"
#define PREFIX    "house_"

reset(arg) {
   if (!arg) {
      no_castle_flag = 1;
      set_light(1);

      dest_dir =  ({
         ROOMSDIR+PREFIX+ "1", "north",
         ROOMSDIR+PREFIX+ "2", "east"
         })   +    ({
         "/room/church", "church"
            });
      my_short_desc = "nice";
      long_desc =
"A big central room. There are cables leading to the room to the north.\n" +
"You can hear the noices of computers for north.\n" +
"To the east you see another room.\n";
   }
}
