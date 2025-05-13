inherit "room/room";

void reset(int arg) {     
    if(!arg) {
 
       set_light(1);

  short_desc="In the indigo dimension rooms.";
  long_desc="\
You have found the dimension halls, where time and space have \
no meaning.  You stand in the middle chambers of the indigo demons, \
the mirror walls casting a mystical light upon you.  The floors and the \
ceiling are made of indigo glass, making all sounds intense and sharp to \
the ear.  You feel calm yet alert as you venture onwards. \n\n";

  dest_dir=({"/players/redsexy/dimensions/indigo/5","east",
             "/players/redsexy/dimensions/indigo/7","southwest",
           });
  

  items=({"halls","The dimension halls of Sophillicus",
          "chambers","Glass rooms with magical properties where demons train",
          "mirror","You see your own reflection",
          "walls","The walls are made of mirrored indigo glass",
          "light","A mystical indigo light is reflected off the mirrors",
          "glass","Indigo glass from which the chambers are built",
         });
   
   clone_list=({

          1, 1, "demon", "/players/redsexy/dimensions/monsters/indigo4", 0,

  });

    }
    ::reset(arg);
    replace_program("room/room");
}


