inherit "room/room";
object mom,apron;
reset (arg) {
if(!mom) {
mom=clone_object("obj/monster");
transfer(mom,this_object());
mom->set_name("mother goblin");
mom->set_short("mother goblin");
mom->set_level(15);
mom->set_alias("goblin");
mom->set_long("This is a female goblin.\nShe looks pregnant.\n");
mom->load_chat(20, ({"Grrrr...I hate cooking\n"}));
apron=clone_object("obj/armour");
transfer(apron,mom);
apron->set_name("apron");
apron->set_short("apron");
apron->set_long("This is a tattered apron.\n");
apron->set_weight(1);
apron->set_class("shield");
apron->set_wc(1);
apron->set_value(100);
mom->init_command("wear apron");
}
if (arg) return;
set_light(3);
short_desc = "hut2";
long_desc =  
"This is a goblin house.\n"
+ "It looks very lived in.\n"
+  "An old table sits in the middle of the room.\n"
+"A tired looking goblin woman is cooking something in a kettle by the fireplace.\n";
items = ({
"fireplace","A stone fireplace\nA warm fire is burning in it\n",
"kettle","A kettle full of strange looking slop",
"table","An old wooden table",
});
dest_dir = ({
"players/jake/goblin/gob4","south",
"players/jake/goblin/hut2a","north",
});
}
