inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);
  short_desc="The enterance to a town in the Mos Eisley desert.";
  long_desc="The city wall of Mos Eisley runs to your north as you continue "+
            "through the town.  The cobblestone now form a path which forks "+
            "to the south or sotheast here, and there is a wooden sign hammered "+
            "into the ground. Shielded from the sun a little, you contemplate " +
            "which way to turn before continuing. \n\n";

  dest_dir=({"/players/redsexy/jedi/areas/moseisley/1","west",
             "/players/redsexy/jedi/areas/moseisley/3","south",
             "/players/redsexy/jedi/areas/moseisley/4","southeast",
           });
  
  items=({"wall","The city wall prevents enterance or eixt to the town, except via the archway",
          "sign","The sign reads: Modezville, south - Elderville, southeast ",
          "sand","The sand is replaced by cobblestones here",
          "town","The cobblestone pavings seem to indicate this is some kind of town",
          "desert","The desert lies to the west",
          "sun","The town wall is so high, it casts a shadow shielding you from the sun",
         });

  ::reset();
   replace_program("/room/room");

}


