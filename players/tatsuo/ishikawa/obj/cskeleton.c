inherit "obj/container";
#define IPATH "/players/tatsuo/ishikawa/"

object ob,ob2,ob3,ob4,ob5;
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
ob= clone_object(IPATH+"obj/machete");
ob->add_money(347);
move_object(ob, this_object());
ob2=clone_object(IPATH+"obj/lantern");
ob3=clone_object(IPATH+"obj/rope");
ob4=clone_object(IPATH+"obj/pscroll");
ob5=clone_object(IPATH+"obj/machete");
move_object(ob2, this_object());
move_object(ob3, this_object());
move_object(ob4, this_object());
move_object(ob5, this_object());
    }
}

