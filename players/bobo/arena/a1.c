inherit "room/room";
reset (arg) {
   if (arg) return;
   set_light(1);
   short_desc="Inside the arena.";
   long_desc=
"You are in the colliseum.  Unfortunately, it appears that you are not\n"+
"a spectator but a participant.  The arena itself is very large and\n"+
"filled with many different animals and people.  There are many people\n"+
"in the stands yelling various things.  Right now you are near the\n"+
"southernmost wall next to the exit, fortunately the portcullis is\n"+
"still up, making escape possible.\n";
   dest_dir=({
        "players/bobo/arena/road2.c","south",
        "players/bobo/arena/a3.c","north",
   });
   items=({
        "arena","Round in shape, the arena looks like it has high, unclimbable walls",
        "people","Many vicious spectators waiting to see blood spill",
        "stands","Big stone steps double as seats for the crowds",
        "wall","The wall is tall and sheer and definitely unclimbable",
        "portcullis","It's still up so you can beat a hasty retreat if you want to",
   });
   replace_program ("room/room");
}
