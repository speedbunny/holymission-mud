inherit "obj/weapon";
reset(arg) {
::reset(arg);
if(!arg){
set_name("dagger");
set_short("Dagger");
set_long("A very sharp, light weight dagger.\n");
set_class(5);
set_weight(1);
set_value(250);
}
}
