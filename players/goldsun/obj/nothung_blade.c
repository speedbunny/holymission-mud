inherit "/obj/thing";

void reset(int arg){
 ::reset(arg);

 if (arg) return;
  set_name("blade");
  set_alt_name("goldsun_nothung_blade_12903");
  set_short("An old blade");
  set_long("An old rusty blade. It is made of excelent steel. Maybe\n"+
	   "you could find the hadle.\n");
  set_value(100);
  set_weight(1);
}
