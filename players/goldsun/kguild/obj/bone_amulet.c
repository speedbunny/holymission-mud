inherit "/obj/armour";

reset(arg){
 ::reset(arg);

if (arg) return;
set_name("bone amulet");
set_type("amulet");
set_ac(1);
set_short("A bone amulet");
set_long("A magic bone amulet.\n");
set_size(0);
set_value(100);
set_weight(1);
}
