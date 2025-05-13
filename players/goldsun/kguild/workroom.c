#define NAME "goldsun"
/* DEF_WORKROOM.C */
/* 300693: Ethereal Cashimor: Removed double define for NAME */
inherit "room/room";
#define CNAME   capitalize(NAME)

/* This procedure is called every hour at the mom. The first time it
   is call with the arg==0, after that arg is always 1. */
reset(arg) {
    /* do the following block only the first time !! */
    move_object("/players/goldsun/obj/t_chest",this_object());
    load_object("/players/goldsun/obj/excalibur");
    if(!arg) {
        
    
        /* first we need some light in here */
        set_light(1);

        /* then lets set a short description in case we are in brief-mode */
        short_desc=CNAME + "' workroom",

        /* now the long standard room description */
        /* change this to fit your style *grin* */
        long_desc=
            "This is the workroom of "+CNAME+".\n" +
	    "It looks very comfortable. There are the large working table\n"+
            "in the middle of the room and many commands, monsters and \n"+
            "objects around the table. You notice small door on the wall.\n";

        /* we need some exits too ... lets set the destination directions */
        dest_dir=({
	    "players/goldsun/guild/room/magic_shop","down"
    	   
                 });

        /* here could follow some item descriptions, like ...*/

        items=({ 
            "air","It's very thin up here",
            "floor","The floor is dirty",
 	    "door","The door to the movie"
              });
        /* Properties can be set like the following */
        property = ({
                     "no_sneak","no_steal","has_fire"
                    });
        /* Smell is set like this... */
        smell = "This place is a bit dusty";
    }
}

init()
{
  ::init();
 say(capitalize(this_player()->query_real_name())+" has entered Goldsun's "+
     "workroom.\n");
add_action("enter","enter"); 
}

int enter(string str){
 if (str=="door"){
  this_player()->move_player("into the door#players/goldsun/movie");
  return 1;
 }
 return 0;
}

