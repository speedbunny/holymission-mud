#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f71","south",
      FORST+"f79","west",
      FORST+"f77","east",
      }); 
   
   }
 
