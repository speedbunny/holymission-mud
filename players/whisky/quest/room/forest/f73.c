#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f79","northeast",
      FORST+"f66","south",
      FORST+"f67","southwest",
      FORST+"f72","east",
      }); 
   
   }
