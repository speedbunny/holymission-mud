#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f13","north",
      FORST+"f6","east",
      FORST+"f8","west",
      FORST+"f3","south",
      }); 
   
   }
 
