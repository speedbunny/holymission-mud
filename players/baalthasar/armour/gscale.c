inherit "obj/armour";

reset(arg) {
::reset(arg) ;
if (arg) return 1;
set_name("scale armour");
set_type("armour");
set_ac(3);
set_value(350);
set_size(3);
set_short("scale armour");
set_long("Small plates held together with leather bonds makes up this armour. \n");
set_weight(4);
set_alias("armour");
}
