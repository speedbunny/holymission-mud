inherit "obj/armour";

query_auto_load() {
 return "players/ted/items/mykal_ring:";
}

short() {
  if(worn)
    return "Diamond Engegement Ring  (worn)";
 return "Diamond Engagement Ring";
}
long() {
 write("This is an exquisit diamond ring created by\n");
 write("the finest craftsmen in all of REALMS\n");
}

drop() { return 1; }

extra_look() { return "Amazon is engaged to Mykal"; }

init() {
 ::init();
}
reset(arg) {
  ::reset(arg);
set_name("ring");
set_type("amazons_ring");
set_alias("engagement ring");
set_ac(0);
}

id(str) { return str == "ring" || str == "engagement ring"; }

