#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f73","southwest",
      FORST+"f72","south",
      FORST+"f80","west",
      FORST+"f78","east",
      }); 
   
   }
 
