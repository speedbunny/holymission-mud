  inherit "obj/weapon";
reset(arg) {
  ::reset(arg);
if(arg) return;
   set_name("sword");
   set_alias("black");
   set_value(600);
   set_class(10);
   set_weight(2);
   set_short("A black bladed sword");
  set_long("A black bladed sword covered in ancient runes of evil\n");
   }
