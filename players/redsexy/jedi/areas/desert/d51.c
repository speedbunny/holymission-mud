inherit "room/room";

void reset(int arg) {     
    if(!arg) {
        set_light(1);     

        short_desc = "Outside the enterance toa magnificent palace";     
        long_desc = "\
You are on some kind of makeshift path, which has lead you to the hidden \
entry of a grand palace.  It is obvious that whoever owns this place does \
not want anyone to be able to enter his abode, because the walls of \
this place stretch for miles in either direction and this is the only door \
that you can see.  Now that you have found a shelter from the sun, you feel more \
relaxed, but you just know that whoever lives in here will not be happy to \
entertain an intruder so travel forward with caution. \n\n";

        dest_dir = ({
            "/players/redsexy/jedi/areas/palace/15" , "south",
            "/players/redsexy/jedi/areas/desert/d41", "north",
        });

        items = ({
            "path", "The cobblestone path stops at this entry to the \
palace",            
            "walls", "The walls spread for miles into the surrounding \
Dune Sea, but you cannot venture around them", 
            "palace", "The palace is two stories high, and made of the \
finest marble",
            "door", "This old wooden door looks strangely out of place \
compared to the rest of the magnificent castle.",
            "entry", "This old wooden door looks strangely out of place \
compared to the rest of the magnificent castle.",
            "desert", "Miles of sand make this island look the same all \
over",
            "sun", "You are sheltered from the sun by the shadow of the \
castle"
        });

       
    }
    ::reset(arg);
    replace_program("room/room");
}
