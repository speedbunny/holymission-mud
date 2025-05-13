inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);
  short_desc="The edge of a town square in the Mos Eisley desert.";
  long_desc="This path is more modern, and redbricks replace the cobblestones "+
            "making it easier to travel here on foot.  You realise that you are "+
            "now on the edge of a kind of town square, surrounded by workplaces of "+
            "various trades.  There seems to be a lot of farmpeople around the square, " +
            "purchasing goods for their land.  Perhaps you should investigate further? \n\n";

  dest_dir=({"/players/redsexy/jedi/areas/moseisley/16","southwest",
             "/players/redsexy/jedi/areas/moseisley/2","north",
             "/players/redsexy/jedi/areas/moseisley/22","southeast",
             "/players/redsexy/jedi/areas/moseisley/23","south",           
           });
  
  items=({"path","The path is now paved with redbricks, hot from the sun, yet still easy to travel on",
          "square","The square is surrounded by cabins built from stone, and you stand on the northernmost edge",
          "workplaces","Cabins made of stone dotted around the square look like workplaces",
          "farmpeople","Many farmpeople are wandering around the square",
          "goods","The goods the people seem to carry are for the farmland",
          "sun","The sun is fierce here, and the redbricks absorb a lot of the heat",
         });

  ::reset();
   replace_program("/room/room");

}


