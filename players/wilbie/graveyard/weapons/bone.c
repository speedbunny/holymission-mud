  inherit "obj/weapon";
reset(arg) {
  ::reset(arg);
if(arg) return;
   set_name("bone");
   set_alias("leg");
   set_value(2);
   set_class(2);
   set_weight(1);
   set_short("An old leg bone");
set_long("You shudder as you think of how the owner lost this bone!!\n");
   }
