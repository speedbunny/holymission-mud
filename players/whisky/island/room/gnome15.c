

#define TP  this_player()
#define TPN TP->query_name()
#define TPP TP->query_possessive()

inherit "room/room";
#include "../island.h"
 
void reset(int arg) 
{
   
     ::reset ( arg );
     
     if ( !arg ) {
     
     
     set_light( 1 );
     short_desc = "In a cavern";
     long_desc = BS(
           "You are in a big cave leading further into the volcano. You recognize "+
           "that the walls are made of black stones and there are lighted torches "+
           "fixed to the walls. You see a lot of little footsteps leading northwest. "+
           "The air is really hot here. To the northeast there is the ENTRANCE of a "+
           "small building and there is a very LOUD PLACE to the west.");
              
           
      items = ({
            "cave","The cave leads further to the northeast, southwest, west and north",
            "stones","Big black stones lying on the ground",
            "stone","There are a lot of stones lying around",
            "torches","They are lighted and fixed to the walls",
            "torch","There are lots of torches fixed to the walls",
            "walls","The walls are dark and made of black stones",
            "ground","The ground is full of dark stones",
            "path","The path leads further to the northwest and west",
            "footsteps","You see a lot of tiny gnomish footsteps, leading northeast, southwest, west and north",
            "volano","Well you are just inside the volcano",
            "lake","You see a little dark lake with hot steam coming from it"
            });
            
      dest_dir = ({
            PATH+"gnome20","northeast",            
            PATH+"gnome12","southwest",
            PATH+"gnome14","west",
            PATH+"gnome19","north"
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
         
        
