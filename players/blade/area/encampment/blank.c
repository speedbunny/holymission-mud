inherit "room/room";

#define FPATH "/players/blade/area/rooms/"

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="A small tunnel through the stone.",
        long_desc=
            "This cave is barely large enough for you to walk standing up.\n" +
	    "The stone walls surround you so closely, making you feel\n"      +
	    "closed in and trapped.\n";     
   dest_dir=({
            FPATH+"cave1.c", "north",
	    FPATH+"cave3.c", "south", 
                 });
   items=({ 
     "walls","They are cold dark stone covered in places with water.",
     "ceiling","The ceiling is high enough so that you do not bump your head.",
     "water","Cold and slimy water that is dripping down the walls.",
   });

        smell = "This place smells very humid.";
    }
}


