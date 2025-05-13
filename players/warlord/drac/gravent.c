inherit"room/room";

reset(arg) {
   if (arg) return;
   set_light(1);
   short_desc="Graveyard entrance\n";
   long_desc=
"You see a large fence to the north of you with a gate open. Beyond\n"+
          "the gate is a graveyard. To the west you notice an arch.\n";
   items=({
      "fence","You see a large iron fence ",
      "arch","The arch looks to be carved masterfully",
   });
   dest_dir=({
            "players/warlord/rooms/hall2","east",
      "players/warlord/drac/grave1","gate",
   });
}
