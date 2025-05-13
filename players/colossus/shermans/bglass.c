/* Edit by Colossus 022294 */

#pragma strict_types

inherit "obj/thing";

void reset(int arg){
    ::reset(arg);
    if (!arg) {
	set_name("glass");
	set_weight(1);
	set_value(1000);
	set_short("Delicately shaped glass");
	set_long(
	  "The glass is shaped like a flower with a long curving neck that\n"+
	  "begins at the base and tapers off at the tip. There are several\n"+
	  "beautiful carvings on the glass itself that give it an ornamental\n"+
	  "look.\n");
    }
}
