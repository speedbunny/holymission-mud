inherit"/obj/monster";
reset (arg) {
  ::reset(arg);
if (arg) return 1;
set_name("termite");
set_short("Termite");
set_long("These little guys love eating wood!\n");
set_level(8);
return 1;
}

