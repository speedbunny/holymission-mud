
#define TP  this_player()
#define TPN TP->query_name()
#define TPP TP->query_possessive()


inherit "room/room";
#include "../island.h"
     object board;
 
void reset(int arg) 
{
   
     if ( !arg ) {
     
     
     set_light( 1 );
     short_desc = "In a cavern";
     long_desc = BS(
           "You are in a big cave in the volcano. You recognize that this must "+
           "be a kind of communication place for the gnomes. The walls are made "+
           "of black stones and there are lighted torches fixed to the wall. "+
           "You see a lot of little footsteps leading west and a board fixed "+
           "to the eastern wall.");
           
           
              
           
      items = ({
            "cave","The cave leads further to the west",
            "stones","Big black stones lying on the ground",
            "stone","There are a lot of stones lying around",
            "torches","They are lighted and fixed to the walls",
            "torch","There are lots of torches fixed to the walls",
            "walls","The walls are dark and made of black stones",
            "ground","The ground is full of dark stones",
            "path","The path leads further to the north and east",
            "footsteps","You see a lot of tiny gnomish footsteps, leading west",
            "volano","Well you are just inside the volcano",
            });
            
      dest_dir = ({
            PATH+"gnome16","west"
            });
               
          }
          
       if(!board) {
          board=clone_object("/players/whisky/genobj/board");
          board->set_file("players/whisky/island/gnome_board");
          board->set_name("board");
          board->set_short("TheGnomeBoard");
         transfer(board,this_object());
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
         
