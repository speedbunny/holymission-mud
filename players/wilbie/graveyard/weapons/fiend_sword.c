  inherit "obj/weapon";
reset(arg) {
  ::reset(arg);
if(arg) return;
   set_name("sword");
   set_alias("massive");
   set_value(1000);
   set_class(20);
   set_weight(3);
   set_short("A massive fiend's sword");
  set_long("A massive iron sword belonging to an evil Pit Fiend!!\n");
   }
