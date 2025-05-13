/* Metaprat - automatically generated house room */

/* Save as: ROOMSDIR/house_0.c */

inherit "/room/room.c";

#define OWNER     "baer"
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
         "/room/church", "church",
         "/room/shop", "shop"
            });
      my_short_desc = "0";
      long_desc =
