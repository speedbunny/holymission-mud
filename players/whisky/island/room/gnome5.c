

#define TP  this_player()
#define TPN TP->query_name()
#define TPP TP->query_possessive()

inherit "room/room";
#include "../island.h"
 
void reset(int arg)
{
   
     if ( !arg ) {
     
     
     set_light( 1 );
     short_desc = "In a cavern";
     long_desc = BS(
           "You are in a big  cave leading further into the volcano. You recognize "+
           "that the walls are made of black stones and there are lighted torches "+
           "fixed to the walls. South there is a big iron pole leading up. You see "+
           "a small path leading further to the east and you hear some human noises "+
           "coming from there.");
           
           
      items = ({
            "stones","Big black stones lying on the ground",
            "stone","There are a lot of stones lying around",
            "torches","They are lighted and fixed to the walls",
            "torch","There are lots of torches fixed to the walls",
            "walls","The walls are dark and made of black stones",
            "ground","The ground is full of dark stones",
            "path","The path leads further to the east",
            "pole","A big iron pole leading down, it seems possible to slide on it",
            "volano","Well you are just inside the volcano"
            });
            
      dest_dir = ({
            PATH+"gnome6","east"
               });
               
          }
        }
        
      init() {
      
        add_action("do_move","move");
        add_action("do_move","push");
        add_action("do_slide","slide");
        add_action("do_climb","climb");
        
        ::init();
       }
       
       do_move( arg ) {
       
          if ( !arg ) return ( 0 );
                    
          write("You try to move "+arg+" but nothing happens.\n");
          say(TPN+" tries to move "+arg+" but nothing happens.\n");
         return ( 1 );
        }
         
     do_slide ( arg ) {
     
        if (!arg || arg!="pole") {
            notify_fail("Sliding what ?\n");
        } else {
            write("You already reached the ground.\n");
        }
         
       return ( 1 );
      }
      
      do_climb( arg ) {
      
        if (!arg) {
            notify_fail("Climbing what ?\n");
        } else if (arg=="pole") {
            write("You try to climb up the pole, but slide down again.\n");                  
            say(TPN+" tries to climb up the pole, but slides down again.\n");
             
         } else {
             notify_fail("You try to climb "+arg+", but fail.\n");
           }
          
        return ( 1 );
      } 
      
