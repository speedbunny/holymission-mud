inherit "room/room";

void reset(int arg) {     
    if(!arg) {
 
       set_light(1);

  short_desc="In the violet dimension rooms.";
  long_desc="\
You have found the dimension halls, where time and space have \
no meaning.  You stand in the higher chambers of the violet demons, \
the mirror walls casting a mystical light upon you.  The floors and the \
ceiling are made of violet glass, making all sounds intense and sharp to \
the ear.  You feel calm yet alert as you venture onwards. \n\n";

  dest_dir=({"/players/redsexy/dimensions/violet/2","west",
             "/players/redsexy/dimensions/violet/6","southeast",
           });
  

  items=({"halls","The dimension halls of Sophillicus",
          "chambers","Glass rooms with magical properties where demons train",
          "mirror","You see your own reflection",
          "walls","The walls are made of mirrored violet glass",
          "light","A mystical violet light is reflected off the mirrors",
          "glass","Violet glass from which the chambers are built",
         });
   
   clone_list=({

          1, 1, "demon", "/players/redsexy/dimensions/monsters/violet3", 0,

  });

    }
    ::reset(arg);
    replace_program("room/room");
}


