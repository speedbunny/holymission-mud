#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f3","west",
      FORST+"f6","north",
      FORST+"f5","northeast",
      FORST+"f1","southwest",
      }); 
   
   }
 
