inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);
  short_desc="A gaming area in the Mos Eisley Cantina.";
  long_desc="This area of the cantina seems to be set aside for illegal "+
            "gambling and games. There is a poker table set up in the corner "+
            "and you'd quite fancy a game if you could ever figure out how to "+
            "play! This room is full of smoke, from the pipes and cigars of the "+
            "rich creatures who play here, so you don't feel like hanging around "+
            "for too long. \n\n ";

  dest_dir=({"/players/redsexy/jedi/areas/cantina/5","north",
             "/players/redsexy/jedi/areas/cantina/15","south",
           });

  items=({"bar","This is the Mos Eisley Cantina, and it is packed",
          "creatures","The rich creatures who gamble here all look pretty tough",
          "smoke","Horrible cigar and cigarette smoke makes you cough",
          "corner","The dark corner looks like something from a gangster underworld",
          "desert","Forget about it!  RELAX....",
          "poker","It is a poker table, type 'help poker' for details",
          "pipes","Some creatures smoke the wunga tobacco in long pipes",
          "cigars","Mos Eisley's finest hand rolled cigars are smoked by some of the creatures",

         });

   clone_list=({  1, 1, "table", "/players/redsexy/jedi/objects/poker", 0,
               });
  

  ::reset(arg);
  replace_program("/room/room");

}

