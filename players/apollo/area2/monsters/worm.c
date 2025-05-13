
inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if (!arg) {

    set_name("worm");
    set_alias("glow worm");
    set_short("A little glow worm");
    set_long("A little green glow worm.\n");
    set_level(1);
    set_size(1);
    set_al(10);
    set_wc(1);
    
    move_object(clone_object("obj/torch"),
	this_object());
  }

}
