#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({      
      FORST+"f29","west",
      FORST+"f27","east",
      }); 
   
   }
 
