/* Underground room storage - hacked from Padrone */

#include "std.h"

clean_up() {}

string directions, shortdirections, type, colour;
int opposite, delta_x, delta_y, delta_z;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

ONE_EXIT("players/moonchild/workroom", "out",
	 "Underground room storage room",
	 "Underground room storage room.\n", 0)

find_dungeon_room(x, y, z) {
    object the_room;

    the_room = first_inventory(this_object());
    while (the_room) {
	if (the_room->match_xyz(x, y, z))
	    return the_room;
	the_room = next_inventory(the_room);
    }
}

extra_reset() {

    directions =
	({"up", "down", "north", "south", "east", "west",
	  "northwest", "northeast", "southwest", "southeast"});
    shortdirections =
	({"u", "d", "n", "s", "e", "w",
	  "nw", "ne", "sw", "se"});
    type= ({ "beautiful", "strongly-perfumed", "pale", "intense" });
    colour=({ "red", "pink", "white", "yellow" });
    opposite = ({1, 0, 3, 2, 5, 4, 9, 8, 7, 6});
    delta_x = ({0, 0, 0, 0, 1, -1, -1, 1, -1, 1});
    delta_y = ({0, 0, 1, -1, 0, 0, 1, 1, -1, -1});
    delta_z = ({1, -1, 0, 0, 0, 0, 0, 0, 0, 0});
} /* extra_reset */

query_delta_x(dir_nr) { return delta_x[dir_nr]; }
query_delta_y(dir_nr) { return delta_y[dir_nr]; }
query_delta_z(dir_nr) { return delta_z[dir_nr]; }
query_opposite(dir_nr) { return opposite[dir_nr]; }
query_directions(dir_nr) { return directions; }

dir_to_nr(str) {
    int i;

    i = 0;
    while (i < 10) {
	if (str == directions[i])
	    return i;
	i += 1;
    }
    i = 0;
    while (i < 10) {
	if (str == shortdirections[i])
	    return i;
	i += 1;
    }
    return -1;
}

make_monster(dungeon_level) {
    object m,t;
    int ml;

    if (dungeon_level > 3 && !random(4)) {
	m = clone_object("obj/monster");
        t=clone_object("players/moonchild/plants/roseseeds");
	move_object(t,m);
        t->set_no(5+random(6));
        t->set_type(type[random(4)] + " " + colour[random(4)]);
	m->set_name("giant mole");
	m->set_race("mole");
	m->set_level(10);
	m->set_male();
	m->set_wc(20);
	m->set_ac(6);
	m->set_hp(200);
	m->set_short("A giant mole");
	m->set_long("This is a giant mole, who doesn't look pleased to see you!\n");
	return m;
    }
    if(dungeon_level > 5 && !random(15)) {
	m = clone_object("players/moonchild/puzzle/worm");
	return m;
    }
    if(!random(30)) {
	m = clone_object("players/moonchild/puzzle/gnome");
	return m;
    }
    m = clone_object("obj/monster");
    ml = random(dungeon_level + 1) + 1;
    if (ml > 20)
	ml = 20;
    m->set_level(ml*3/4);
    m->set_wc(ml + 3);
    m->set_ac(ml / 3);
    m->set_hp(50 + ml*15);
    if (ml == 20) {
	m->set_name("lurker");
	m->set_short("A Lurker");
	m->set_long("The Lurker is a really nasty creature who will attack anything that he sees\n" +
	"invading his underground territory. You would be well advised to stay clear\n"
	+ "of him!\n");
	m->set_spell_mess1("Lurker pounds his attacker.");
	m->set_spell_mess2("Lurker pounds you.");
	m->set_chance(20);
	m->set_spell_dam(30);
	m->add_money(random(1001));
	m->set_aggressive(1);
    }
    else if (ml > 17) {
	m->set_name("giant snake");
	m->set_alt_name("snake");
	m->set_short("A giant snake");
	m->set_long("This snake appears to be completely at home under the ground.\n" +
	"But he also looks a really nasty creature, one to stay clear of.\n");
	m->set_dead_ob(this_object());
	m->set_spell_mess1("Snake bites its attacker.");
	m->set_spell_mess2("The snake bites you!");
	m->set_chance(15);
	m->set_spell_dam(25);
	m->set_aggressive(1);
    }
    else if (ml > 15) {
	m->set_name("slimy creature");
	m->set_short("A slimy creature");
	m->set_long("A horrible slimy creature, slithering about underground.\n");
	m->set_aggressive(1);
	t=clone_object("obj/weapon");
	move_object(t,m);
	t->set_name("slime dagger");
	t->set_alias("dagger");
	t->set_class(12);
	t->set_value(250);
	t->set_weight(2);
	t->set_short("A slime dagger");
	t->set_long("A very slimy dagger indeed.\n");
    }
    else if (ml > 10) {
	m->set_name("poison spider");
	m->set_short("A small poison spider");
	m->set_long("A small poison spider, it is weak but its bite can kill!\n");
	m->set_hp(50-ml);
	m->set_wc(20+random(ml*2));
	m->set_aggressive(1);
    }
    else if (ml > 5) {
        t=clone_object("players/moonchild/plants/roseseeds");
	move_object(t,m);
        t->set_no(3+random(4));
        t->set_type(type[random(4)] + " " + colour[random(4)]);
	m->set_name("big mole");
	m->set_short("A big mole");
	m->set_long("This is a big mole.\n");
    }
    else if (ml > 3) {
        t=clone_object("players/moonchild/plants/roseseeds");
	move_object(t,m);
        t->set_no(2+random(3));
        t->set_type(type[random(4)] + " " + colour[random(4)]);
	m->set_name("mole");
	m->set_short("A mole");
	m->set_long("This is a mole. It lives under the ground.\n");
    }
    else if (ml > 2) {
        t=clone_object("players/moonchild/plants/roseseeds");
	move_object(t,m);
        t->set_no(1+random(2));
        t->set_type(type[random(4)] + " " + colour[random(4)]);
	m->set_name("small mole");
	m->set_alias("mole");
	m->set_short("A small mole");
	m->set_long("This is a mole. It lives under the ground.\n");
    }
    else {
	m->set_name("beetle");
	m->set_short("A beetle");
	m->set_long("This is a small beetle.\n");
	m->set_hp(20+random(20));
    }
    return m;
}

monster_died(ob) {
  object skin;
  log_file("moonchild.quest", ctime(time()) + ": " +
        this_player()->query_name() + " (level " + this_player()->query_level()
        + ") (" + capitalize(this_player()->query_real_name()) + ")\n\t\t\t  "
        + "got the snake skin.\n");
  skin=clone_object("players/moonchild/puzzle/skin");
  move_object(skin,ob);
  skin->set_finder(this_player()->query_real_name());
  return 0;
}
