inherit "obj/treasure";

int heal_value,poison_value;

reset(arg) {
  string clr;
  if(arg) return;
  clr=({ "blue", "red", "green", "yellow", "white", "pink", "black" })[random(7)];
  set_id("potion");
  set_alias(clr + " potion");
  set_weight(1);
  set_short("A " + clr + " potion");
  set_long("A " + clr + " potion. Looks like you could drink it.\n");
  set_read("It says: For healing purposes only.\n");
}

init() {
  ::init();
  add_action("drink", "drink");
}

set_heal_value(i) {
  heal_value=i;
}

set_poison_value(i) {
  poison_value=i;
}

query_value() {
  return 200 + heal_value * 20 - poison_value * 50;
}

drink(str) {
  if(!id(str)) return 0;
  write("You drink the potion and feel healed. The bottle crumbles to dust.\n");
  say(this_player()->query_name() + " drinks a potion.\n");
  this_player()->heal_self(heal_value);
  if(poison_value) {
    write("You think the potion is poisoned!\n");
    this_player()->add_poison(poison_value);
    return 1;
  }
  destruct(this_object());
  return 1;
}
