/* EASTROAD5 */
/* 120593: Airborne: Replace_program added */
/* 090793: Ethereal Cashimor: Northexit added */
/* 101293: Galadriel: down changed from capablanca to portil */
/* 170295: Sir Goldsun: removed down and changed to up to goldsun */
/* 	  	        change description */

inherit "room/room";

reset(arg) {
  if(!arg) {
    set_light(1);
    short_desc="East road";
    long_desc="East road runs south from here. To the west lies the Eastroad "
            + "Inn. A narrow path leads up to shiny dark castle.\n";

   //         Stairs lead down to the training halls of the famous "
   //         + "fighter guild.\n";

    dest_dir=({"room/eastroad4","south",
               "room/inn","west",
               "players/goldsun/guild/room/outside","up",
               "players/kelly/rooms/vill/eastroad6","north"});
    smell="There isn't a really pervading smell here.";
    replace_program("room/room");
  }
}
