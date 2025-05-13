inherit "obj/weapon";
reset (arg) {
  ::reset();
set_name("teeth");
set_class(1000000);
set_weight(1);
set_value(10000);
set_short("Vampire teeth");
set_long("Very long and sharp teeth.\n");
}

init() {
  ::init();
  if(this_player() && this_player()==environment() &&
     !this_player()->query_wizard()) destruct(this_object());
}

drop() {
return(1);
}
