inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("dwarf");
 set_short("sturdy dwarf");
 set_level(random(3)+2);
 set_hp(35);
 set_al(-60);
}
