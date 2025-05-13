inherit "room/room";

reset(arg) {
   set_light(1);
   short_desc = "Courtyard";
   long_desc = "You stand at the east end of a beautiful courtyard. "+
                      "While many flowers are still in bloom, it looks as if "+
                      "the gardener has been at work recently.  To the west "+ 
                      "the courtyard continues, while to the east one of the castle "+
                      "walls.\n";
   smell = "The air sweet";
   dest_dir = ({"players/kawai/areas/dwarves/palace/centeryard","west"});
   items = ({"cave","It is large and illuminated by a strange source",
                "passage","It is small and barely lit",
                 "wall","Gee...A wall....not much to say about that",
                  "courtyard","It is beautifully decorated.  In the center is a large statue",
                  "statue","It is a large statue of the king....obviously not life-sized",
                  "flowers","Roses, tulips, lilacs...the usual sort",
                  "rose","'Tis a rose...and a beautiful one",
                  "roses","Rows of various colores rose bushes adorn the yard",
                  "tulip","A tulip!  How lovely!",
                  "tulips","You've always thought that Two lips are better better than one!\n"+
                             "(Bad pun, I know...)",
                  "lilac","The lilac is sweetly scented",
                  "lilacs","The lilac bush is in full bloom and a nice deep lavender color",
                  "castle","It's the king's palace.  Not very large, but nicely\n"+
                               "decorated, though",         
                  "shrubs","lots of shrub sculputres",
                  "shrub","Look! Its a shrub sculpture of a....a.....shrub!",
                  "flower","A rose, how lovely!",
                  "palace","It's the king's palace.  Not very large, but nicely\n"+
                               "decorated, though"});
::reset(arg);
replace_program("room/room");
}

