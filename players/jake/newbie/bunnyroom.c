inherit "room/room";
object bunny;
int i;
reset (arg) {
if(!bunny) {
for (i=0;i<10;i++){
bunny=clone_object("obj/monster");
bunny->set_name("bunny-rabbit");
bunny->set_short("bunny-rabbit");
bunny->set_alt_name("bunny");
bunny->set_alias("rabbit");
bunny->set_level(3);
bunny->set_align(500);
bunny->set_aggressive(0);
move_object(bunny,this_object());
}}
if (arg) return;
set_light(3);
short_desc = "bunnyroom";
long_desc = "The field of bunnies.\n"
+  "These rabbits like to sit out here all day and munch on the grass.\n"
+  "Jake requests that you kill them before they destroy his garden!\n";
items = ({"grass","almost dead-looking grass.\nDamn rabbits are killin' it!"});
dest_dir = ({
"players/jake/newbie/gard6","west",
});
}
