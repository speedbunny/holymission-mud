inherit "room/room";
object gob,cross;
reset (arg) {
if (!gob) {
gob=clone_object("obj/monster");
transfer(gob,this_object());
gob->set_name("goblin preacher");
gob->set_short("goblin preacher");
gob->set_level(20);
gob->set_hp(1000);
gob->set_long("This is the goblin preacher.\nHe wanders around preaching the word of Garbriel, the goblin god.\n");
gob->set_alt_name("preacher");
gob->set_alias("goblin");
gob->set_align(1000);
gob->add_money(500);
gob->set_move_reset();
cross=clone_object("obj/treasure");
transfer(cross,gob);
cross->set_id("goblin cross");
cross->set_short("goblin cross");
cross->set_long("This is the goblin cross.\nThere is an inscription on it.\n");
cross->set_read("He who owns this must devote himself to Garbriel.\n");
cross->set_alt_name("cross");
cross->set_weight(2);
cross->set_value(500);
}
if (arg) return;
set_light (3);
short_desc = "croad3";  
long_desc = "The main path proceeds east from here.\n"
+  "There is a thick growth of trees preventing passage to the north.\n"
+  "A slight path to the west.\n";
items =({
"trees","A growth of trees much too thick to walk through\n",
"path","A slight path to the west.\nWhy not *go* on it?",
});
dest_dir = ({
"players/jake/goblin/croad4","east",
"players/jake/goblin/croad2","south",
});
}
init () {
::init (); 
add_action ("west"); add_verb("west");
}
west(str) {
if (str !="west") return;
call_other(this_player(),"move_player","leaves east#/players/jake/goblin/croad3a");
return 1;
}
