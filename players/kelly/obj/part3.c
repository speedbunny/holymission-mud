inherit "/obj/treasure";
 
reset(arg) {
if (arg) return;
 set_alias("part");
 set_id("amulet");
 set_short("A part of an amulet");
 set_long("This is a part of a broken amulet. It shows a part a bright "+
   "sword.\n");
 set_value(5);
 set_weight(1);
}
 
init() {
  add_action("turn","turn");
}
 
turn(str) {
  if(!id(str)) return;
  write("as you turn the amulet you see a Greek beta.\n");
  return 1;
}
