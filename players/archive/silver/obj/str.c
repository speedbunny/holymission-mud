inherit "obj/soft_drink";

 object locket;

int _str()
 {
 cat("/players/silver/string");
  return 1;
 }
reset(arg) {
    ::reset(arg);
    set_name("beer");
    set_alias("drink");
    set_alias("double");
    set_short("Double beer");

 }
void init()
 {
  ::init();
  add_action("_str","string");
 }
