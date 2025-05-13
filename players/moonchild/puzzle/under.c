/* Hacked from Padrone's dungeon - Moonchild */

object dungeon;
int x, y, z, desc_no;
object exits;
status can_make_monsters;
int last_init_time;

reset(arg) {
    if (!arg) {
	desc_no=random(3);
	exits = allocate(10);
	can_make_monsters=1;
    }
    if(!random(3)) can_make_monsters=1;
}

reset2() {
    move_object(this_object(), "players/moonchild/puzzle/undermon");
    dungeon = environment(this_object());
}

init() {
    int no;
    object monst;
    add_action("up", "up");
    add_action("down", "down");
    add_action("north", "north");
    add_action("south", "south");
    add_action("east", "east");
    add_action("west", "west");
    add_action("northwest", "northwest");
    add_action("northeast", "northeast");
    add_action("southwest", "southwest");
    add_action("southeast", "southeast");
    add_action("dig", "dig");
    add_action("roomstat", "roomstat");
    if (can_make_monsters) {
	can_make_monsters = 0;
	no=0;
	while (!random(2) && no<30) {
	    move_object(monst=dungeon->make_monster(-z*2), this_object());
	    no+=monst->query_level();
	}
    }
    if(interactive(this_player())) last_init_time=time();
}

set_coordinates(x1, y1, z1) { x = x1; y = y1; z = z1; }
match_xyz(x1, y1, z1) { return x == x1 && y == y1 && z == z1; }
query_exits() { return exits; }

up() { return do_move("up", 0); }
down() { return do_move("down", 1); }
north() { return do_move("north", 2); }
south() { return do_move("south", 3); }
east() { return do_move("east", 4); }
west() { return do_move("west", 5); }
northwest() { return do_move("northwest", 6); }
northeast() { return do_move("northeast", 7); }
southwest() { return do_move("southwest", 8); }
southeast() { return do_move("southeast", 9); }

dig(str) {
    int dir_nr, x1, y1, z1, tmp;
    object other_room;

    if (!str) {
	write("Yes, but in what direction do you want to dig?\n");
	return 1;
    }
    dir_nr = dungeon->dir_to_nr(str);
    if (dir_nr == -1) {
	write("What a strange direction!\n");
	return 1;
    }
    if (exits[dir_nr]) {
	write("But there is already an opening leading " + str + "!\n");
	return 1;
    }
    x1 = x + dungeon->query_delta_x(dir_nr);
    y1 = y + dungeon->query_delta_y(dir_nr);
    z1 = z + dungeon->query_delta_z(dir_nr);
    tmp = z1;
    if(tmp<-5) tmp=-10-tmp;
    if (z1 > 0 || x1 < (tmp-3) || x1 > (-tmp+3) || y1 < (tmp-3) || y1> (-tmp+3)) {
	write("The ground here is far too hard for you to be able to dig through it.\n");
	return 1;
    }
    str = (dungeon->query_directions())[dir_nr];
    write("You dig a hole leading " + str + ".\n");
    say(this_player()->query_name() + " digs a hole leading " + str + ".\n");
    other_room = dungeon->find_dungeon_room(x1, y1, z1);
    if (!other_room) {
	other_room = clone_object("players/moonchild/puzzle/under");
	other_room->reset2();
	other_room->set_coordinates(x1, y1, z1);
    }
    other_room->set_exit(dungeon->query_opposite(dir_nr), this_object());
    set_exit(dir_nr, other_room);
    return 1;
}

set_exit(dir_nr, room) {
    if (exits[dir_nr])
	write("WARNING! This exit was already used in the other room.\n");
    exits[dir_nr] = room;
}

roomstat() {
    int i;

    if (!this_player()->query_wizard())
	return 0;

    write("Room coordinates: (x, y, z) = (" + x + ", " + y + ", " + z + ")\n");
    i = 0;
    while (i < 10) {
	write("  Exit " + i + ": ");
	write(exits[i]);
	write("\n");
	i += 1;
    }
    return 1;
}

do_move(dirstring, nr) {
    if (!exits[nr])
	return 0;
    this_player()->move_player(dirstring, exits[nr]);
    return 1;
}

short() { return "Underground"; }

long(str) {
    int i;
    object the_array;
    status notfirst;

/*  if (set_light(0) == 0) {
	write("It is dark.\n");
	return;
    }*/
    if(!desc_no)
	write("You are in the soft peaty earth underneath the moor.\n");
    else if(desc_no==1)
	write("You are digging underground in the dirty earth.\n");
    else write("You are underground, digging in soft peaty earth.\n");
    if(z<-10) write("It is really cold and dark down here, and you shiver.\n");
    else if(z<-5) write("It is getting rather cold and dark down here now.\n");
	write("It looks like you could probably dig in any direction.\n" +
          "Other exits already dug are:\n    ");
    the_array = dungeon->query_directions();
    notfirst = 0;
    i = 0;
    while (i < 10) {
	if (exits[i]) {
	    if (notfirst)
		write(", ");
	    write(the_array[i]);
	    notfirst = 1;
	}
	i += 1;
    }
    write(".\n");
}

clean_up() {
  object *inv;
  if((time()-last_init_time) > 3600) {
    int i,j;
    inv=deep_inventory();
    if(sizeof(filter_array(inv, "int_f", this_object()))) return 1;
    j=sizeof(inv);
    for(i=0;i<j;i++) if(inv[i]) destruct(inv[i]);
    destruct(this_object());
    return 0;
  }
  return 1;
}

int_f(ob) { return interactive(ob); }
