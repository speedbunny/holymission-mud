inherit "room/room";
object gob,sword;

int i;

reset(arg) {

if(!gob) {
 for (i=0;i<2;i++) {
gob=clone_object("/obj/monster");
transfer (gob,this_object());
gob->set_name("goblin guard");
gob->set_short("goblin guard");
gob->set_long("This is a goblin guard.\nHe roams the castle looking for intruders.\n");
gob->set_level(20);
gob->set_hp(1000);
gob->set_al(0);
gob->set_aggressive(1);
gob->set_alias("goblin");
gob->set_alt_name("guard");
sword=clone_object("obj/weapon");
transfer(sword,gob);
sword->set_name("sword");
sword->set_short("sword"); 
sword->set_wc(2);
sword->set_weight(2);
sword->set_value(1000);
gob->init_command("wield sword");
}
if (arg) return;
set_light(3);
short_desc = "2 goblin hall";
long_desc = 
"The hall goes north and south.\n"
+"There is a bright blue carpet covering the red stone floor\nthat extends off into the distance.\n"
+ "A small window to your east.\n";
items = ({
"floor","It is made of bright, ruby red stone",
"wall","They are made of grey stones.  There is nothing on them",
"ceiling","The ceiling is made of pearly white stones",
"window","You can only see trees that surround the castle",
"carpet","A bright blue carpet that extends north",
});
dest_dir = ({
"players/jake/goblin/castle/c4","south",
"players/jake/goblin/castle/c6","north",
});
}
}
