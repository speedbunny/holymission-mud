inherit "obj/weapon";
void reset(int arg) {
::reset();
set_name("magic rod");
set_short("Magic rod");
set_alias("rod");
set_class(19);
set_type("staff");
set_weight(2);
set_value(5000);
set_long("A magic rod from the great mages of Haden. Though its ancient\n"+
	 "magic is of no use to you, it would make a great weapon still.\n");
}
