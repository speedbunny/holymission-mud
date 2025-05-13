/* Code by Arthur for Holy Mission-140.78.3.1 finished 11.4.94 */
inherit "obj/weapon";
#include "/players/arthur/defs/arweap.h"

long() {
write("The sword has a black hilt, the blade is gold with a small\n"+
   "insignia writing 'Owner: "+own_name+"'\n"+el+"\n");return 1;}

reset (arg) {
if (arg) return;
   set_name("Sword");
   set_id("Sharp Sword");
   set_short("Sharp Sword");
   set_alt_name("sword");
   set_class(20);/* High Wc due to the weapon being breakable!*/
   set_type(3);
   set_value(5000);
   set_weight(10);
}

