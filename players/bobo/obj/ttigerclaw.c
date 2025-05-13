inherit "obj/weapon";

void reset(int arg) {
  ::reset(arg);

  if(arg) return;

  set_name("claw");
  set_short("Tiger claw");
  set_long("A very sharp claw from a bengal tiger.");
  set_class(2);
  set_weight(1);
  set_value(75);
}
