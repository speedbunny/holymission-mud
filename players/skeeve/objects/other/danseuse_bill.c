inherit "/obj/treasure";

int coins;
string name;
/*
extra_look() { return ((environment(this_object())->id(name)) && (coins != 0)) ?
     (capitalize(environment()->query_pronoun())
    + " had lost "+coins+" coins to the danseuse") : "" ;}
*/

set_bill(c,n)    {
  coins=c;name=n;
  set_read("It's a bill over "+coins+" coins for "+ name +"\n");
}

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("danseuse bill");
    set_alias("bill");
    set_alt_name("danseuse_bill");
    set_read("It's a unused bill!\n");
    set_short("A bill");
    set_long("A bill from the danseuse. There is something written on it.\n");
    set_value(20);
    set_weight(0);
    coins=0;
    name=0;
    set_info("Don't loose it! It's protect you against the danseuse.\n");
  } else {
    if (environment(this_object()) != this_player())
      destruct(this_object());
} }
