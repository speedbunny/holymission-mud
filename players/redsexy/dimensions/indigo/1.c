inherit "room/room";

void reset(int arg) {     
    if(!arg) {
 
       set_light(1);

  short_desc="The corridor of the dimension halls.";
  long_desc="\
You stand in the highest indigo dimension chamber, where the keeper \
of the indigo demons lives.  The whole room is made of glass, reflecting \
light at strange angles and making you lose your sense of direction. \
The whole place is very quiet and mysterious, and you feel humbled by \
the man who stands before you. \n\n";

  dest_dir=({"/players/redsexy/dimensions/connect/7","east",
             "/players/redsexy/dimensions/indigo/2","northwest",
          });


  items=({"halls","The dimension halls of Sophillicus",
          "chamber","Glass rooms with magical properties where demons train",
          "mirror","You see your own reflection",
          "walls","The walls are made of mirroindigo glass",
          "light","A mystical light is reflected off the mirrors",
          "glass","Glass from which the chamber are built",
          "man","The keeper of the indigo Domain",
         });
   clone_list=({

          1, 1, "keeper", "/players/redsexy/dimensions/monsters/indigokeeper", 0,

  });

   
    }
    ::reset(arg);
    replace_program("room/room");
}


