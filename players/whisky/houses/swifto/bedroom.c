
/* bedroom */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     if (flag == 0)
     {
         set_light(1);
         short_desc = "In the bedroom of Swifto's house";
         long_desc = BS(
         "You have entered the bedroom of Swifto's house. "+
         "It's a large room with a big, french, king-sized "+
         "bed on the western wall. The bed is covered with "+
         "soft linen. On the eastern wall is a big fireplace. "+
         "There is a large mirror fixed to the ceiling. The "+
         "room is dimly lit by a large candelier and the northern "+
         "wall is made of glass with a look to the beautiful lake.");
        
         
        items =
        ({
         "walls","The walls are painted in white",
         "northern wall",
         "You can see the beautiful lake through the glass",
         "floor","The floor is hardwood",
         "ceiling","There is a big mirror fixed to the ceiling",
         "bell","A little silver bell, you can ring it",
         "chadelier","The large golden chadelier lits the room",
         "pillows","Soft blue pillows",
         "pillow","Soft blue pillows",
         "bed","The bed is covered with soft linen", 
         "mirror","There is a large mirror fixed to the ceiling",
        });

         dest_dir =
         ({
           PATH+"entrance","down",
           PATH+"bathroom","north",
           PATH+"bed","bed",
         }); 
     }
   }



    

