inherit "obj/thing";

reset(arg) {
  ::reset(arg);
  if(!arg) {

    set_name("sandcastle");
    set_alias("sandcastle");
    set_short("This sandcastle is a magnificent structure!");
    set_long("This sandcastle stands tall and proud, you doubt anything could 'destroy' it.\n");
    set_can_get(0);
     }
}


