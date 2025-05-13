inherit "room/room";

void reset(int arg) {     
    if(!arg) {
        set_light(1);     

        short_desc = "Outside a cantina hidden in the desert";
        long_desc = "\
You have finally found the entry to the building you have been searching \
for and can take shelter at last.  From the noise, which echoes to where \
you stand, you get the feeling that it is a pub of some kind. The way you feel \
not even the sun bothers you anymore as you dream about the amber nectar for \
consumption that awaits you inside.\n\n";

        dest_dir = ({
            "/players/redsexy/jedi/areas/desert/d58", "west",
            "/players/redsexy/jedi/areas/cantina/3" , "southeast",
        });

        items = ({
            "sand", "The sand spreads on for miles and miles in every \
direction",            
            "desert", "Miles of sand make this island look the same all \
over",
            "wasteland", "This derelict wasteland is the most disturbing \
place you have ever seen",       
            "shelter", "The building to the southwest seems to be a pub",
            "building", "The building to the southwest seems to be a pub",
            "sun", "Two evil suns in the sky heat this desert landscape with \
an alarming ferocity"
 });

       
    }
    ::reset(arg);
    replace_program("room/room");
}
