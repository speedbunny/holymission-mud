inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("herbs");
  set_short("Some herbs");
  set_long("Some strange herbs\n");
  set_value(2);
  set_weight(1);
}
init() {
 ::init();
 add_action("eat","eat");
 
 }
eat(str) {
  if (str!="herbs")  return; 
  write("Baaaa they are tasting awful.\n");
  say(this_player()->query_name()+" eats some herbs.\n");
  this_player()->frog_curse(0);
  this_player()->heal_self(2);
  destruct(this_object());
 return 1;
 }

