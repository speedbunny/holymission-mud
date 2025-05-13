
/* house_map.c     Metaprat    11th April 1992  */

/* builds up a map of the house */


#define  FILENAME     "/players/silas/houses/house_map"
#include "/players/silas/houses/house_defines.h"

/* STATIC variables (won't be restored into) */
static string index_desc;
static string map_desc;
static string owner_name;
static object main_hall;


/* DYNAMIC variables (will be restored) */
string rooms_desc;
string rooms_short;
int    rooms_x;
int    rooms_y;
int    exits_north;
int    exits_east;


id(str) {
    return (str == "map")   ||   (str == owner_name + " house map")  ||
    (str == short()) ||   (str == owner_name + " map")        ||
    (str == "map of " + owner_name + "'s house")  ||
    (str == "map of " + owner_name + "s house")   ||
    (str == "index")  ||  (str == "map index");
}


short() {
    if (!owner_name) {
	return "Undrawn map";
    }
    return "Map of " + capitalize(owner_name) + "'s house, with index";
}


get() {
    return 1;
}


drop() {
    return 0;
}



query_value() {
    return (MAPCOST / 2) ;
}


reset(arg) {
    if (arg) {
	return;
    }
    if (DEBUGLEVEL) {
	log_file(LOGFILE, "House_map: created.\n");
    }
    rooms_desc  = allocate(MAXNUMROOMS);
    rooms_short = allocate(MAXNUMROOMS);
    rooms_x     = allocate(MAXNUMROOMS);
    rooms_y     = allocate(MAXNUMROOMS);
    exits_north = allocate(MAXNUMROOMS);
    exits_east  = allocate(MAXNUMROOMS);
}



init() {
    add_action("read", "read");
}



draw_map() {
    int    index_room;
    int    index_x;
    int    index_y;
    int    max_x;
    int    min_x;
    int    max_y;
    int    min_y;
    int    cells;
    int    cells_north;
    int    cells_east;
    string map_row_1;
    string map_row_2;

    if (DEBUGLEVEL) {
	log_file(LOGFILE, "House_map: drawing map, ");
	if (this_player()) {
	    log_file(LOGFILE, "for " + this_player()->query_name() + ", ");
	}
	else {
	    log_file(LOGFILE, "No player name known.\n");
	}
	log_file(LOGFILE, "house owner is " + owner_name + ".\n");
    }
    if(!restore_object(sprintf(HOUSES_DIR + "%c" +
	  "/" + "%s", owner_name[0], owner_name))) {
	/*Nylakoorub : dir sep */
	map_desc = "The map is an empty page.\n";
	return 1;
    }
    /* Calculate page size */
    for (index_room = 0; index_room < MAXNUMROOMS; index_room ++) {
	if (rooms_x[index_room] > max_x) {
	    max_x = rooms_x[index_room];
	}
	if (rooms_x[index_room] < min_x) {
	    min_x = rooms_x[index_room];
	}
	if (rooms_y[index_room] > max_y) {
	    max_y = rooms_y[index_room];
	}
	if (rooms_y[index_room] < min_y) {
	    min_y = rooms_y[index_room];
	}
    }

    cells       = allocate(max_x - min_x + 1);
    cells_north = allocate(max_x - min_x + 1);
    cells_east  = allocate(max_x - min_x + 1);
    for (index_x = 0; index_x < (max_x - min_x + 1); index_x ++) {
	cells[index_x]       = allocate(max_y - min_y + 1);
	cells_north[index_x] = allocate(max_y - min_y + 1);
	cells_east[index_x]  = allocate(max_y - min_y + 1);
    }

    for (index_room = 0; index_room < MAXNUMROOMS; index_room ++) {
	if (rooms_desc[index_room]) {
	    index_x = rooms_x[index_room] - min_x;
	    index_y = rooms_y[index_room] - min_y;
	    cells[index_x][index_y]       = index_room + 1;
	    cells_north[index_x][index_y] = exits_north[index_room];
	    cells_east[index_x][index_y]  = exits_east[index_room];
	}
    }

    map_desc = "A map of " + capitalize(owner_name) + "'s house.\n";
    for (index_y = 0; index_y <= (max_y - min_y); index_y ++) {
	map_row_1 = "    ";
	map_row_2 = "    ";
	for (index_x = 0; index_x <= (max_x - min_x); index_x ++) {
	    if (cells[index_x][index_y]) {
		if (cells_north[index_x][index_y]) {
		    map_row_1 = map_row_1 + "|  ";
		}
		else {
		    map_row_1 = map_row_1 + "   ";
		}
		if ((index_x + min_x == 0) && (index_y + min_y == 0)) {
		    map_row_2 = map_row_2 + "E";
		}
		else {
		    map_row_2 = map_row_2 + (cells[index_x][index_y] - 1);
		}
		if (cells_east[index_x][index_y]) {
		    map_row_2 = map_row_2 + "--";
		}
		else {
		    map_row_2 = map_row_2 + "  ";
		}
	    }
	    else {
		map_row_1 = map_row_1 + "   ";
		map_row_2 = map_row_2 + "   ";
	    }
	}
	map_desc = map_desc + map_row_1 + "\n" + map_row_2 + "\n";
    }
    /* The rooms_desc array is quite large, so lets clear it out. */
    rooms_desc = ({ });
    if (rooms_short[0]) {
	index_desc = "E - Entrance/Exit (" + rooms_short[0] + ").";
    }
    else {
	index_desc = "E - Entrance/Exit.";
    }
    for (index_room = 1; index_room < MAXNUMROOMS; index_room ++) {
	if (rooms_short[index_room]) {
	    index_desc = index_desc + "\n" + index_room + " - " +
	    rooms_short[index_room] + ".";
	}
    }
    rooms_short = ({ });
}



set_owner(str) {
    owner_name = str;
    draw_map();
    call_out("timeout", TIMEOUT);
}


read(str) {
    if ((!str) || (!id(str))) {
	return 0;
    }
    if ((str == "index") || (str == "map index")) {
	write(index_desc + "\n");
	return 1;
    }
    write(map_desc + "\nE - Entrance/Exit.\nThe index may also be read.\n");
    return 1;
}


long(str) {
    if ((str == "index") || (str == "map index")) {
	write(index_desc + "\n");
	return 1;
    }
    write(map_desc + "\nE - Entrance/Exit.\nThe index may also be read.\n");
    return 1;
}


timeout() {
    say("Your map turns to dust.\n");
    map_desc   = ""; /* just make sure the arrays get deallocated */
    index_desc = "";
    destruct(this_object());
}
