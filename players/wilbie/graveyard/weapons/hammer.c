  inherit "obj/weapon";
reset(arg) {
  ::reset(arg);
if(arg) return;
   set_name("hammer");
   set_alias("steel hammer");
   set_value(300);
   set_class(6);
   set_weight(1);
   set_short("A sturdy hammer of cold steel");
   set_long("A sturdy looking hammer made out of fine steel.\n");
   }
