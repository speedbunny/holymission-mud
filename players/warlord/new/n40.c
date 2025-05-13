inherit"room/room";
reset (arg) {
if (arg) return 1;
set_light(1);
short_desc="Forest of winter\n";
long_desc="You have entered the cold forbidden region. You obviously are a\n"+
          "new player to these parts so enjoy this land. Have fun but don't\n"+
          "fall for it may hurt. All you can see around you is a pond to the\n"+
          "west and trees to the north and south. If you want to leave this\n"+
          "area just go east.\n";
items=({ "trees","The trees are covered in a blanket of snow and ice",
      });
dest_dir=({"/players/warlord/entrance","east",
          "/players/warlord/new/n32","north",
          "/players/warlord/new/n48","south",
          "/players/warlord/new/n39","west",
        });
return 1;
}
