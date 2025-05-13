inherit "/obj/treasure";

reset(arg){

   if (arg)return;
    set_name("package");
    set_short("A brightly-wrapped package");
    set_long("A small package, beautifully wrapped with brightly colored "
"paper and ribbon. There is a small tag on it that reads \"Open Me!\"\n");
    set_value(25);
    set_weight(1);
}
init()
{
 add_action("open", "open");
}

open(arg)
{
 if (!arg) { return write("Open what?\n"),1; }
 if (arg == "package") { doboom(); return 1; }
}

doboom()
{
 write("You open the package.\n");
 write("** BOOOM **\n");
 write("The package explodes in your hands! Jokey has struck again!\n");
 say(capitalize(this_player()->query_name())+" opens a package. BOOM!\n");
 this_player()->hit_player(random(10)+1);
 destruct(this_object());
}
