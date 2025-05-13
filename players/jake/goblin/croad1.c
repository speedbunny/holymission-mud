inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     dest_dir = ({ "players/jake/goblin/croad","south",
                    "players/jake/goblin/croad2","north",
});
short_desc = "croad1";
long_desc = "The path continues north towards the castle.\n"
+ "The poles continue to line the path.\n"
+ "The corpses appear to be more and more decayed as you get closer towards the castle.\n";
  }
  extra_reset();
}

extra_reset()
{
object bug,weapon;
    int n,i,class,value,weight;
    string w_name,alt_name;

    i = 0;
if (!bug) {
while(i<10) {
	    i += 1;
bug=clone_object("obj/monster");
bug->set_name("bugbear");
bug->set_short("bugbear");
bug->set_long("This is a bugbear warrior.\nHe is on his way to rampage the goblin castle.\n");
bug->set_race("bugbear");
bug->set_size(3);
bug->set_level(random(20) + 1);
bug->set_hp(100);
	    n = random(3);
	    weapon = clone_object("obj/weapon");
	    if (n == 0) {
                w_name = "spear";
		class = 5;
                value = 200;
		weight = 1;
                alt_name = "knife";
	    }
	    if (n == 1) {
                w_name = "dagger";
		class = 7;
                value = 300;
		weight = 1;
                alt_name = "dagger";
	    }
	    if (n == 2) {
                w_name = "sword";
		class = 9;
                value = 500;
		weight = 2;
                alt_name = "sword";
	    }
	    weapon->set_name(w_name);
	    weapon->set_class(class);
	    weapon->set_value(value);
	    weapon->set_weight(weight);
	    weapon->set_alt_name(alt_name);
            transfer(weapon, bug);
            move_object(bug, this_object());
                 bug ->init_command("wield" + w_name);
	}
    }
}
