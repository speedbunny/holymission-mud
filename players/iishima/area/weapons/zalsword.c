inherit "obj/weapon";
void reset(int arg){
::reset(arg);
if (arg) return;
set_name("zalpur sword");
set_alias("sword");
set_class(11);
set_weight(2);
set_value(175);
set_short("A Zalpur Wizard's Sword");
set_long("This is the Zalpur Wizard's Sword. It is very sharp.\n");
}
