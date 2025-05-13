
/* ci5 */

inherit "/obj/std_pub";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        set_light(1);
        short_desc = "In the Orcish bar";
        long_desc = BS(
        "You are standing in the Orcish pub. The whole room "+
        "is filled with tables and chairs. Gurush the bartender "+
        "is cleaning glasses and grunting musically. There is "+
        "a big wooden sign, written in blood fixed to the counter.");
        set_header("              The Orcish Pub             ");
        add_drink("elf blood",8,2,"soft",4);
        add_drink("guts soup",40,5,"soft",30);
        add_drink("assbiter",50,6,"alc",20);
        add_drink("bloody brew",150,12,"alc",80);
        add_drink("elf stew",30,5,"food",15);

        items = 
        ({
         "bottom","The bottom is covered with human bones",
         "ground","The bottom is covered with human bones",
         "walls","The walls are covered with human blood",
         "tables","Some oak wooden tables",
         "chairs","Some oak wooden chairs",
        });
        dest_dir = 
        ({
         PATH+"ci4","east",
        });
     }
}


