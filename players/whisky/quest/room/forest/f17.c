#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f23","northeast",
      FORST+"f24","north",
      FORST+"f18","west",
      FORST+"f10","southwest",
      }); 
   
   }
 
