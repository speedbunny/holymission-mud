inherit "obj/container";

reset(arg) {
object key;

  ::reset(arg);
  if(!arg) {
    set_name("chest");
    set_short("A very large chest");
    set_long("This is a rather large chest made of wood that will\n"
           + "still be here when you are long gone.\n");
    set_max_weight(10);
    set_can_close(1);
    set_closed(1);
    set_can_get(0);
  }
  if(!present("key",this_object())) {
    key=clone_object("players/cashimor/objects/key");
    move_object(key,this_object());
  }
}
