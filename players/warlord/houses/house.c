
/* house.c   V2.0      Metaprat       6th April 1992  */

/* This is the players house.  Various household options may be specified */
/* by they player, as well as the decor.  Entry, and creation/restoration */
/* is controlled by the house_key, which the player is given when they    */
/* buy the house.                                                         */

/* NOTE: when you set this up for the first time, patch set_owner to      */
/* NEW_OWNER, and set up the default room descriptions ('decorate').      */


inherit "/players/silas/houses/house_room";

#define FILENAME     "/players/silas/houses/house"
#include "/players/silas/houses/house_defines.h"


/* STATIC variables (not restored/saved) */
static string nullstring;
static string owner_name;      /* Supplied by the house key  */
static object rooms;           /* rooms array; will replace bedroom & kit */


/* DYNAMIC variables (restored and saved) */
string main_room_desc;      /* V1 descriptions.  If set, these will be */
string bedroom_room_desc;   /* translated to the V2 variables below.   */
string kitchen_room_desc;

string rooms_desc;      /* V2 arrays for room information */
string rooms_short;     /* will replace V1 kitchen and    */
string furnishings;     /* bedroom strings.               */
string items;		/* notes, vases, etc ...	  */
int    rooms_x;
int    rooms_y;

/* Exits for south and west are taken from the neighbouring rooms,    */
/* this means that the data structure is proof against paired errors. */

string exits_special;   /* ({"church", "guild", "shop"})        */
string exits_wizard;    /* ({"workroom", "castle"})             */
int    exits_north;     /* 0 = no exit.  For other exit types,  */
int    exits_east;      /* see 'describe_door()' in house_room. */
int    get_room_index;



reset(arg) {
    int indx;
    int something_found;

    if (arg) {
	/* Ok, the following section is to conserve memory.     */
	/* See if anyone is in the house.                       */
	for (indx = (MAXNUMROOMS - 1); indx >= 0; indx --) {
	    if ((rooms[indx]) && (first_inventory(rooms[indx]))) {
		something_found = 1;
	    }
	}
	/* If the house is empty, then make the whole lot go BOOM */
	if (!something_found) {
	    self_destruct();
	}
	return;
    }
    if (DEBUGLEVEL) {
	log_file(LOGFILE, "House: house created, ");
	if (this_player()) {
	    log_file(LOGFILE, "for " + this_player()->query_name() + ".\n");
	}
	else {
	    log_file(LOGFILE, "no player name known.\n");
	}
    }
    set_light(1);

    /* make the restored vars into arrays. Probably unnecessary. */
    rooms_desc    = allocate(MAXNUMROOMS);
    rooms_short   = allocate(MAXNUMROOMS);
    furnishings   = allocate(MAXNUMROOMS);
    items         = allocate(MAXNUMROOMS);
    rooms_x       = allocate(MAXNUMROOMS);
    rooms_y       = allocate(MAXNUMROOMS);
    exits_north   = allocate(MAXNUMROOMS);
    exits_east    = allocate(MAXNUMROOMS);
    exits_special = allocate(MAXNUMROOMS);
    exits_wizard  = allocate(MAXNUMROOMS);

    /* set up the rooms table. */
    rooms     = allocate(MAXNUMROOMS);
    rooms[0]  = this_object();
    main_hall = this_object();
}



room_stats() {
    ::room_stats();
    write("SPECIAL:    This is the controlling room, from which room data\n");
    write("            is loaded and stored.\n");
    return 1;
}


