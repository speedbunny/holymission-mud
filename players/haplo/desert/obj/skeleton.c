inherit "obj/container";
#define IPATH "/players/haplo/ishikawa/"

reset(arg) {
    ::reset(arg);
    if (!arg) {
	set_weight(100);
      set_max_weight(15);
      set_value(35);
 set_name("skeleton");
	set_long("A skeleton of an adventurer.  It looks as if he did\n"+
	         "not die peacefully.\n");
      set_can_close(1);
    }
}

