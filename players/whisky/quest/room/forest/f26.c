#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f37","north",
      FORST+"f19","south",
      FORST+"f27","west",
      FORST+"f25","east",
      }); 
   
   }
 
