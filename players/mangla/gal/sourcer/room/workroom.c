inherit "room/room";
#define CNAME   capitalize(NAME)
#define NAME    "sourcer"
#define TP this_player()
int ossiCount;

/* This procedure is called every hour at the mom. The first time it
   is call with the arg==0, after that arg is always 1. */
reset(arg) {

    if(!arg) {
  
        ossiCount = 0;
        
        set_light(1);

        short_desc=CNAME + "' workroom",
        long_desc=
        "This is the giant workroom of "+CNAME+".\n" +
        "There is a huge desk standing in front of the window, \n" + 
        " with piles of papers on it.... you can't imagine how busy \n " +
        "this wizard is, so don't disturb him!!! \n ";

        dest_dir=({
            "room/post", "post",
            "room/church", "church",
            "room/adv_guild", "guild", 
            "/players/sourcer/quest/road1", "quest",
            "players/sourcer/room/room1", "room1",
                });
 
        items=({ 
            "air","It's very thin up here",
            "floor","The floor is covered with smooth carpets.",
            "desk","It's a huge wooden desk with lots of papers on it. ",
            "papers","You won't dare to read it, they are PRIVATE!!",
              });
      /*  property = ({
                 "no_teleport","no_sneak","no_steal",
                    });     */
        /* Smell is set like this... */
        smell = "This place is a bit dusty";
    }
}

init()
{
  ::init(); 

    if ((find_living( NAME )) && (TP->query_real_name() != NAME)) {
        if (TP->query_invis()) {
            tell_object( find_living( NAME ), capitalize( TP->query_real_name() +
            " has entered the your workroom !! " + " (invisible) \n"));
            }
        else {
            tell_object( find_living( NAME ), capitalize( TP->query_real_name() +
            " has entered your workroom !! \n "));
            }
        }
    else { if (TP->query_real_name() != NAME)
        write("Master Sourcer is not at home!!  \n"); }
    add_action("read","read");
    }
    
    /**************************************/
    if(TP->query_race()=="turtle") {
        TP->move_player("into the aquarium#"+"/players/sourcer/room/aquarium");
        ossiCount++;
        return(1);
        }
    
read(str) {
    if (!str) {
        write("What do you want to read ?? \n");
        return 0;
        }
    if (str == "paper" || str == "papers") {
        write("You are not allowed to read this !! \n" +
                "A bell starts ringing!!  \n");
        return 1;
        }
    else write("This in not here. \n");
    }
    
    
