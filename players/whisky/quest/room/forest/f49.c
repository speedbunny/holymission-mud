#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f57","northeast",
      FORST+"f39","south",
      FORST+"f50","west",     
      }); 
   
   }
