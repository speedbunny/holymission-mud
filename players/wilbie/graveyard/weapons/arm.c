  inherit "obj/weapon";
reset(arg) {
  ::reset(arg);
if(arg) return;
   set_name("bone");
   set_alias("arm");
   set_value(2);
   set_class(2);
   set_weight(3);
   set_short("An old arm bone");
set_long("Horribly enough, you notice this arm bone was removed from it's "+
         "ownder somewhat recently!\n");
   }
