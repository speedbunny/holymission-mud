  inherit "obj/weapon";
reset(arg) {
  ::reset(arg);
if(arg) return;
   set_name("hammer");
   set_alias("steel hammer");
   set_value(800);
   set_class(15);
   set_weight(2);
   set_short("A huge hammer of cold steel");
   set_long("A huge looking hammer made out of fine steel.\n");
   }
