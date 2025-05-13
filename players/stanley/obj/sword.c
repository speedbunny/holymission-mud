inherit "obj/weapon";
reset(arg) {
   if(arg) return; 
   ::reset(arg);
   set_name("sword");
   set_alias("old sword");
   set_alt_name("longsword");
   set_class(18);
   set_weight(3);
   set_value(2500);
   set_short("An old sword");
   set_long("This is one of the longswords of the ancient Elves of Nargothrond.\n");
}
