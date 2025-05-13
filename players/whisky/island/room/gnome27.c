
  /*fixed by haplo 3-22-958 */

#define TP  this_player()
#define TPN TP->query_name()
#define TPP TP->query_possessive()

inherit "room/room";
#include "../island.h"

object gnome;
 
void reset(int arg) 
{
   
      if ( !gnome ) 
          CM("gno11");
         
     
     if ( !arg ) {
     
     
     set_light( 1 );
     short_desc = "In a cavern";
     long_desc = BS(
        "You are in the middle of a really STRANGE PLACE in the volcano. "+
           "The walls are made of black stones and there are lighted torches "+
           "fixed to the walls. You see a lot of little footsteps leading west. "+
           "But if you look up you see some gnomes flying around in the air.");
          
               
      CO("catapult");
     
      items = ({
            "cave","The cave leads further back to the west",
             "stones","Big black stones lying on the ground",
            "stone","There are a lot of stones lying around",
            "torches","They are lighted and fixed to the walls",
            "torch","There are lots of torches fixed to the walls",
            "walls","The walls are dark and made of black stones",
            "ground","The ground is full of dark stones",
            "path","The path leads further to the north and east",
            "footsteps","You see a lot of tiny gnomish footsteps, leading to the west",
          "volcano","Well you are just inside the volcano",
            });
            
      dest_dir = ({
            PATH+"gnome26","west",
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
         
