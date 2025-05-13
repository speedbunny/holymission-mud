inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);
  short_desc="The town square.";
  long_desc="You now stand in the middle of the town square.  A large statue looms "+
            "above you, sculptured from granite.  You have a good view of the rest "+
            "of the square from here, and you note that each corner has a trade or "+
            "business situated nearby.  \n\n";

  dest_dir=({"/players/redsexy/jedi/areas/moseisley/19","south",
             "/players/redsexy/jedi/areas/moseisley/3","north",
           });
  
  items=({"statue","The statue is immense! It seems to portray the great Jabba the Hut, in a prettier light...",
          "square","The square has a cabin built from stone in each corner, and you stand in the middle",
          "trade","Four huts, one in each corner of the square.",
          "business","The huts on the corners of the square all look like businesses",
          "granite","Its the finest granite!",
         });
 

  ::reset();
   replace_program("/room/room");

}


