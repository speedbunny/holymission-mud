inherit"obj/armour";
void reset(int arg){
::reset(arg);
if (arg) return;
set_name("jacket");
set_type("armour");
set_short("A hunter's jacket");
set_long("This is the jacket of an a hunter.  You can tell by the various drops\n"+
"of blood and small pieces of fur embedded into it.\n");
set_value(200);
set_weight(4);
set_ac(2);
}
