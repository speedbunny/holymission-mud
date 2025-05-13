inherit "/room/room";

object gnome;
int light,currLight,gnomeNr,actGnome;
object *gnomeArr;
#define TP this_player()
#define maxGnome 5
#define PATH "/players/sourcer/"

reset(arg) {
    ::reset(arg);
      create_room();               
      }
    
    
    create_room() {
        
        set_light( 0 ); 
        short_desc= "A dark and very old forest";
        long_desc= "You are in the Old Forest, the trees are huge \n" +
                  "and seem to be very old. Heaps or half rotten \n" +
                  "branches and leafes are lying on the ground.\n" +
                  "It's rather spooky around here. \n";
        
        dest_dir = ({PATH + "room/forest2","south"});
                     
        items = ({"heaps","They consist of leafes, branches and other rotten things",
                  "branch","They are rotten",
                  "braches","They are rotten",
                  "leafes","They are quite rotten",
                  "tree","They are very old",
                  "trees","They are very old"});
                  
          if (!gnome) {
             gnome=clone_object(PATH+"monster/gnome1");
             move_object(gnome,this_object());
           }
        }
        
init(arg) {
    ::init(arg);
    add_action("do_search","search");
    
/* ------------- LIGHT  -------------*/

    light = random (2 );
    write("Light: "+ light + "\n");
    if (light == 0) {
        currLight = set_light(0);
        if (currLight == 0) return ( 0 );
        else set_light(-1);
        }
    else {
        currLight = set_light(0);
        if (currLight == 0) set_light(1);
        else return ( 0 );
        }
        
/*--------------- Gnomes -----------------*/
    
    if(gnome->query_hp() < (900)) {
        gnomeNr = random ( maxGnome );  
        write(gnomeNr);
        for (actGnome = 1;actGnome <= gnomeNr;actGnome = actGnome + 1) {
            gnomeArr[actGnome] = clone_object(PATH+"monster/gnome1");
            move_object(gnomeArr[actGnome],this_object());
            }
        }
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

    
        
    
