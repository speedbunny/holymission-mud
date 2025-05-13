inherit "/obj/chest";
object money;
reset(arg) { 
if (arg) return;

  money=clone_object("obj/money");
money->set_money(1000+random(2000));
move_object(money,this_object());
}
