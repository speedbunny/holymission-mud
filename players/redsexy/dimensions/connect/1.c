inherit "room/room";

void reset(int arg) {     
    if(!arg) {
 
       set_light(1);

  short_desc="The corridor of the dimension halls.";
  long_desc="\
You stand in a corridor of the dimension halls, decorated in black \
and mysteriously quiet.  Legend has it that this is the realm where \
demons come to take tests and improve their skills before being born into the world we know as \
the Holy Mission.  Light shines in from the exits, illuminating the \
glass walls that surround you. \n\n";

  dest_dir=({"/players/redsexy/dimensions/connect/chamber","south",
             "/room/church","north",
          });


  items=({"halls","The dimension halls of Sophillicus",
          "exits","Something a little bit too familiar lies to your north....",
          "chambers","Glass rooms with magical properties where demons come to take tests and improve",
          "corridor","You see your own reflection",
          "walls","The walls are made of mirrored glass",
          "light","A mystical light is reflected off the mirrors",
          "glass","Glass from which the chambers are built",
         });
   }
    ::reset(arg);
}


