inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);
  short_desc="The southern edge of a town square in Mos Eisley.";
  long_desc="You stand on the southern edge of a town square in Mos Eisley.  There's "+
            "nothing much to see here, the redbrick path continues underfoot, and around "+
            "the square are a number of huts offering various services.  This seems to be "+
            "the modern area of the town, and is the workplace for many of the inhabitants.\n\n  ";

  dest_dir=({"/players/redsexy/jedi/areas/moseisley/21","northeast",
             "/players/redsexy/jedi/areas/moseisley/17","northwest",
             "/players/redsexy/jedi/areas/moseisley/23","north",
           });
  
  items=({"path","The path is now paved with redbricks, hot and slightly cracked from the sun, yet still easy to travel on",
          "square","The square is surrounded by cabins built from stone, and you stand on the southern edge",
          "town","This is the modern area of the town of Mos Eisley",
          "redbrick","The paving used absorbs a lot of heat from the sun",
          "huts","Huts dotted around the square",
          "workplace","The huts provide a workplace for the inhabitants of Mos Eisley",
             
         });


  ::reset();
   replace_program("/room/room");

}


