inherit "/obj/monster";
 
reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("bee");
    set_alias("honey bee");
    set_alt_name("bee");
    set_short("a honey bee");
    load_chat(8, ({
	"SUMMMM ...\n",
	"BUZZZZ ...\n",
	"A little bee flies around your head.\n" }) );
    set_long("A yellow and brown striped honey bee flying from flower to flower.\n");
    set_level(1);
    set_size(1);
    set_al(10);
    set_aggressive(0);
    move_object(clone_object("players/whisky/garden/obj/honey"),this_object());
  }
}
 
 
