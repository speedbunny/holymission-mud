inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("herbs");
  set_short("Some herbs");
  set_long("Some island herbs\n");
  set_value(2);
  set_weight(0);
}
init() {
 ::init();
 add_action("eat","eat");
 
 }
eat(str) {
  if (str!="herbs")  return; 
  write("Baaaa they are tasting awful.\n");
  say(this_player()->query_name()+" eats some herbs.\n");
  this_player()->eat_food(10);
  destruct(this_object());
 return 1;
 }