restore_stats(str) {
    if (DEBUGLEVEL) {
	log_file(LOGFILE,
	  "House: reading "+ str +"'s house file "+
	  ", at "+
	  ctime(time()) + ".\n");
    }
    if(!restore_object(sprintf(HOUSES_DIR + "%c" +
	  "/" + "%s", str[0], str))) {
	log_file(LOGFILE,
	  "House: restore_stats(" + str + ") failed - probably new house.\n" +
	  "Rebuilding from a "+
	  "NEW_OWNER at time: "+
	  ctime(time()) + ".\n");
	restore_object(sprintf(HOUSES_DIR + "%c" +
	    "/" + "NEW_OWNER", str[0] ));
	save_stats();
    }
    if (main_room_desc || kitchen_room_desc || bedroom_room_desc) {
	log_file(LOGFILE,
	  "House: Transforming data file from Ver 1 to Ver 2 format.\n");
	if (main_room_desc) {
	    rooms_desc[0]    = main_room_desc;
	    rooms_short[0]   = "Main hallway";
	    furnishings[0]   = "";
	    items[0]	  = 0;
	    rooms_x[0]       = 0;
	    rooms_y[0]       = 0;
	    exits_north[0]   = 0;
	    exits_east[0]    = 0;
	    exits_special[0] = ({"church"});
	    exits_wizard[0]  = ({"workroom", "castle"});
	    main_room_desc = nullstring;
	}
	if (kitchen_room_desc) {
	    rooms_desc[1]    = kitchen_room_desc;
	    rooms_short[1]   = "Kitchen";
	    furnishings[1]   = "";
	    items[1]	  = 0;
	    rooms_x[1]       = 0;
	    rooms_y[1]       = 1;
	    exits_north[1]   = 1;    /* to/from main room */
	    exits_east[1]    = 1;    /* to/from bedroom   */
	    exits_special[1] = ({ });
	    exits_wizard[1]  = ({ });
	    kitchen_room_desc = nullstring;
	}
	if (bedroom_room_desc) {
	    rooms_desc[2]    = bedroom_room_desc;
	    rooms_short[2]   = "Bedroom";
	    furnishings[2]   = "";
	    items[2]	  = 0;
	    rooms_x[2]       = 1;
	    rooms_y[2]       = 1;
	    exits_north[2]   = 0;
	    exits_east[2]    = 0;
	    exits_special[2] = ({ });
	    exits_wizard[2]  = ({ });
	    bedroom_room_desc = nullstring;
	}
	save_stats();
    }
    gather_room_information(0,0);    /* set up main hall descriptions */
}



static save_stats() {
    if (DEBUGLEVEL > 1) {
	log_file(LOGFILE,
	  "House: saving "+ owner_name +
	  "'s house, at "+
	  ctime(time()) + ".\n");
    }
    save_object(sprintf(HOUSES_DIR +
	"%c" +"/"+ "%s", owner_name[0], owner_name));
}



set_owner(str) {
    owner_name = str;
    (MASTERHOUSE)->register_house(owner_name, this_object());
}



query_owner(str) {
    return owner_name;
}


set_new_decoration(newx, newy, new_short, new_desc) {
    int room_index;

    room_index = get_room_index(newx, newy);
    if (room_index < 0) {
	log_file(LOGFILE,
	  "House: set_new_decoration(" + newx + ", " + newy +
	  ") failed to get room index.\n");
	write("Sorry, 'decorate' failed!  Room index not found.\n");
	return;
    }
    rooms_desc[room_index] = new_desc;
    rooms_short[room_index] = new_short;
    save_stats();
}


set_new_items(newx, newy, new_items) {
    int room_index;

    room_index = get_room_index(newx, newy);
    if (room_index < 0) {
	log_file(LOGFILE,
	  "House: set_new_items(" + newx + ", " + newy +
	  ") failed to get room index.\n");
	write("Sorry, 'decorate' failed!  Room index not found.\n");
	return;
    }
    items[room_index] = new_items;
    save_stats();
}

set_new_exits_north(newx, newy, new_exit_status) {
    int room_index;

    room_index = get_room_index(newx, newy);
    if (room_index < 0) {
	log_file(LOGFILE,
	  "House: set_new_exits_north(" + newx + ", " + newy +
	  ") failed to get room index.\n");
	return;
    }
    exits_north[room_index] = new_exit_status;
    save_stats();
}



set_new_exits_east(newx, newy, new_exit_status) {
    int room_index;

    room_index = get_room_index(newx, newy);
    if (room_index < 0) {
	log_file(LOGFILE,
	  "House: set_new_exits_east(" + newx + ", " + newy +
	  ") failed to get room index.\n");
	return;
    }
    exits_east[room_index] = new_exit_status;
    save_stats();
}



