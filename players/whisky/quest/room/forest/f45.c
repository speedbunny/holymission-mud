#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({      
      FORST+"f46","west",
      FORST+"f44","east",
      }); 
   
   }
