#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f35","northwest",
      FORST+"f17","southwest",
      FORST+"f24","west",
      FORST+"f34","northeast",
      }); 
   
   }
 
