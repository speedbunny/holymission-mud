inherit"room/room";
reset (arg) {
if (arg) return 1;
set_light(1);
short_desc="East side of pond.\n";
long_desc="You are a pond of pure ice. You can see many colors coming \n"+
          "from under the ice. You feel a slight chill on your nose. The\n"+
          "pond continues to the north, west and south.\n";
items=({ "ice","The ice is very bright almost blinding",
      });
dest_dir=({"/players/warlord/new/n40","east",
           "/players/warlord/new/n31","north",
           "/players/warlord/new/n47","south",
           "/players/warlord/new/n38","west",
         });
return 1;
}
