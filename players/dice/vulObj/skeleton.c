inherit "obj/thing";

reset(arg) {
    ::reset(arg);
    if(!arg){
	set_name("skeleton");
	set_weight(1);
	set_value(2);
       set_alt_name("skeleton of adventurer");
	set_alias("skeleton");
	set_short("Skeleton of adventurer");
      set_long("The skeleton of an aventurer.\n"+
   "This adventurer was less lucky then you are.\n"+
   "The bones are white and hard.\n"+
   "They seem to lay here quite some time.\n"+
   "You better be more careful then he was.\n");
         set_can_get(1);
    }
}
