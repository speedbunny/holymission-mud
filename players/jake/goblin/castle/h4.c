inherit "room/room";
object gob,vest;
reset (arg) {
smell = "The stench of alcohol makes you sick to your stomach";
if (!gob) {
gob=clone_object("obj/monster");
transfer(gob,this_object());
gob->set_name("goblin");
gob->set_short("drunken goblin");
gob->set_long("This goblin reeks of alchohol.  He looks real intoxicated.\n"); 
gob->set_level(10);
gob->load_chat(20,({"Argsh lishk blacshk.\n"}));
gob->set_size(3);
gob->set_race("goblin");
gob->set_al(100);
gob->set_aggressive(0);
vest=clone_object("obj/armour");
transfer(vest,gob);
vest->set_name("vest");
vest->set_short("leather vest");
vest->set_long("A tattered looking leather vest.\n");
vest->set_ac(1);
vest->set_type("vest");
vest->set_size(3);
vest->set_value(200);
vest->set_weight(2);
gob->init_command("wear leather vest");
}
if (arg) return;
set_light(2);
short_desc = "center hallway  drunken goblin";
long_desc = 
  "The north end of the grand hallway.\n"
+ "You can hear sounds of clanging metal and numerous voices coming from the east.\n" + "A rather large portrait of a goblin is on the west wall.\n"
+ "There is a familiar smell in the air.\n";
items = ({
 "floor","It is made of red stone",
 "ceiling","It is made of white stone",
 "wall","The walls are of grey stone, with a picture on the west wall",
 "picture","A large portrait of the goblin king and his queen",
});
dest_dir = ({
 "players/jake/goblin/castle/h3","south",
 "players/jake/goblin/castle/h5","east", 
 "players/jake/goblin/castle/c13","north",
}); 
}
