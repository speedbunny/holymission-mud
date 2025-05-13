inherit "obj/chest";
object money;

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    money=clone_object("obj/money");
    money->set_money(4000);
    move_object(money,this_object());
}
