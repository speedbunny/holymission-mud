#define NAME "morrolan"
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
"          Welcome to Morrolan's Workroom!!\n"+
"Yea, this is where Morrolan likes to hang out, and looking out the window at\n"+
"the ocean below you can understand why. Inside the room\n"+
"there is a desk, computer, and various other coding-type\n"+
"stuff layin around. Feel free to look around, but please\n"+
"please please don't break anything....for your own sake.\n";

// We need some exits too ... lets set the destination directions
    dest_dir=({
               "room/post", "post",
               "room/church", "church",
               "room/adv_guild", "guild", 
               "players/matt/newworld/city/rooms/votebooth", "vote",
               "players/tuppence/workroom", "stephie",
               "players/redsexy/workroom", "red",
               "players/misticalla/workroom", "hoosier",
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
