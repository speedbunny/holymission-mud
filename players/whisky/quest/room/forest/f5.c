#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f11","north",
      FORST+"f6","west",
      FORST+"f10","northeast",
      FORST+"f2","southwest",
      }); 
   
   }
 
