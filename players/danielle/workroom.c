#define NAME "danielle"
inherit "room/room";
#define CNAME   capitalize(NAME)
// This procedure is called periodically to check for monsters
//    which need to be replaced or other values that need
//    to be reset.
void reset(int arg) {
// First we need some light in here
    set_light(1);
// Then lets set a short description in case we are in brief-mode
    short_desc=CNAME + "'s workroom",
// Now the long standard room description
//    change this to fit your style
   long_desc=
    	"This is Danielle's laboratory.  The room is furnished with\n" +
	"a desk, a few bookshelves and a couple of chairs for\n" +
        "occasional visitors.\n";
// We need some exits too ... lets set the destination directions
    dest_dir=({
               "room/post", "post",
               "room/church", "church",
               "room/adv_guild", "guild",
          	"players/sylvyn/workroom.c", "Sylvyn"
             });
// Item descriptions can be placed in here
    items=({
            "bookshelves","These shelves are filled with all sorts of Physics\n" +
	                   "Mathematics texts",
            "chair","This chair is meant for visitors.  Relax and sit down",
	    "desk","A large oak desk.  There are papers, books and pens\n" +
                   "strewn all over it",
          });
// Properties can be set like the following
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
// Here you call the the reset in the inherited "room/room"
//    and the replace program will keep the room updated
//    without further function calls
    ::reset(arg);
    replace_program("room/room");
}
/********** You can place add_actions in here for special actions
init() {
    ::init();
    add_action("_blah","blah");
}
************/
