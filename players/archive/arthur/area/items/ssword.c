/* Code by Arthur for Holy Mission-140.78.3.1 finished 11.11.94 */
inherit "obj/weapon";
#include "/players/arthur/defs/arweap.h"

long() {
write("This short sword has a very sharp blade that can be used to slice\n"+
   "through things very easily. On the hilt there is an insignia writing\n"+ 
   "'Owner: "+own_name+"'\n"+el+"\n");return 1;}

reset (arg) {
if (arg) return;
   set_name("Short Sword");
   set_id("Short Sword");
   set_short("Short Sword");
   set_alt_name("sword");
   set_class(15);/* High Wc due to the weapon being breakable!*/
   set_value(3000);
   set_weight(10);
}

