inherit "obj/armour";
mixed worn;
string real_title;
reset(arg) {
  worn=0;
  if(arg) return 0;
  set_name("silver ring");
  set_short("a cold silver ring");
  set_long("A silver ring that perfectly matches you attire.\n")+
  set_type("ring");
}
