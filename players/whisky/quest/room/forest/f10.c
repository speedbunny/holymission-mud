#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f18","north",
      FORST+"f11","west",
      FORST+"f5","southwest",
      FORST+"f17","northeast",
      }); 
   
   }
 
