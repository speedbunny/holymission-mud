/* 
  Just a test armour (invincibility), so I can use novives for fighting
  without being killed.
*/

#define ux "unix"

inherit "obj/armour";

init() {

	::init();

	set_id(ux);
	set_name(ux);
	set_short(ux);
	set_value(0);
	set_weight(0);
	set_ac(1000000);
	set_long(ux);
	set_type(ux);
	return;
}
