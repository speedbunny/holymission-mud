inherit "obj/weapon";

int poison_amount;

reset(arg) {
  ::reset(arg);
    poison_amount=25;
  if(!arg) {
    set_name("dirk");
    set_alias("dagger");
    set_alt_name("inscription");
    set_read("Belongs to the collection of Ianthe.\n");
    set_short("A beautiful dirk");
    set_class(6);
    set_value(350);
    set_hit_func(this_object());
    set_weight(1);
    set_long("This dirk has a large purple stone, which is\n"
           + "@@fill_level@@. The blade is hollow, and has\n"
           + "a rune-like inscription on it.\n");
  }
  poison_amount+=5;
}

fill_level() {
  if(poison_amount>20) return "full with liquid";
  if(poison_amount>10) return "half-full";
  if(poison_amount) return "almost empty";
  return "empty";
}

weapon_hit(who) {
  if(poison_amount>0) {
    poison_amount--;
    who->add_poison(1);
  }
}
