#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f8","north",
      FORST+"f9","northwest",
      FORST+"f1","southeast",
      FORST+"f3","east",
      }); 
   
   }
 
