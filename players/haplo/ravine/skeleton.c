inherit "obj/container";
#define IPATH "/players/tatsuo/ishikawa/"

object ob;
reset(arg) {
    ::reset(arg);
    if (!arg) {
	set_weight(100);
      set_max_weight(15);
      set_value(35);
 set_name("skeleton");
	set_long("A skeleton of an adventurer.  It looks as if he did\n"+
                 "not make it to the top of the cliff before he let go!\n");
      set_can_close(1);
  ob= clone_object(IPATH+"obj/machete");
ob->add_money(347);
move_object(ob, this_object());
    }
}

