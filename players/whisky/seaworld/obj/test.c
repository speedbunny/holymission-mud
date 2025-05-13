inherit "/obj/chest";
object money;
reset(arg) { 
if (arg) return;

  money=clone_object("obj/money");
money->set_money(1000+random(2000));
move_object(money,this_object());
}
init()
{
   add_action("move_out","out");
   add_action("do_enter","enter");
   ::init();
}
void long()
{
     ::long();
     if (environment(this_player()) == this_object())
         write("The only exit is 'out'.\n");
}

int do_enter(string arg)
{
    if (!arg || !id(arg)) return 0;
/*
    if (environment(this_player()) == environment())
  */
    if (1 == 1)
    {
        write("You enter the chest.\n");
        move_object(this_object(),environment(this_player()));
        move_object(this_player(),this_object());
        return 1;
     }
    return 0;
}

int move_out()
{
    if (environment(this_player()) == this_object())
    {
        write("You leave the chest.\n");
        move_object(this_player(),environment());
        return 1;
     }
   return 0;
}
