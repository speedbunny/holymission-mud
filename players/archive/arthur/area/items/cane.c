/* Code by Arthur for Holy Misson - 140.78.3.1 Code finished 11.4.94 */
inherit "obj/weapon";
#include "/players/arthur/defs/ardefs.h"

int dc,tpinf;

reset (arg) {
if (arg) return;
   set_name("A Cane");
   set_id("Cane");
   set_short("A Cane");
   set_alt_name("cane");
   set_long("The cane has some scratches on it from when the poor old lady\n"+
   "was trying to defend herself from being brutaly murdered.\n");
   set_class(7);
   set_value(700);
   set_weight(4);
}
drop() {
 if(TP()->query_npc()==1) {return 0;}
dc=random(100);
tpinf=TP()->query_level()+TP()->query_dex()+TP()->query_int();
if (dc>tpinf){write("The cane is to sticky to drop.\n"); return 1;}
 ::drop();
}
