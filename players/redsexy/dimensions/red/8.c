inherit "room/room";

void reset(int arg) {     
    if(!arg) {
 
       set_light(1);

  short_desc="In the red dimension rooms.";
  long_desc="\
You have entered the dimension halls, where time and space have \
no meaning.  You stand in the lower chambers of the red demons, \
the mirror walls casting a mystical light upon you.  The floors and the \
ceiling are made of red glass, making all sounds intense and sharp to \
the ear.  You feel calm yet alert as you venture onwards. \n\n";

  dest_dir=({"/players/redsexy/dimensions/red/9","east",
             "/players/redsexy/dimensions/red/7","west",
           });
  

  items=({"halls","The dimension halls of Sophillicus",
          "chambers","Glass rooms with magical properties where demons train",
          "mirror","You see your own reflection",
          "walls","The walls are made of mirrored red glass",
          "light","A mystical red light is reflected off the mirrors",
          "glass","Red glass from which the chambers are built",
         });
   
   clone_list=({

          1, 1, "demon", "/players/redsexy/dimensions/monsters/red8", 0,

  });

    }
    ::reset(arg);
    replace_program("room/room");
}


