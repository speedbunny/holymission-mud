inherit "room/room";
object snake,fang;
int i;
reset (arg) {
if (!snake) {
for (i=0;i<5;i++) {
snake=move_object(clone_object("obj/monster"),this_object());
snake->set_name("pit viper");
snake->set_short("pit viper");
snake->set_long("This is a poisonous pit viper.\n");
snake->set_level(10);
snake->set_hp(100);
snake->set_aggressive(1);
snake->set_alias("viper");
snake->set_align(-1000);
fang=move_object(clone_object("obj/weapon"),snake);
fang->set_name("fangs");
fang->set_short("fangs");
fang->set_long("snake fangs");
fang->set_weight(1);
fang->set_wc(2);
snake->init_command("wield fangs");
}
if (arg) return;
set_light(3);
short_desc = "croad3a";
long_desc = "As you make your way through the shrubbery, \n"
+ "You suddenly lose your footing and fall into some sort of a pit.\n"
+ "There are big walls made of dirt surrounding you.\n"
+  "Maybe you should try climbing them?\n";
items = ({
"wall","walls made of dirt.\nmaybe you should try climbing them?",
});
}
}
init() {
::init ();
add_action("climb");add_verb("climb");
}
climb (str) {
if (str !="wall") return;
call_other(this_player(),"move_player","climbs out#/players/jake/goblin/croad3");
return 1;
}
