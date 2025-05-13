inherit "obj/armour";

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_name("girth");
    set_alias("belt");
    set_short("A thain girth");
    set_long(
      "A heavyset belt made of strong metal links provides good protection\n\
for the wearer. The craftsmanship looks distinctly dwarven.\n");
    set_ac(1);
    set_weight(1);
    set_value(250);
    set_type("belt");
    set_size("small");
}
