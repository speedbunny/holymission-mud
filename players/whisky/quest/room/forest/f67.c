#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f74","north",
      FORST+"f60","southwest",
      FORST+"f59","southeast",
      FORST+"f73","northeast",
      FORST+"f66","east",
      }); 
   
   }
