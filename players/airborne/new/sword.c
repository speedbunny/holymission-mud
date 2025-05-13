inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  set_name("sword");
  set_short("A small sword");
  set_long("This is a small sword. It looks quite effective, but\n"
	+ "you could problably get a better weapon if you tried.\n");
  set_class(5);
  set_weight(1);
}

drop() {
  tell_object(environment(), "The sword suddently falls to pieces.\n");
  destruct(this_object());
  return 1;
}
