#define NAME "dragonn"
inherit "room/room";

#define CNAME   capitalize(NAME)


void reset(int arg) {

    set_light(1);


    short_desc="[Lord] "+CNAME + "'s workroom",

    long_desc=
"The [Lord] Dragonn workroom.\n";

    dest_dir=({
               "room/post", "post",
               "room/church", "church",
               "room/adv_guild", "guild", 
             });


    items=({ 
            "air","It's very thin up here",
            "floor","The floor is dirty",
          });

    property = ({
                 "no_teleport","no_sneak","no_steal",
               });

// Here you call the the reset in the inherited "room/room"
//    and the replace program will keep the room updated
//    without further function calls
    ::reset(arg);
    replace_program("room/room");
}

init() {
    ::init();
add_action("yell","yell");
}
yell(str){
object u;
 int i;
if (str!="hi"){

               write("Yell what ???\n");
               return 0;
                              }
   u=users();
   for (i=0; i<sizeof(u);i++); {
if (u[i]->query_level()<30) {
if (u[i]->query_level()>30 || u[i]->query_testchar())
{
    if ( this_player()->query_real_name()!="dragonn")
tell_object(u[i],"Dragonn yells: Hello playeerrrrSSSSS\n");
/* changed to the above lines  forgot the ) on the if. :)
    if ( this_player()->query_real_name()!="dragonn"
tell_object(u[i],"Dragonn yells: Hello playeerrrrSSSSS\n");
*/
       }
}
}
   write("Done, Boss.|n");
    return 1;
 }
