  inherit "obj/weapon";
reset(arg) {
  ::reset(arg);
if(arg) return;
   set_name("sword");
   set_alias("rusty sword");
   set_value(300);
   set_class(6);
   set_weight(3);
   set_short("A twisted rusty sword");
   set_long("A short sword that looks like it was used one time too many\n");
   }