set_new_room(indx, newx, newy) {
    /* Add a new room.  Do NOT record it, since it will be recorded by the */
    /* ensuing call to change_exit_pair.                                   */

    if ((indx < 1) || (indx >= MAXNUMROOMS) || (rooms[indx])) {
	log_file(LOGFILE,
	  "House: set_new_room(" + indx + ", " + newx + ", " +
	  newy + ")ignoring.\n");
	return;
    }
    rooms_desc[indx]    =
    "This is a brand new, unfurnished room.  As soon as you see it, you\n" +
    "start imagining interesting ways to decorate it.. it could be anything,\n" +
    "a cupboard, a conservatory, an orchard, heaven or hell..\n" +
    "A small note in the corner says:  'help build/furnish'.\n";
    rooms_short[indx]   = "A brand new room, ready to be decorated";
    furnishings[indx]   = "";
    items[indx]	       = 0;
    rooms_x[indx]       = newx;
    rooms_y[indx]       = newy;
    exits_special[indx] = ({ });
    exits_wizard[indx]  = ({ });
    exits_north[indx]   = 0;
    exits_east[indx]    = 0;
    save_stats();
    find_room(newx, newy);  /* create the room, add it to rooms array */
}


set_new_exits_special(arr, newx, newy) {
    int room_index;

    room_index = get_room_index(newx, newy);
    if (room_index < 0) {
	log_file(LOGFILE,
	  "House: set_new_exits_special(" + newx + ", " + newy +
	  ") failed to get room index.\n");
	return;
    }
    if (!pointerp(arr)) {
	return;
    }
    exits_special[room_index] = arr;
    save_stats();
}



set_new_exits_wizard(arr, newx, newy) {
    int room_index;

    room_index = get_room_index(newx, newy);
    if (room_index < 0) {
	log_file(LOGFILE,
	  "House: set_new_exits_wizard(" + newx + ", " + newy +
	  ") failed to get room index.\n");
	return;
    }
    if (!pointerp(arr)) {
	return;
    }
    exits_wizard[room_index] = arr;
    save_stats();
}



find_room(newx, newy) {
    int room_index;

    room_index = get_room_index(newx, newy);
    if ((room_index < 0) || (room_index >= MAXNUMROOMS)) {
	log_file(LOGFILE,
	  "House: ERROR, find_room(" + newx + ", " + newy + ") found " +
	  room_index + ". Owner = " + owner_name + ",\ntime was: " +
	  ctime(time()) + ".\n");
	return main_hall;   /* make exit to main room */
    }
    if (!rooms[room_index]) {
	room_index = gather_room_information(newx, newy);
    }
    return rooms[room_index];
}


query_room(indx) {
    if ((indx < 0) || (indx >= MAXNUMROOMS)) {
	return 0;
    }
    return rooms[indx];
}



query_desc(indx) {
    if (indx == -1) {
	return "An uninitialised room.\n";
    }
    if ((indx < 0) || (indx >= MAXNUMROOMS)) {
	return "A room with an unreliable index.\n";
    }
    return rooms_desc[indx];
}


query_items(indx) {
    if ((indx==-1) || (indx < 0) || (indx >= MAXNUMROOMS))
	return ({ "nothing","You see nothing" });
    return items[indx];
}


query_room_position(indx) {
    if ((indx < 0) || (indx >= MAXNUMROOMS)) {
	return 0;
    }
    if (rooms_desc[indx]) {
	return ({ rooms_x[indx], rooms_y[indx] });
    }
    return 0;
}



get_room_index(newx, newy) {
    int indx;

    if ((newx == 0) && (newy == 0)) {
	return 0;    /* just hardwire the check for the main room in */
    }
    for (indx = 1; indx < MAXNUMROOMS; indx ++) {
	if ((newx == rooms_x[indx]) && (newy == rooms_y[indx])) {
	    return indx;
	}
    }
    return -1;   /* search failed */
}


