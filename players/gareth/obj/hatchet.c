inherit "obj/weapon";

reset(arg) 
{
  ::reset(arg);
    if(!arg) {
    set_name("black hatchet");
    set_alias("hatchet");
    set_short("A black hatchet");
    set_long("The shaft is made of fine oak and the the head of the"+
    " keen blade is made of polished adamantine.\n");
    set_class(16);
    set_weight(4);
    set_value(200);
    }
}





