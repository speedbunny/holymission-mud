inherit "obj/monster";

reset(arg) {
::reset(arg);
if(!arg) {
set_name("Preacherman");
set_alias("man");
set_long("nothing special");
set_al(0);
set_aggressive(0);
set_level(40);
set_wc(50);
set_ep(1);
set_ac(10);
set_hp(100000);
}
  }
