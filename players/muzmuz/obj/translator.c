inherit "/obj/thing";
reset (arg) {
::reset (arg);
if (arg) return;
  set_name ("translator");
  set_alias("translator");
  set_short("translator");
  set_long("This is a translator to make you understand wild German\n");
  set_weight (1);
return 1;
}
init() {
 ::init(); }
