inherit "room/room";
object mouse,spider;
reset (arg) {
if(!mouse || !spider) {
mouse=clone_object("obj/monster");
spider=clone_object("obj/monster");
mouse->set_name("mouse");
mouse->set_short("mouse");
mouse->set_long("This is an ordinary mouse.\nIt loves gloomy places like basements.\n");
mouse->set_level(2);
mouse->set_align(0);
mouse->set_aggressive(0);
mouse->add_money(50);
spider->set_name("spider");
spider->set_short("spider");
spider->set_long("A creepy looking spider.\n");
spider->set_align(-5);
spider->set_aggressive(1);
spider->add_money(75);
spider->set_level(4);
move_object(mouse,this_object());
move_object(spider,this_object());
}
if (arg) return;
set_light(0);
short_desc = "base";
long_desc = "Grouchy Smurf's basement.\n"
+  "It is very gloomy and eerie down here.\n"
+  "The place is empty except for a cobweb that hangs from the ceiling.\n"
;
items = ({"cobweb","An ordinary looking spider-web"});
dest_dir = 
({"players/jake/newbie/smurfhouse","up"});
}
