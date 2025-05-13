inherit "obj/container";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("chest");
  set_alias("small chest");
  set_short("A small chest");
  set_long("This is a beautifully crafted chest, buried for centuries but\n" +
	   "remarkably well-preserved by the cold.\n");
  set_max_weight(6);
  set_can_close(1);
  set_closed();
  set_can_get(1);
           }
