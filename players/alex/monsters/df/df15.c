inherit "room/room";
   reset(arg) {
      if (arg) return;
 
    set_light(0);
  short_desc = "Dreadforest";
 long_desc = "You are some were in the Dread forset, most people\n"+
             "would not even think of entering in here but you do not seem so wise.\n" +
             "The forest seems to be unnaturaly quiet and you try to\n"+
             "tread as silent as a elf.\n" +
             "There is a path running east here but outher then that this is a dead end.\n";
 
dest_dir = ({"players/alex/area/df/df16","east",});
 
items=({
        "trees","They all dead but have a evil glow they apear to be watching for something or some$
        "path","A well trod path with strange marks impressed on the surface.",
        "marks","They are very faint but you get the impression that VERY boney feet have passed th$
        "forest","It is dark gloomy and filled with dead trees.",  
       });
 
}
 
 
 
 
 
