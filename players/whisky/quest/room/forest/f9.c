#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f15","north",
      FORST+"f8","east",
      FORST+"f16","northwest",
      FORST+"f4","southeast",
      }); 
   
   }
 
