inherit"room/room";
reset(arg) {
if (arg)return;
  set_light(1);
 short_desc="Thick forest.\n";
 long_desc="This part of the forest is very quiet.You can feel a \n"+
          "strange presence near you.\n";
           "strange presence near you./n";
  items=({
  "forest","The forest is green and quiet",
  });
  dest_dir=({
   "players/warlord/quest/dungeon/for1","south",
  });
  return 1;
  }
