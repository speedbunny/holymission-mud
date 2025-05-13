
    /*fixed by haplo 3-22-95 */

inherit "/players/whisky/genesis/std/shop";
#include "../island.h"

 
void reset(int arg) 
{
   
     ::reset ( arg );
     
     
     
     set_light( 1 );
     short_desc = "In a cavern";
     long_desc = BS(
      "You are in a big warm cave in the volcano. It's really hot but friendly "+
           "here the walls are made of black stones and there are lighted torches "+
           "fixed to the walls. You see a lot of little footsteps leading south. "+
      "There is chainmail and a big SIGN fixed on the wall here, and you see a big. "+
          "wooden desk to the north.");
              
      
      store = PATH+"astore";
      keeper = "Eferra";
      type = "armourer";
      
      items = ({
            "cave","The cave leads back to the southwest",
            "stones","Big black stones lying on the ground",
            "stone","There are a lot of stones lying around",
            "torches","They are lighted and fixed to the walls",
            "torch","There are lots of torches fixed to the walls",
            "eferra","She is sitting behind the desk, smiling at you",
            "walls","The walls are dark and made of black stones",
            "ground","The ground is full of dark stones",
            "footsteps","You see a lot of tiny gnomish footsteps, leading southwest",
          "volcano","Well you are just inside the volcano",
            "chainmail","It's a big golden chainmail, which is fixed to the wall",
            "sign","A big iron sign, maybe you should read it",
            "desc","A big oak-wooden desc"
               });
            
      dest_dir = ({
            PATH+"gnome15","southwest"          
               });
               
  }

init()
{
 ::init();
 add_action("do_read","read");
}

int do_read(string arg)
{
  if (arg!="sign") return 0;
  write("Here you can: list, buy, sell and value armours.\n");
  return 1;
}

