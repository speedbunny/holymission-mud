#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f65","northwest",
      FORST+"f48","southeast",
      FORST+"f49","southwest",
      FORST+"f63","northeast",
      }); 
   
   }
