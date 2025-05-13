
inherit "obj/weapon";

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("staff");
  set_class(4);
  set_value(10);
  set_weight(1);
  set_short("Staff");
  set_long(
   "A staff made of sturdy oak.\n");
}
