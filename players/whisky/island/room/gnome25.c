


#define TP  this_player()
#define TPN TP->query_name()
#define TPP TP->query_possessive()

inherit "room/room";
#include "../island.h"
 
void reset(int arg) 
{
      
   if (filter_live(this_object()) < 1)
   {
    CM("gno4");
    CM("gno6");
    CM("gno8");
   }
    
     if ( !arg ) {
     
     
     set_light( 1 );
     short_desc = "In a cavern";
     long_desc = BS(
           "You are in a big cave leading further into the volcano. You recognize "+
           "that the walls are made of black stones and there are lighted torches "+
           "fixed to the walls. You see a lot of little footsteps leading north. "+
           "There is a little corridor leading to the east, where you can hear some "+
           "strange noises coming from. To the north you can see a small "+
           "CRACK in the wall.");
           
              
           
      items = ({
            "cave","The cave leads further to the southwest and east",
            "stones","Big black stones lying on the ground",
            "stone","There are a lot of stones lying around",
            "torches","They are lighted and fixed to the walls",
            "torch","There are lots of torches fixed to the walls",
            "walls","The walls are dark and made of black stones",
            "ground","The ground is full of dark stones",
            "path","The path leads further to the north and east",
            "footsteps","You see a lot of tiny gnomish footsteps, leading southwest and east",
            "volano","Well you are just inside the volcano",
            "crack","A small crack, but big enough to 'enter' it",
            });
            
      dest_dir = ({
            PATH+"gnome21","southwest",
            PATH+"gnome26","east",            
               });
               
          }
        }
        
      init() {
      
        add_action("do_move","move");
        add_action("do_move","push");
        add_action("do_enter","enter"); 
        ::init();
       }

int do_enter(string arg)
{
    if (!arg || arg!="crack")
        return 0;
    write("You squeeze your self through the crack !\n");
    this_player()->move_player(
    "squeezing through a crack#players/whisky/island/room/caves/room/cave1");
    return 1;
}

       
int do_move(string arg) 
{
       
   if ( !arg ) return ( 0 );
                    
       write("You try to move "+arg+" but nothing happens.\n");
       say(TPN+" tries to move "+arg+" but nothing happens.\n");
   return ( 1 );
}
         
