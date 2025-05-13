#define NAME "haplo"
inherit "room/room";
#include "/players/haplo/break_string.h"
#define CNAME   capitalize(NAME)
object ob1,ob2;

object ob1;
reset(arg) {
    if(!arg) {
        set_light(1);

        short_desc=CNAME + "' Haplo's study",

       long_desc= break_string(
"You are in the study of the Patryn leader Haplo.  Old tomes fill myriads of "+
"bookshelves which line the walls.  The room is lit by two runes glowing a "+
"lite blue, which are etched on the ceiling.  You can see a large mahogany "+
"desk in the corner of the room, with a comfortable chair behind it. There "+
"are several chairs sitting around the room.  An intricate pattern of runes "+
"are carved into the floor.  You can see pictures of Samurai and Ninjas  "+
"hanging around the room.\n",65);
        dest_dir=({
          "room/post", "post",
          "players/haplo/misc/private/gimme" , "gimme",
         "players/haplo/desert/rooms/path1","desert",
         "players/soozie/workroom","soozie",
          "players/haplo/work_area", "arena",
           "players/haplo/ishikawa/jungle/beach1","ishikawa",
       "players/tuppence/workroom","tuppy",

        "players/herp/workroom","herp",
        "players/dalamar/workroom","dal",
	"players/jewel/workroom", "jewel",
        "room/church" , "church",
            "room/adv_guild", "guild", 
            "players/nokey/centralroom", "central",
            "players/airborne/workroom", "air",
"players/gandalf/workroom", "gandalf",
                 });
  ob1=clone_object("/players/haplo/misc/fun/death");
  ob2=clone_object("/boards/private_boards/haplo");
    transfer(ob1,this_object());
    transfer(ob2,this_object());

        items=({ 
            "air","It's very thin up here",
            "floor","The floor is dirty",
              });
        property = ({
  "no_sneak","no_steal","no_backstab","no_teleport",
                    });
        smell = "This place is a bit dusty";
    }
}

init()
{
  ::init();
}
int connected_to_center()
{return 1;}
