  inherit "obj/weapon";
reset(arg) {
  ::reset(arg);
if(arg) return;
   set_name("skull");
   set_alias("stick");
   set_value(2);
   set_class(2);
   set_weight(1);
   set_short("An old skull on a stick");
set_long("An old stick has been violently rammed into this skull, forming "+
         "a rather grotesque club.\n");
   }
