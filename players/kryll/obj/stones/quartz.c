inherit "/std/object";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("quartz");
  set_short("quartz");
  set_long("A pretty quartz. Too bad it's worthless.\n");
  set_alias("gem");
  set_size(1);
  set_weight(1);
  set_material(GEMSTONE);
  set_value(random(10) + 1);
}
