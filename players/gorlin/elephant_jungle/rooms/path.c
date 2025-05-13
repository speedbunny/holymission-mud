/* Gorlin, 15.10.1996 */

inherit "room/room";

void reset (int arg) {

   ::reset (arg);
   if (arg) return;

   short_desc="Path";
   long_desc="You stand on a path leading south into a large jungle, "+
      "and north to ????HM-village????\n";
   set_light(1);
   dest_dir=({
      "/OUT_OF_HERE","north",
      "/players/gorlin/elephant_jungle/rooms/jungle1","south",
   });
   items=({
      "jungle","The jungle is large, very large. It extends far "+
         "to the south. The path leads directly into the jungle, "+
         "inviting you to follow it south.",
   });
   replace_program("room/room");
   return;
}
