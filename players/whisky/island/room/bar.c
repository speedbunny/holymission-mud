
 /*fixed by haplo 3-22-95 */
/* island bar */

inherit "/obj/std_pub";
#include "../island.h"

void reset(int arg) 
{
    ::reset(arg);
    if (!arg)
    {
        set_light( 1);
        short_desc = "In the Zombie bar";
        long_desc = BS(
        "You are in a strange cavern of the volcano. "+
        "It's really hot here, but the smell of cool drinks "+
        "nearly makes you crazy. An old sailor is standing "+
       "behind a desk and maybe waiting for you to order. "+
        "There is a wooden sign hanging on the wall.");

        dest_dir = 
        ({
            PATH + "island17","out",
        });
        set_waiter("Kunigunde");
        set_header("            Kunigunde's nasty inn           \n");
        add_drink("dekilla",500,20,"alc",150);
        add_drink("lumumba",25,4,"alc",20);
        add_drink("pizza",50,4,"food",30);
        add_drink("coco milk",15,2,"soft",15);
     }
}
