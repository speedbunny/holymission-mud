


#define TP  this_player()
#define TPN TP->query_name()
#define TPP TP->query_possessive()

inherit "room/room";
#include "../island.h"
 
void reset(int arg) 
{
      
     if (filter_live(this_object()) < 1)
     {
       CM("gno2");
       CM("gno3");
       CM("gno8");
     }
   
     if ( !arg ) {
     
     
     set_light( 1 );
     short_desc = "In a cavern";
     long_desc = BS(
           "You are in a big cave leading further into the volcano. You recognize "+
           "that the walls are made of black stones and there are lighted torches "+
           "fixed to the walls. You see a lot of little footsteps leading north into "+
           "a strange building where you can hear the noise of metal coming from. "+
           "The cave leads back to the southwest.");
              
           
      items = ({
            "cave","The cave leads further to the north and southwest",
            "stones","Big black stones lying on the ground",
            "stone","There are a lot of stones lying around",
            "torches","They are lighted and fixed to the walls",
            "torch","There are lots of torches fixed to the walls",
            "walls","The walls are dark and made of black stones",
            "ground","The ground is full of dark stones",
            "path","The path leads further to the north and southwest",
            "footsteps","You see a lot of tiny gnomish footsteps, leading in all directions",
            "volano","Well you are just inside the volcano",
            "lake","You see a little dark lake with hot steam coming from it"
            });
            
      dest_dir = ({
            PATH+"gnome23","north",
            PATH+"gnome13","southwest"            
               });
               
          }
        }
        
      init() {
      
        add_action("do_move","move");
        add_action("do_move","push");
        add_action("do_enter","enter");
          
        ::init();
       }
       
       do_move( arg ) {
       
          if ( !arg ) return ( 0 );
                    
          write("You try to move "+arg+" but nothing happens.\n");
          say(TPN+" tries to move "+arg+" but nothing happens.\n");
         return ( 1 );
        }
         
        do_enter( arg ) {
         
         if ( !arg || arg!="lake") {
             notify_fail("Enter what ?\n");
         } else {
             write("You enter the hot lake. Autch the water is damn hot, you struggle\n"+
                   "full of pain and jump back on the path !\n");
             say(TPN+" screams full of pain as "+TP->query_pronoun()+" tries to enter "+
                 "the hot lake.\n");
             TP->hit_player(1+random(4));
           }
        
        return ( 1 );
       }
         
