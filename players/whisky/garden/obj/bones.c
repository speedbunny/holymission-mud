inherit "obj/thing";

reset(arg) {
  if (!arg) {
    set_name("bones");
    set_alias("bone");
    set_short("bones from an adventurer");
    set_long("This are some bones of an adventurer, who died at this place.\n"+
	     "Feed you favourite pet with them ...\n");
    set_value(40);
    set_can_get(1);
  }
} 
 init() {
   call_out("dest",1800);
   ::init();
  }
  dest() {
   destruct(this_object());
   return 1;
  }

