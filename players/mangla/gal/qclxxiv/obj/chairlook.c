#define MAX_LIST            20
#define SHARE "obj/share"
#define CName capitalize(name)
object myobj;
static object myself;           /* Ourselfs. */
static string it;               /* Last thing referenced. */
static string name;
int is_invis;	        	/* True when player is invisible */

id(arg) { return arg=="qchairlook"; }

possess(object pl) {
	myobj = shadow(pl, 1);
}

mylook(brief) {
object ob, ob_tmp;
string item,short_str,msg;
int max;
	myself = this_player();
	name = myself->query_name();
	is_invis = myself->query_invis();
    if (myself->test_dark())
		return 1;
    /* if (!brief) { No brief support in these rooms:-) */
	long();
	ob = first_inventory(this_object());
	max = MAX_LIST;
	msg = "";
	while(ob && max > 0) {
		/* filter out ppl sitting on chairs etc. */
		/* as chairs do display them already.    */
		/* also filter out things we are sitting on ourselves */
		if (living(ob)) {
			if (present("qchairsoul",ob)) {
	    		ob = next_inventory(ob);
				continue;
			}
		}
		else {
			if (ob->id("q174chair") && myself==ob->query_sitting()) {
	    		ob = next_inventory(ob);
				continue;
			}
		}
		/* end of chair/etc filter */
	    if (ob != myself) {
		if (short_str=ob->short()) {
		    max -= 1;
		    msg += capitalize(short_str) + ".\n";
		   it = short_str;
		}
	    }
	    ob = next_inventory(ob);
	}
	if (ob && !max) msg += "*** TRUNCATED ***\n";
	if (msg!="") write(msg);
	if (!is_invis) say(CName+" looks around.\n");
	return 1;
}
 
