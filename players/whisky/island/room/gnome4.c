


#define TP  this_player()
#define TPN TP->query_name()
#define TPP TP->query_possessive()

inherit "room/room";
#include "../island.h"
 
void reset(int arg) 
{
  if (filter_live(this_object()) < 1)
  {
    CM("gno1");
    CM("gno3");
  }
   
     if ( !arg ) {
     
     
     set_light( 1 );
     short_desc = "In a cavern";
     long_desc = BS(
           "You are in a big cave that leads into the volcano. You "+
           "recognize that the walls are made of shiny black stones "+
           "and there are lighted torches fixed to the walls. North "+
           "there is a big iron pole leading down into a deep hole "+
           "from which you hear human noises. On the right side of "+
           "the cave there is a net fixed to two large sticks. The "+
           "only way out would appear to be to the east.");
           
      items = ({
            "cavern","The cavern leads back to south",
            "stones","Big black stones lying on the ground",
            "stone","There are a lot of stones lying around",
            "torches","They are lighted and fixed to the walls",
            "torch","There are lots of torches fixed to the walls",
            "net","A big net fixed on 2 sticks",
            "walls","The walls are dark and made of black stones",
            "ground","The ground is full of dark stones",
            "path","The path is dark leads back to the east",
            "sticks","You see two big wooden sticks fixed to the ground",
            "stick","You see 2 sticks",
            "hole","A really big hole, there is some light coming from it",
            "pole","A big iron pole leading down, it seems possible to slide on it",
            "volano","Well you are just inside the volcano"
            });
            
      dest_dir = ({
            PATH+"gnome3","east"
               });
               
          }
        }
        
      init() {
      
        add_action("do_move","move");
        add_action("do_move","push");
        add_action("do_north","north");
        add_action("do_north","n");
        add_action("do_north","jump");
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
         
     do_north() {
       
       write("\n\n################    YOU ARE FALLING   #################\n\n"+
             "\n\n################    YOU ARE FALLING   #################\n\n"+   
             "\n\n################    YOU ARE FALLING   #################\n\n"+   
             "\n\n################    YOU ARE FALLING   #################\n\n"+   
              "OUCH! You fall on the hard ground!!! \n");
             
             TP->hit_player( random(TP->query_max_hp()/4) );
             
             TP->move_player(" fast as a stone down into the hole#players/whisky/island/room/gnome5");
                              
       return ( 1 );
     }
       
     do_slide ( arg ) {
     
        if (!arg || arg!="pole") {
            notify_fail("Sliding what ?\n");
        } else {
            write("\n\nZIIIIIIIIIIIIPPPPPPPPPPPP  You slide down the pole.\n\n");
            TP->move_player(" sliding down the pole#players/whisky/island/room/gnome5");
         }
         
       return ( 1 );
      }
      
      do_climb( arg ) {
      
        if (!arg) {
            notify_fail("Climbing what ?\n");
        } else if (arg=="pole") {
            write("You climb up the pole and bump your head against the cavewall\n"+
                  "AUTCH that hurts, you fall down again !\n");
            say(TPN+" tries to climb up the pole, but hurts "+TPP+" head badly on\n"+
                "the cavewall and falls down again.\n");
            TP->hit_player(1+random(4));
            
         } else {
             notify_fail("You try to climb "+arg+", but fail.\n");
           }
          
        return ( 1 );
      } 
      
        
