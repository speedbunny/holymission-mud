#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f6","south",
      FORST+"f11","east",
      FORST+"f13","west",     
      }); 
   
   }
 
