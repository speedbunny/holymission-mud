inherit "obj/weapon";
void reset(int arg){
::reset(arg);
if (arg) return;
set_name("zalpur staff");
set_alias("staff");
set_class(3);
set_weight(1);
set_value(75);
set_short("A Zalpur Hunter's Staff");
set_long("This is the Zalur Hunter's Staff.  It is covered with rubies and emeralds.\n");
}
