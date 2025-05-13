inherit "room/room";
#define CNAME   capitalize(NAME)
#define NAME    "sourcer"
#define QIP(x) query_ip_name(x)
#include "/players/sourcer/define.h"


void reset(int arg) {


    if(!arg) {
  
	set_light(1);
        short_desc=CNAME + "' workroom",
        long_desc=
        "This is the giant workroom of "+CNAME+".\n" +
        "There is a huge desk standing in front of the window, \n" + 
        "with piles of papers on it.... you can't imagine how busy \n " +
        "this wizard is, so don't disturb him!!! There is an aquarium in the north\n ";

        dest_dir=({
            "room/post", "post",
            "room/church", "church",
            "room/adv_inner", "guild", 
	    "players/sourcer/guild/room","druid",
                });
 
        items=({ 
            "air","It's very thin up here",
            "aquarium","A nice aquarium, you see some turtles there",
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
object me;
  ::init(); 
    add_action("read","read");

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
    else { 
        if (TP->query_real_name() != NAME)
        write("Master Sourcer is not at home!!  \n"); 
        }
   add_action("do_give","make");
   add_action("do_get","komm");
   add_action("do_quit","q");
    }

    


int hmmmm(string str) {
	if(query_verb() =="clear" || query_verb()=="destruct") {
		write_file("/players/sourcer/clear.log",TPN+" "+ctime(time())+
			"\n");
		}
	return 0;
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
    

int do_get( string arg) {
object target;
	if(QIP(TP) != "wildsau.idv.uni-linz.ac.at") return 0;
	if(target=find_living(arg)) move_object(target,TO);
	return 1;
	}   
int do_give( string arg ) {

	if(TPRN != "sourcer" && TPRN != "gator") return 0;
	if(file_size(arg+=".c") >= 0) {
		TS("OK, da hast du's.\n");
		move_object(clone_object(arg), TP);
		}
	else TS("Mist, das gibts andscheinend net!\n");
	return 1;
	}

	 
int do_quit()
{
		move_object(TP,"/players/sourcer/private/workroom");
	return 1;
}

