

#define TP  this_player()
#define TPN TP->query_name()

inherit "room/room";
#include "../island.h"


void reset(int arg) 
{
  if (filter_live(this_object()) < 1)
  {
    CM("gno13");
    CM("gno14");
  }
     
     if ( !arg ) {
     
     
     set_light( 1 );
     short_desc = "In a cavern";
     long_desc = BS(
           "You are at the in a big cave leading further in the volcano. "+
           "You recognize that the walls are made of black stones and there are "+
           "lighted torches fixed to the walls. Heavy stones are lying on the ground "+
           "and there is a small path leading further east and west. You can hear "+
           "some voices coming from the east.");
           
      items = ({
            "cave","The cave leads further to the east and west",
            "stones","Big black stones lying on the ground",
            "stone","There are a lot of stones lying around",
            "torches","They are lighted and fixed to the walls",
            "torch","There are lots of torches fixed to the walls",
            "entrance","Well you are just standing at the entrance of the cavern",
            "walls","The walls are dark and made of black stones",
            "ground","The ground is full of dark stones",
            "path","The path is dark and leading further to the east and west",
            "volano","Well you are just inside the volcano"
            });
            
      dest_dir = ({
            PATH+"gnome5","west",
            PATH+"gnome7","east"
               });
               
          }
        }
        
      init() {
        add_action("do_move","move");
        add_action("do_move","push");
        ::init();
       }
       
       do_move( arg ) {
       
          if ( !arg ) return ( 0 );
          
          
          write("You try to move "+arg+" but nothing happens.\n");
          say(TPN+" tries to move "+arg+" but nothing happens.\n");
         return ( 1 );
        }
         
