inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="Garden corridor";
  long_desc="You have arrived at the western end of the path.  There is " +
            "a fountain standing to the west.  Fish jump up every now and " +
            "again.  To the south is the opening through the hedge. You " +
            "can see that this is the way into the garden.  As you look " +
            "at the garden to the south you realise that it appears to be " +
            "as wonderful as it has been described to you.\n";

  items=({"hedge","The hedge seems to attract diffrent types of bugs here",
         "fountain","As you look into the fountain, a gold fish looks " +
                   "up at you and squirts you in the eye with water!  Ouch!",
         "fish","There are a bunch of little goldfish swimming around in " +
                "the fountain.  One seems to almost be mischieviously " +
                "grinning at you",
         "path","It ends here",
         "opening","It is to the south",
         "garden","It almost defies description",         
       });
  dest_dir=({"/players/emerald/garden/garden1","south",
             "/players/emerald/garden/gar_cor2","east",
           });


  ::reset();
  replace_program("/room/room");

}
