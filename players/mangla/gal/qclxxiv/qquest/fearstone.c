inherit "obj/treasure";

id(arg) { return (::id(arg) || arg=="black stone"); }

reset(arg) {
  if(arg) return;
    set_short("A black stone");
    set_long("A black stone. It shimmers dully and feels magic.\n");
	set_id("stone");
	set_alias("qfearstone"); /* just recognized by THE qdragon */
    set_value(0);
  	set_weight(0);
}
