

/* Tegerl, 24.3.1995 */
/* obj/barrel */


inherit "obj/container";
object money;
void reset(int arg) 
{
::reset(arg);

if (!arg) {

set_name("pillow");
set_weight(2);
set_max_weight(2);
set_long("It seems to be an ordinary pillow.\n");
set_value(0);
set_can_get(0);
money=clone_object("obj/money");
money->set_money(20000);
move_object(money,this_object());
}
}
