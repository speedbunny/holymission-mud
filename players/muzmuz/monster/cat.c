inherit "obj/monster";

object catclaw;

reset(arg) {
  ::reset(arg);
   if(arg) return 1;
   set_name ("cat");    
   set_alias ("cat");
   set_race ("cat");
   set_short ("A medium cat");
   set_long ("A medium cat with a soft fur. You hear it purring.\n");
  set_level (4);
 
   catclaw = clone_object ("players/muzmuz/obj/catclaw");
   move_object (catclaw,this_object());
   command ("wield claw");

return 1;

}