static gather_room_information(newx, newy) {
    int room_index;
    int s_room_index;   /* used to get exits to south */
    int w_room_index;   /* used to get exits to west  */
    int found_exit_south;
    int found_exit_west;

    room_index   = get_room_index(newx, newy);
    s_room_index = get_room_index(newx, newy + 1);
    w_room_index = get_room_index(newx - 1, newy);
    if (s_room_index >= 0) {
	found_exit_south = exits_north[s_room_index];
    }
    else {
	found_exit_south = 0;
    }
    if (w_room_index >= 0) {
	found_exit_west = exits_east[w_room_index];
    }
    else {
	found_exit_west = 0;
    }
    /* force the main hall to have a church exit */
    if ((room_index == 0) &&
      ((!exits_special[0]) ||
	(!search_array(exits_special[0], "church")))) {
	/*    exits_special[0] = exits_special[0] + ({ "church" }); */
	exits_special[0] =  ({ "church" }); 
    }
    if (!rooms[room_index]) {
	rooms[room_index] = clone_object(ROOMS);
    }
    rooms[room_index]->set_parent_house(this_object());
    rooms[room_index]->set_room_desc(rooms_desc[room_index]);
    rooms[room_index]->set_room_short_desc(rooms_short[room_index]);
    rooms[room_index]->set_room_furnish(furnishings[room_index]);
    rooms[room_index]->set_room_items(items[room_index]);
    rooms[room_index]->set_room_coords(newx, newy);
    rooms[room_index]->set_room_index(room_index);
    rooms[room_index]->set_room_special_exits(exits_special[room_index]);
    rooms[room_index]->set_room_wizard_exits(exits_wizard[room_index]);
    rooms[room_index]->set_room_exits(exits_north[room_index],
      found_exit_south,
      exits_east[room_index],
      found_exit_west);
    return room_index;
}


self_destruct() {
    int indx;

    for (indx = (MAXNUMROOMS - 1); indx >= 0; indx --) {
	if (rooms[indx]) {
	    tell_room(rooms[indx],
	      "A massive explosion rips through the house, destroying all.\n");
	    move_contents(rooms[indx], find_object(CHURCH));
	    destruct(rooms[indx]);
	}
    }
}



erase_room(indx) {
    int newx;
    int newy;
    int s_room_index;
    int w_room_index;
    int found_exit_south;
    int found_exit_west;

    if (indx == 0) {
	write("The main room may not be destroyed.\n");
	return 0;
    }
    if ((indx < 1) || (indx >= MAXNUMROOMS)) {
	write("Rooms index number out of range.\n");
	return 0;
    }
    newx = rooms_x[indx];
    newy = rooms_y[indx];
    s_room_index = get_room_index(newx, newy + 1);
    w_room_index = get_room_index(newx - 1, newy);
    if (s_room_index >= 0) {
	found_exit_south = exits_north[s_room_index];
    }
    else {
	found_exit_south = 0;
    }
    if (w_room_index >= 0) {
	found_exit_west = exits_east[w_room_index];
    }
    else {
	found_exit_west = 0;
    }
    if ((exits_north[indx]) ||
      (found_exit_south)  ||
      (exits_east[indx])  ||
      (found_exit_west))     {
	write("There are exits remaining! These must be destroyed first..\n");
	return 0;
    }
    log_file(LOGFILE,
      "house: Room " + indx + " destroyed. " + ctime(time()) + ".\n");
    if (rooms[indx]) {
	tell_room(rooms[indx],
	  "A demolition team turn up, throw you out, and smash the room into" +
	  "\na dusty pile of rubble.\n");
	move_contents(rooms[indx], find_object(CHURCH));
	destruct(rooms[indx]);
    }
    rooms_desc[indx]    = nullstring;
    rooms_short[indx]   = nullstring;
    furnishings[indx]   = nullstring;
    items[indx]	       = 0;
    rooms_x[indx]       = 0;
    rooms_y[indx]       = 0;
    exits_special[indx] = ({ });
    exits_wizard[indx]  = ({ });
    exits_north[indx]   = 0;
    exits_east[indx]    = 0;
    save_stats();
    return 1;
}


move_contents(origin, destination) {
    object thisob;
    object nextob;

    thisob = first_inventory(origin);
    while (thisob) {
	nextob = next_inventory(thisob);
	move_object(thisob, destination);
	thisob = nextob;
    }
}





