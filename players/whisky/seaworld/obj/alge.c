inherit "/obj/treasure";

reset(arg) {
  if(arg) return;

  set_id("alge");
    set_alias("green alge");
    set_short("A green alge");
    set_long("A tasty looking alge.\n");
    set_value(10);
    set_weight(1);
 }
init() {
  ::init();
  add_action("eat","eat");
 }
eat(str) {
if (str!="alge") return;
  write("Mnammm Mnammm\n");
  say(this_player()->query_name()+" eats an alge.\n");
  destruct(this_object());
  return 1; }
