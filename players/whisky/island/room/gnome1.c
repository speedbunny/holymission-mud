

#define TP  this_player()
#define TPN TP->query_name()

inherit "room/room";
#include "../island.h"
 
void reset(int arg) 
{
   
     ::reset ( arg );
     if (filter_live(this_object()) < 1)
         CM("white_dragon");
     
     if ( !arg ) {
     
     
     set_light( 1 );
     short_desc = "In a cavern";
     long_desc = BS(
           "You are at the entrance of a big cavern leading further in the volcano. "+
           "You recognize that the walls are made of black stones and there are "+
           "lighted torches fixed to the walls. Heavy stones are lying on the ground "+
           "and there is a small path leading further north and some light coming "+
           "from the south.");
           
      items = ({
            "cavern","The cavern leads further to the north and south",
            "stones","Big black stones lying on the ground",
            "stone","There are a lot of stones lying around",
            "torches","They are lighted and fixed to the walls",
            "torch","There are lots of torches fixed to the walls",
            "entrance","Well you are just standing at the entrance of the cavern",
            "walls","The walls are dark and made of black stones",
            "ground","The ground is full of dark stones",
            "path","The path is dark and leading further to the north",
            "light","Light coming from the south",
            "rock","@@query_rock@@",
            "volano","Well you are just inside the volcano"
            });
            
      dest_dir = ({
            PATH+"gnome2","north"
            ,PATH+"island22","south"
               });
               
          }
        }
        
      init() {
        add_action("do_move","move");
        add_action("do_move","push");
        add_action("do_south","south");
        add_action("do_south","s");
        ::init();
       }
       
       do_move( arg ) {
       
          if ( !arg ) return ( 0 );
          
          
          write("You try to move "+arg+" but nothing happens.\n");
          say(TPN+" tries to move "+arg+" but nothing happens.\n");
         return ( 1 );
        }
         
     do_south() {
       object partner;
       
       partner=PATH+"island22";
       
       if ( (partner)->query_blocked() ) {
            write("You bump against a big black rock, blocking the exit to the south.\n");
            say(TPN+" bumps against a big black rock.\n");
            TP->hit_player(random(4)+1);
       } else {
            TP->move_player("south#players/whisky/island/room/island22");
         }
       
       return ( 1 );
       }
       
      query_rock() { 
         object partner;
       
         partner=PATH+"island22";
             
         if ( (partner)->query_blocked() ) return "You see a big black rock blocking the exit";
         else return "There are lots of rocks lying around";
         
       return ( 1 );
       
     }
