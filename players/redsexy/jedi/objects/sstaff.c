inherit "obj/weapon";
void reset(int arg){
::reset(arg);
if (arg) return;
set_name("staff");
set_alias("staff");
set_class(5);
set_weight(1);
set_value(400);
set_short("The Wooden Staff of a Sandperson");
set_long("This Staff is carried by the Sanpeople to help them negotiate the\n" +
          "the rough desert terrain.  It also comes in handy as a weapon");
}
