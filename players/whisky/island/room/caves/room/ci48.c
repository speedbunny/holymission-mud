
/* ci48 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (filter_live(this_object()) < 6)
     {
        CM("troll");
        CM("troll");
        CM("troll");
        CM("warrior");
        CM("shaman");
        CM("shaman");
     }
     if (!present("elder orc",this_object()))
         CM("master");
     if (!present("chieftrain",this_object()))
         CM("chieftrain");
     if (!present("chiefshaman",this_object()))
         CM("chiefshaman");

     if (flag == 0)
     {
        set_light(1);
        short_desc = "In a big hall";
        long_desc = BS(
        "You have entered a big hall, the end of the secret orc "+
        "caves. You see a table and a wooden chair standing at "+
        "the wall, where a huge orc is grinning at you as you "+
        "enter. Beside the table is a huge bed and a campfire."+
        " The only way back is to the south."); 

        items = 
        ({
         "bottom","The bottom is covered with blood",
         "table","A big wooden table",
         "chair","A big wooden chair",
         "bed","A big, dirty bed",
         "campfire","A campfire to have it warm during the winternights", 
         "ground","The bottom is covered with blood",
         "walls","The walls are made of stone",
         "spots","You see big spots of human blood",
         "blood","You see big spots of human blood", 
         "moss","Green wet moss",
        });
      }
     dest_dir = 
     ({
       PATH+"ci47","south",
     });
}


