inherit "obj/armour";
 
object obj;
int i;
 
reset(arg) {
::reset(arg);
if (arg) return;
 set_name("hat");
 set_alias("browniehat");
 set_short("A brownie's hat");
 set_long("A brownie's hat, maybe it has some magical feature.\n");
 set_ac(1);
 set_size(2);
 set_value(500);
 set_weight(1);
 set_type("helmet");
}
 
init(){
  add_action("owner","magic");
  add_action("owner","use");
 ::init();
}
 
 
owner(str) {
  if(!id(str)) return;
  write("Don't you think you should give it back to the owner, instead"+
   " of using it.\n");
  return 1;
}
 
