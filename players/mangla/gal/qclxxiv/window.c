/* window object --- by Qclxxiv 1993 */
string toroom;
string name;
string alias;
string longtxt;
int clean;
int visible;
int dirtyatreset;
int cleanatreset;
/* example: set_all( "players/qclxxiv/room3", "A window to the west",
 *                    "west window", "A nice clean window to the west.\n",
 *                    1, 1, 0, 1 );
 * leaving out the / at start of toroom is essential for room-room lookup!
*/
set_all( destroom, aname, analias, alongtxt, isclean, isvisible,
         isdirtyatreset, iscleanatreset )
{
    set_toroom(destroom); set_name(aname); set_alias(analias);
    set_long(alongtxt); set_clean(isclean), set_visible(isvisible);
    set_dirtystreset(isdirtyatreset); set_cleanatreset(iscleanatreset);
}

set_toroom(arg) { toroom=arg; }    
set_name(arg) { name=arg; }
set_alias(arg) { alias=arg; }
set_long(arg) { longtxt=arg; }
set_clean(arg) { clean=arg; }
set_visible(arg) { visible=arg; }
set_dirtyatreset(arg) { dirtyatreset=arg; }
set_cleanatreset(arg) { cleanatreset=arg; }
query_toroom() { return toroom; }
query_clean() { return clean; }

id(arg) { return (arg=="window"||arg==name||arg==alias||arg=="win_"+toroom); }
short() { return (visible) ? name : 0; }
long()  { 
    write(longtxt); 
    write("The window is "+( (clean>0) ? "clean" : "dirty")+". ");
    if (clean) write("You can probably look through it.\n");
    else write("You can probably not look through it.\n");
}
get()    { return 0; }

init()  { 
    add_action("breakwindow", "break" );
    add_action("makeclean", "clean" );
    add_action("lookthru", "look" );
}

reset(arg) {
    if (cleanatreset) clean = 1;
    if (dirtyatreset) clean = 0;
    if (arg) return;
    clean = 1;            /* clean by default:-) */
    name = "window";    /* safe defaults */
    alias = "window";
    longtxt = "A window.\n";
	visible = 1;
}

breakwindow(arg) {
    if (!arg || !id(arg)) return 0;
    say(this_player()->query_name()+" tries to break the window.\n",
                this_player() );
    write("You fail to break the famous Qcxxiv's magic panzer glass.\n");
    return 1;
}

makeclean(arg) {
    if (!arg || !id(arg)) return 0;
    if (clean>0) {
        say(this_player()->query_name()+" is cleaning a clean window.\n",
                    this_player() );
        write("This window is already clean, at least at this side.\n");
    }
    else {
        say(this_player()->query_name()+" is cleaning a window.\n",
                    this_player() );
        write("Ok.\n");
        clean++; /* allow neg. clean so that multiple cleans are nece:-) */
        if (clean<1) write("It still didn't become clean.\n");
    }
    return 1;
}

lookthru(arg) {
	object other;
	string win;
    if (!arg) return 0;
	if ( !(sscanf(arg,"through %s",win)||sscanf(arg,"thru %s",win)) 
		 || (!id(win)) ) 
		return 0;
    say(this_player()->query_name()+" looks through a window.\n",
              this_player() );
    if (!clean) write("You can not look through it.\n");
    else {
        if (!toroom) 
            write("Apparently there is NOTHING at the other side...\n");
        else {
			if (toroom->get() || 1) {	/* make sure toroom is there */
				if (other=present("win_"+file_name(environment(this_object())),
							find_object(toroom))) {
					if (other->query_clean()<1) {
						write("Unfortunately the other side is dirty.\n");
						return 1;
					}
				}
				write("You look through the window:\n");
				ext_long(find_object(toroom));
			}
        }
    }
    return 1;
}

ext_long(arg) {
	if (!arg) arg = environment(this_object());
	if (!arg) arg = this_object();
	arg->long();
	show_inventory(arg);
}

show_inventory(arg) {
	int i;
	object obj;
	if (!arg) arg = environment(this_object());
	if (!arg) arg = this_object();
	obj = all_inventory(arg);
	for (i=0; i<sizeof(obj); i++)
		if (obj[i]->short()) write(capitalize(obj[i]->short())+".\n");
}

