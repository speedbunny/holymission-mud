#define NAME "raindell"
inherit "room/room";

#define CNAME   capitalize(NAME)

// This procedure is called periodically to check for monsters
//    which need to be replaced or other values that need
//    to be reset.

void reset(int arg) {

// Here you call the the reset in the inherited "room/room"
    ::reset(arg);

// First we need some light in here
    set_light(1);

// Then lets set a short description in case we are in brief-mode
    short_desc=CNAME + "'s workroom",

// Now the long standard room description
//    change this to fit your style
    long_desc=
              "\nThis is "+CNAME+"'s shiny, brand-new workroom.\n" +
          	  "There is little visible at present, as most \n" +
		  "of the room is obscured by a veritable flood \n" +
		  "of brown cardboard boxes.  With labels running \n" +
		  "the gamut from 'Supplies' to 'Music' to 'Amusing-\n" +
		  "but-useless-trinkets', it's obvious to even a blind \n" +
		  "man in a dark bag, that a new wizard is still moving \n" +
		  "in.  Thus far, the only real decor (apart from the \n " +
		  "boxes) is a rather worn swivelling office chair, and \n" +
		  "a most bizarre computer desk, still unassembled. \n";

// We need some exits too ... lets set the destination directions
    dest_dir=({
               "room/post", "post",
               "room/church", "church",
               "room/adv_guild", "guild", 
             });

// Item descriptions can be placed in here
    items=({ 
            "air","It's very thin up here",
            "floor","The floor is dirty",
          });

// Properties can be set like the following
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });

//    The replace program will keep the room updated
//    without further function calls
    replace_program("room/room");
}

/********** You can place add_actions in here for special actions
init() {
    ::init();
    add_action("_blah","blah");
}
************/
