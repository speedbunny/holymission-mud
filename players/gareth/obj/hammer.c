inherit "obj/weapon";

reset(arg) 
{
  ::reset(arg);
    if(!arg) {
    set_name("hammer");
    set_alt_name("hammer");
    set_alias("war hammer");
    set_short("A war hammer");
    set_long("A large extra heavy war hammer.  It's shaft is made of\n"+
    " polished redwood. The head of the hammer is forged of adamantine,\n");
    set_class(18);
    set_weight(4);
    set_value(1500);
    }
}





