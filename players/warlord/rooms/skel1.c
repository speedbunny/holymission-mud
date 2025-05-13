inherit"room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="Skeleton hallway.\n";
long_desc="You are in a very cluttered hallway. The floor is covered in\n"+
          "rotting corpses and a lot of broken equipment. It looks like a \n"+
          "major battle has taken place here.\n";
items=({
      "floor","It's covered in corpses and broken equipment",
      "corpses","The corpses are rotting away to the point where the maggots are starving",
      "equipment","All the equipment is broken and useless",
      });
dest_dir=({
       "players/warlord/drac/drac1","north",
       "players/warlord/rooms/skel3","south",
        "players/warlord/drac/drachall3","west",
         "players/warlord/rooms/skel2","east",
        });
  }
