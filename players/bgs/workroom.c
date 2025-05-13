#define NAME "bgs"
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
              "You are in "+CNAME+"'s workroom. The room is filled with the\n" +
              "usual smell of newly furnished rooms. Everything is new and there is\n" + 
              "still some dust on everything except for the table and the chair.\n";

// We need some exits too ... lets set the destination directions
    dest_dir=({
               "room/post", "post",
               "room/church", "church",
               "room/adv_guild", "guild", 
             });

// Item descriptions can be placed in here
    items=({ 
            "desk","It's a nice table made of a beautiful dark brown wood",
            "table","It's a nice table made of a beautiful dark brown wood",
            "floor","There is some white dust on the floor",
            "dust","The room was not yet cleaned since "+CNAME+" moved in",
            "chair","It's a rather worn chair but you can see that it must be very\n" +
             "comfortable",
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
