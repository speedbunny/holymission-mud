#define NAME "sargon" 
/* DEF_WORKROOM.C */ 
/* 300693: Ethereal Cashimor: Removed double define for NAME */ 
inherit "room/room"; 
#define CNAME   capitalize(NAME) 

/* This procedure is called every hour at the mom. The first time it 
   is call with the arg==0, after that arg is always 1. */ 
reset(arg) { 
    /* do the following block only the first time !! */ 
    if(!arg) { 
        /* first we need some light in here */ 
        set_light(1); 

        /* then lets set a short description in case we are in brief-mode */ 
        short_desc=CNAME + "' workroom", 
        /* now the long standard room description */ 
        /* change this to fit your style *grin* */ 

        long_desc= 
        "This is the workroom of "+CNAME+".\n"+ 
        "There is a chess board on a table set up in the middle of the room.\n"+ 
        "And of course there are two chairs.\n"+ 
        "Maybe you should choose a side.\n"+ 
        "\n"; 


        /* we need some exits too ... lets set the destination directions */ 
        dest_dir=({ 
            "room/post", "post", 
           "players/patience/arena/prep_room","pr",
            "room/church", "church", 
            "room/adv_guild", "guild",  
            "players/sargon/guild/rooms/restroom", "fig",
            "players/sargon/testrm", "test",
            "players/matt/newworld/city/rooms/votebooth", "vote",
            "players/mangla/guild/rooms/inner", "inner",
            "players/sargon/obj/shop.c", "shop",
 }); 

        /* here could follow some item descriptions, like ...*/ 
        items=({  
            "air","It's very thin up here", 
            "floor","The floor is very clean", 
              }); 
        /* Properties can be set like the following */ 
        property = ({ 
                     "no_teleport","no_sneak","no_steal", 
                    }); 
        /* Smell is set like this... */ 
        smell = "This place smells like pepperoni pizza"; 
    } 
} 

init() 
{ 
  ::init(); 
} 
