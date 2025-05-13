/*  This is a Blank Armour file  */

#include "/players/tamina/defs.h"

inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if(arg) return;

    set_name("felt cloak");
    set_alias("cloak");
    set_type("cloak");
    set_short("A Felt Cloak");
    set_long("A heavy-looking cloak, made of a dark, soft material.\n"+
             "There are a multitude of pin-points of light dotted on the\n"+
             "material, suggesting constellations of stars.  \n"+
             "Despite its seeming shabby appearance, a distinct aura \n"+
             "of protective power eminates from the cloak.\n");
    set_value(1500);
    set_ac(1);
    set_size(3);
    set_weight(4);

}
query_mage_wear() {return 1;}
query_monk_wear() {return 1;}
