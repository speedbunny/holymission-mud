

#define TP  this_player()
#define TPN TP->query_name()
#define TPP TP->query_possessive()

inherit "room/room";
#include "../island.h"
 
object ob;
void reset(int arg) 
{
   
    if (!ob)
    {
      ob = clone_object(MONST+"copper_dragon");
      move_object(ob,this_object());
    }
     
     if ( !arg ) {
     
     
     set_light( 1 );
     short_desc = "In a cavern";
     long_desc = BS(
           "You are in a big cave leading further into the volcano. You recognize "+
           "that the walls are made of black stones and there are lighted torches "+
           "fixed to the walls. You see a lot of little footsteps leading east and "+
           "west. From the east you can hear that STRANGE NOISE getting louder.");
           
              
           
      items = ({
            "cave","The cave leads further to the east and west",
            "stones","Big black stones lying on the ground",
            "stone","There are a lot of stones lying around",
            "torches","They are lighted and fixed to the walls",
            "torch","There are lots of torches fixed to the walls",
            "walls","The walls are dark and made of black stones",
            "ground","The ground is full of dark stones",
            "path","The path leads further to the north and east",
            "footsteps","You see a lot of tiny gnomish footsteps, leading east and west",
            "volano","Well you are just inside the volcano",
            });
            
      dest_dir = ({
            PATH+"gnome25","west",
            PATH+"gnome27","east",            
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
         
