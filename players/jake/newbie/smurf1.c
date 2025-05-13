inherit "room/room";
object pop,staff; 

reset (arg) {
if(!pop) {
pop=clone_object("obj/monster");
pop->set_name("poppa smurf");
pop->set_short("poppa smurf");
pop->set_alias("smurf");
pop->set_long("This is Poppa Smurf.\nHe is the over-seer of the smurf village.\n");
pop->set_level(5);
pop->set_align(2000);
pop->add_money(100);
pop->set_aggressive(0);
pop->load_chat(20,({"Have a smurfy day!\n","I'm feeling just smurfy today!\n"
}));
staff=clone_object("obj/weapon");
staff->set_id("staff");
staff->set_short("staff");
staff->set_long("This is Poppa Smurf's walking staff.\n");
staff->set_value(100);
staff->set_wc(3);
staff->set_weight(1);
move_object(staff,pop);
move_object(pop,this_object());
}
if (arg) return;
set_light(3);
short_desc = "smurf1";
long_desc = "You have entered Poppa Smurf's house.\n"
+  "It looks like a laboratory in here.\n"
+  "There is a bench-like table against the eastern wall.\n"
+  "Potions and magic books are all over the place.\n";
items =
({"table","This is Poppa Smurf's work table",
  "potions","Purple, red, green, blue, and yellow potions that Poppa Smurf has made",
"floor","A wooden floor"});
dest_dir =
({
"players/jake/newbie/gard7","north",
});
}
