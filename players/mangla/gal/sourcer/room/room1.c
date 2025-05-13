inherit "room/room";


#define TP this_player()

reset(arg) {

    if(!arg) {
        set_light(1);
        short_desc= "Testroom No. 1 ";
        long_desc = "This is testroom No. 1. \n" + 
                    "In file /players/sourcer/room/room1.c. \n" +
                    "There is a hole in the floor. \n" +
                    "In the corner you see a chest, \n";
        
    items = ({"floor","You see a little dark hole in the floor",
             "hole","It's dark, but there is something in it.",
             "chest","It looks very precious, open it"});
            
    dest_dir = ({"/players/sourcer/workroom","work",
                "/players/patience/guild/room","guild",
                "/players/sourcer/room/forest1","for"});
    }
  }
    
init() {
    ::init();
    add_action("do_search","search");
    add_action("do_enter","enter");
    }

do_search(str) {
    object vase;
    if(!str) {
        notify_fail("What do you want to search? \n");
        } 
    else if (str == "hole" && (!present("vase",this_object()))) {
        write("There is a vase in it. \n");
        say(TP->query_name()+" found a vase.\n");       
        vase = clone_object("/players/sourcer/obj/ming");
        transfer (vase,this_object());
        }    
    else {
        return ( 0 );
        }       
    return ( 1 );
    }
do_enter (str) {
    if(!str) {
        notify_fail("Enter what ???");
        }
    else if (str == "hole") {
        write("You are much too big!");
        }
    else { return ( 0 ); }
    return (1 );
    }
    


        
