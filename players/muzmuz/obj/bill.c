inherit "/obj/thing";
reset (arg) {
::reset (arg);
if(arg) return ;
  set_name ("bill");
  set_alias ("bill");
set_short ("phone bill");
  set_long ("This is a phone bill over 3000 coins\n");
}
init() {
::init();
}
