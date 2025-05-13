#define TP this_player()
#define TPN TP->query_name()
inherit "room/room";
object gu,sl,bo;
int i;
reset (arg) {
if (!gu) {
for (i=0;i<2;i++) {
gu=clone_object("obj/monster");
transfer(gu,this_object());
gu->set_name("guardian");
gu->set_short("guardian");
gu->set_long("The Goblin Castle guard.\nHe will let you in, but gathering from the snarl on his face,\nhe isn't very happy about it.\n");
gu->set_level(15);
gu->set_align(15);
gu->set_race("goblin");
gu->set_size(3);
gu->add_money(1000);
sl=clone_object("obj/weapon");
transfer(sl,gu);
sl->set_name("guardian slayer");
sl->set_short("guardian slayer");
sl->set_alias("slayer");
sl->set_long("This is the guardian slayer.\nIt is a worthy weapon.\n");
sl->set_wc(18);
sl->set_value(8000);
sl->set_weight(5);
sl->set_hit_func(this_object());
gu->init_command("wield guardian slayer");
bo=clone_object("obj/armour");
transfer(bo,gu);
bo->set_name("body plate");
bo->set_short("body plate");
bo->set_long("A black and red metal armour plate.");
bo->set_ac(3);
bo->set_weight(5);
bo->set_value(5000);
bo->set_size(3);
bo->set_alias("plate");
gu->init_command("wear body plate");
}
if (arg) return;
set_light(3);
short_desc = "Gateway to the castle";
long_desc = 
"You are standing before a massive castle.\n"
+  "The castle walls extends to the east and west, and looking up, you can barely\n"
+  "make out the top of the walls.  Towers stand off to the east and west, and\n"
+  "vines grow up the castle walls.  The large iron portcullis is raised allowing\n"
+  "you to 'enter' the 'castle' if you desire.\n";
items = ({ 
"portcullis","A large iron portcullis.  It is raised",
"towers","Tall guard towers that rise from the corners of the castle",
"vines","Vines growing along the castle walls",
});
dest_dir = ({
"players/jake/goblin/croad5","south",
});
}
}
weapon_hit(ob) {
if (ob->query_race()=="human");
write ("The blade slices cleanly through it's opponent.\n");
return 5;
}
init() {
::init();
add_action ("enter","enter");
}
enter() {
  move_object(TP,"players/jake/goblin/castle/enter");
write ("You enter the castle.\n");
say(TPN + " enters into the castle.\n");
return 1;
}
