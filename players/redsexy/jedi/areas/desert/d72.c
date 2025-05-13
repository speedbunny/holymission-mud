inherit "room/room";

void reset(int arg) {     
    if(!arg) {

        set_light(1);

        short_desc = "On the edge of a town in the depths of the desert.";     
        long_desc = "\
You now stand on the outskirts of a hidden desert town.  The path ends here,  \
and a more sophisticated concrete slabbing leads southeast to the main town area. \
The ominous voice in the back of your head tells you not to get to comfortable \
in your illusions of safety.  You walk on through the heat, praying that you \
will never again have to endure such preposterous conditions for the sake of \
proving yourself as a great adventurer. \n\n";

        dest_dir = ({
            "/players/redsexy/jedi/areas/desert/d71",  "west",
            "/players/redsexy/jedi/areas/desert/d69", "north",
            "/players/redsexy/jedi/areas/desert/d68", "northwest",
            "/players/redsexy/jedi/areas/moseisley/1", "southeast",

        });


         items = ({
             "sand", "The sand is replaced with cobblestones here",            
             "desert", "Miles of sand make this wateland look the same all \
over, but this path offers you hope of an escape",
             "wasteland", "This derelict wasteland is the most disturbing \
place you have ever seen",       
             "path", "The path is paved unevenly with cobblestones, but makes \
way for a sophisticated road leading southeast",
             "cobblestones", "Uneven cobblestones that form a path",
             "slabbing", "Slabs of concrete laid paralell to form a road",
             "sun", "Two evil suns in the sky heat this desert landscape with \
an alarming ferocity",
             "town", "You now stand on the outskirts of the hidden desert town" 
 });
    }
    ::reset(arg);
    replace_program("room/room");
}


