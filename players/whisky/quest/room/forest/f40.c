#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f50","north",
      FORST+"f30","south",
      FORST+"f41","west",
      FORST+"f39","east",
      }); 
   
   }
 
