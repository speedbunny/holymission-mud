inherit "obj/container";

reset(arg) {
object ob;

  ::reset(arg);
  if (!arg) {
    set_name("rucksack");
    set_read("What will a woodchuck do if a woodchuck chucks some wood.\n");
    set_max_weight(15);
    set_short("A rucksack");
    set_long("What will a woodchuck do if a woodchuck chucks some wood.\n");
    set_value(40);
    set_weight(1);
    ob = clone_object("obj/money");
    ob->set_money(2000);
    move_object(ob,this_object());
  }
}
