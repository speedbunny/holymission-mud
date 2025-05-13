inherit "room/room";

void reset(int arg) {     
    if(!arg) {
 
       set_light(1);

  short_desc="In the yellow dimension rooms.";
  long_desc="\
You have found the dimension halls, where time and space have \
no meaning.  You stand in the higher chambers of the yellow demons, \
the mirror walls casting a mystical light upon you.  The floors and the \
ceiling are made of yellow glass, making all sounds intense and sharp to \
the ear.  You feel calm yet alert as you venture onwards. \n\n";

  dest_dir=({"/players/redsexy/dimensions/yellow/3","east",
             "/players/redsexy/dimensions/yellow/1","west",
          });


  items=({"halls","The dimension halls of Sophillicus",
          "chambers","Glass rooms with magical properties where demons train",
          "mirror","You see your own reflection",
          "walls","The walls are made of mirrored yellow glass",
          "light","A mystical yellow light is reflected off the mirrors",
          "glass","Yellow glass from which the chambers are built",
         });
   
   clone_list=({

          1, 1, "demon", "/players/redsexy/dimensions/monsters/yellow2", 0,

  });

    }
    ::reset(arg);
    replace_program("room/room");
}


