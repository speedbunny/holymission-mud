#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f48","north",
      FORST+"f27","south",
      FORST+"f37","east",
      }); 
   
   }
 
