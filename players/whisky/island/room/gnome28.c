inherit "/players/whisky/genesis/std/shop";
#include "../island.h"
 


void reset(int arg) 
{
  object ob;
   
      ::reset(arg);
    if (!find_living("Nun Blackmoon"))
    {
        ob = clone_object("/players/whisky/guild/monster/blackmoon");
     transfer(ob,this_object());
      }
      else
      {
        catch(destruct(find_object(
                       "/players/whisky/guild/monster/blackmoon")));

       }
     
     if ( !arg ) {
     
     
     set_light( 1 );
     short_desc = "In a cavern";
     long_desc = BS(
     "You are in a big warm cave in the volcano. It's really hot but friendly "+
           "here the walls are made of black stones and there are lighted torches "+
           "fixed to the walls. You see a lot of little footsteps leading south. "+
           "There is a  ROPE and a big SIGN fixed on the wall and you see a big. "+
           
           "wooden desk to the north.");
     
      store = PATH+"ostore";
      keeper = "Krznrk";
      type = "trader";         
           
      items = ({
            "cave","The cave leads back to the south",
            "stones","Big black stones lying on the ground",
            "stone","There are a lot of stones lying around",
            "torches","They are lighted and fixed to the walls",
            "torch","There are lots of torches fixed to the walls",
            "walls","The walls are dark and made of black stones",
            "ground","The ground is full of dark stones",
            "footsteps","You see a lot of tiny gnomish footsteps, leading south",
         "volcano","Well you are just inside the volcano",
            "rope","It's a long brown hanf-rope, which is fixed to the wall",
            "krznrk","He is sitting behind the desc waiting patiencely",
            "sign","A big iron sign, maybe you should read it",
            "desc","A big oak-wooden desc"
               });
            
      dest_dir = ({
            PATH+"gnome24","south"          
               });

         move_object(clone_object("/obj/torch"),query_store());               
         move_object(clone_object("/obj/torch"),query_store());               
         move_object(clone_object("/obj/torch"),query_store());               
         move_object(clone_object("/obj/rope"),query_store());               
          }
        }

init( )
{
   ::init( );
   add_action( "do_read", "read" );
 
}

int do_read(string str)
{
  if (str!="sign") return 0;
  write("Here you can: list, buy, sell, value all kinds of stuff.\n");
  return 1;
}

