  inherit "obj/weapon";
reset(arg) {
  ::reset(arg);
if(arg) return;
   set_name("sword");
   set_alias("rusty sword");
   set_value(300);
   set_class(6);
   set_weight(1);
   set_short("An old rusted sword");
   set_long("A badly aged, rusty sword\n");
   }
