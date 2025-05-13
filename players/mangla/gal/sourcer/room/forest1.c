inherit "/room/room";
#define TP this_player()
#define TO this_object()
#define PATH "/players/sourcer/"

reset(arg) {
    ::reset(arg);
    
    if (!arg) {
        set_light( 1 );
        short_desc= "A dark and very old forest";
        long_desc= "You are in the Old Forest, the trees are huge \n" +
                  "and seem to be very old. Heaps or half rotten \n" +
                  "branches and leafes are lying on the ground.\n" +
                  "It's rather spooky around here. \n";
        
        dest_dir = ({PATH + "room/room1","out",
                     PATH + "room/forest2","north"});
                     
        items = ({"heaps","They consist of leafes, branches and other rotten things",
                  "branch","They are rotten",
                  "braches","They are rotten",
                  "leafes","They are quite rotten",
                  "tree","They are very old",
                  "trees","They are very old"});
        
        }
    }
    
init(arg) {
    ::init(arg);
    add_action("do_search","search");
    }
    
do_search(str) {
    if (!str) return 0;
        
    
    else {
        if (str == "heaps" || str == "leafes" || str == "branches" 
                || str == "branch") {
            write("You search, and search but find nothing (yes)");
            say(TP->query_name()+" searches around.");
            return ( 1 );
            }
            
        else {
            write("You search, and search but find nothing (no)");
            say(TP->query_name()+" searches around.");
            return ( 1 );
            }
        }
    }

    
        
    
