  inherit "obj/weapon";
reset(arg) {
  ::reset(arg);
if(arg) return;
   set_name("pickaxe");
   set_alias("pick");
   set_value(300);
    set_class(7);
   set_weight(3);
   set_short("A small pickaxe");
   set_long("The perferred digging tool of the kobold, nice weapon too.\n");
   }
