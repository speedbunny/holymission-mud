#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f42","southwest",
      FORST+"f41","south",
      FORST+"f52","west",
      FORST+"f50","east",
      }); 
   
   }
