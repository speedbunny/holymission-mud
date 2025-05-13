#define TP this_player()
#define TPN TP->query_name()
inherit "room/room";
object statue,sword;
int is_touched;

reset (arg) {
is_touched=0;
if (arg) return; 
set_light(3);
short_desc = "enter"; 
long_desc = "You are standing in the entrance way to the Goblin Castle.\n"
+  "This room is huge.  You see a statue against the far wall.\n"
+ "The ceiling is painted with beautiful pictures.\n"
+ "The floor is made of red stone, and has a small carpet covering it.\n";
items = ({
"carpet","A beautiful carpet.\nIt has a picture of a giant gold dragon on it",
"dragon","A huge gold dragon depicted on the carpet",
"statue","A huge statue of what appears to be a goblin king",
"floor","It is made of ruby red stones",
"ceiling","It is painted with beautiful pictures of goblin women",
});
dest_dir = ({
"players/jake/goblin/castle/c1","east",
"players/jake/goblin/castle/c25","west",
"players/jake/goblin/castle/h1","north",
"players/jake/goblin/castle/gate.c","out",
});
}

init() {
  ::init();
  add_action("clone_me_now","touch");
}

clone_me_now (str) {
if (str!="statue") return;
if (is_touched) write("The statue feels cold and lifeless.\n");
else {
statue=move_object(clone_object("obj/monster"),this_object());
statue->set_name("statue");
statue->set_short("statue");
statue->set_long("This statue looks like a goblin king.\n");
statue->set_al(100);
statue->set_aggressive(0);
statue->set_level(20);
statue->set_hp(300);
statue->add_money(500);
statue->set_race("goblin");
sword=move_object(clone_object("obj/weapon"),statue);
sword->set_name("sword");
sword->set_short("sword");
sword->set_long("This is an ordinary looking sword.\n");
sword->set_weight(3);
sword->set_wc(3);
sword->set_value(400);
write ("The statue comes to life\n");
say (TPN + " has touched the statue, bringing it to life.\n"); 
is_touched=1;
}
return 1;
}
