#define CPL capitalize(environment(this_object())->query_name())
inherit "/obj/weapon.c";
int x;
reset (arg)
{
if (arg) return;
::reset(arg);
set_name("sword");
set_short("sword of death");
set_alias("deathsword");
set_class(20);
set_weight(3);
set_value(4500);
set_long("A sword of heavy destruction\n");
}
weapon_hit() {
write("Hit");
x += 1;
if (x >= 5) {
x = 0;
tell_room(environment(environment(this_object())), CPL +"'s sword spits fire!\n"
);
}
}
