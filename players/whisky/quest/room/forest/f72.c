#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f79","north",
      FORST+"f65","south",
      FORST+"f73","west",
      FORST+"f71","east",
      }); 
   
   }
