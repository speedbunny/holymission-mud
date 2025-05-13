inherit "room/room";

void reset(int arg) {

  if(arg) return;

  long_desc="You have entered a very smelly room.  The floor here is " +
            "covered with rotting cheese.  The smell is so horrible that you "+
            "feel like throwing up!  You notice that the cheese looks like " +
            "it was left here by accident.\n";

  short_desc="A smelly room";

  dest_dir=({"/players/emerald/good/evil/evil18","south",
             "/players/emerald/good/evil/evil20","east"
           });

  items=({"cheese","This is a rotting swiss cheese, full of holes.\n"+
                       "One of the holes seems rather large",
          "hole","You look in a hole and see the word 'three' inscribed",
          "room","It stinks",
          "holes","One of the holes is rather large",
          "floor","You can't see the floor.  It's covered in rotting cheese",
        });

  smell="The sickening fragrance of rotting cheese";

  ::reset();
  replace_program("/room/room");

}
