inherit "obj/armour";

reset(arg) {
::reset(arg) ;
if (arg) return 1;

set_name("shirt");
set_type("cloak");
set_weight(1);
set_value(25);
set_ac(0);
set_short("A West Point T-shirt");
set_size(3);
set_long("On the front of the shirt, it reads:  I graduated from \n"
+"West Point, and all I got was this lousy T-shirt. \n");
}
