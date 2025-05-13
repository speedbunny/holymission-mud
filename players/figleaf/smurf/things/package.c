inherit "/obj/treasure";

void reset(int arg){

  ::reset(arg);
  if (arg)return;
    set_name("package");
    set_short("A package from Jokey smurf");
    set_long("A small package, beautifully wrapped with brightly colored "
"paper and ribbon. There is a small tag on it that reads \"Open Me!\"\n");
    set_value(21);
    set_weight(1);
}
init()
{
 add_action("open", "open");
}

int open(string str) {
 if (str !="package") {
 notify_fail("Open what?\n");
 return 0;
 }
 write("You open the package.\n");
 write("** BOOOM **\n");
 write("The package explodes in your hands! Jokey has struck again!\n");
 say(capitalize(this_player()->query_name())+" opens a package which explodes "
"in "+this_player()->query_possessive()+" face.\n");
 say("That had to hurt!\n");
 this_player()->hit_player(random(10)+1);
 destruct(this_object());
 return 1;
}
