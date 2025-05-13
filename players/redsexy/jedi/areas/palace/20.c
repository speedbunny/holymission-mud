inherit "room/room";

void reset(int arg) {     
    if(!arg) {

        set_light(0);

        short_desc = "A dark stairway in Jabba's Palace.";     
        long_desc = "\
You are now climbing a twisting metal staircase, spiraling into the doom and \
gloom of whatever lies below, and rising to the dizzy heights of the palace. \
Your feet clank on every step, the sound dulled by the muddy walls that surround \
the stairs.  Far in the distance you can hear cries of agony, sending a shiver down \
your spine. \n\n";

        dest_dir = ({
            "/players/redsexy/jedi/areas/palace/30", "down",
            "/players/redsexy/jedi/areas/palace/18", "up",

       });

         items = ({
             "staircase", "A sturdy metalic staircase",
             "doom", "You think you may meet your doom if you head downwards",            
             "gloom", "The darkness and the quietness occaisionally broken by \
the screams adds to the gloomy feel of this place",
             "steps", "Tredded metal steps on the staircase",       
             "walls", "This far below ground, the walls are made of mud",
             "cries", "Cries of pain and agony from whatever lies below",
       });

}
    ::reset(arg);
    replace_program("room/room");
}




