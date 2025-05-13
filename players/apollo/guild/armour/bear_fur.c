
/* Gambit - Barbarian Guild */

inherit "obj/armour";

reset(arg) {
  armour::reset(arg);
  if (!arg) {

	set_name("bear fur and hide");
	set_alias("hide");
	set_type("cloak");
	set_ac(1);
	set_size(0);
	set_short("Bear fur and hide");
	set_long("Heavy fur and hide from a grizzly bear. Feels like very tough leather.\n");
	set_value(400);
	set_weight(4);
  }
}

init() {
  ::init();
  add_action("_wear","wear");
}

_wear(arg) {
  if(arg=="fur" || arg=="bear fur"){
   if(this_player()->query_guild()==11){
     return 0;
     }
   else{
   write("Only barbarians may wear such armour.\n");
   return 1;
   }
  return 0;
 }
}
