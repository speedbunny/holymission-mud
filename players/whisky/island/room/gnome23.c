
  /* fixed by haplo 3-22-95 */


inherit "/players/whisky/genesis/std/shop";
#include "../island.h"
 
void reset(int arg) 
{
   
     ::reset ( arg );
     
     if ( !arg ) {
     
     
     set_light( 1 );
     short_desc = "In a cavern";
     long_desc = BS(
      "You are in a big warm cave in the volcano. It's really hot but friendly "+
           "here the walls are made of black stones and there are lighted torches "+
           "fixed to the walls. You see a lot of little footsteps leading south. "+
          "There is a sword and a big SIGN fixed on the wall and you see a big. "+
         "wooden desk to the north.");
              
      keeper = "Cizra";
      type = "smithy";
      store = PATH+"wstore";
           
      items = ({
            "cave","The cave leads further to the north and southwest",
            "stones","Big black stones lying on the ground",
            "stone","There are a lot of stones lying around",
            "torches","They are lighted and fixed to the walls",
            "torch","There are lots of torches fixed to the walls",
            "walls","The walls are dark and made of black stones",
            "ground","The ground is full of dark stones",
            "cizra","She is sitting behind the desk, snickering happily",
            "footsteps","You see a lot of tiny gnomish footsteps, leading south",
           "volcano","Well you are just inside the volcano",
            "sword","It's a big silver longsword, which is fixed to the wall",
            "sign","A big sign with something written on it",
            "desc","A big oak-wooden desc"
               });
            
      dest_dir = ({
            PATH+"gnome18","south"          
               });
               
          }
        }

init()
{
  ::init();
  add_action("do_read","read");
}

int do_read(string arg)
{
  if (arg!="sign") return 0;
  write("Here you can: list, buy, value or sell weapons.\n");
  return 1;
}

