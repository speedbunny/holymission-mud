inherit "/obj/container";
object money;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("chest");
  set_max_weight(20);
  set_weight(2);
  set_short("A wooden chest");
  set_long("This chest is covered with sand!\n" + "It has obviosly been burried because it contains something of value.\n");
  set_value(200);
  money=clone_object("obj/money");
money->set_money(10000+random(2000));
move_object(money,this_object());
}



