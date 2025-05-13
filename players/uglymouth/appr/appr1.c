inherit "room/room";

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Welcome, Immortal One";
  long_desc = "Welcome, Immortal One.\n"
    + "Now that you have become a wizard, a whole new world has opened\n"
    + "before you. This area has been designed to make you comfortable\n"
    + "with your new status and powers. This area will focus on four\n"
    + "subjects:\n\t* Code of Wizardly Conduct\n\t* Apprentice commands\n"
    + "\t* Basic LPC\n\t* Rules on Coding\n\n"
    + "Remember that this is only an introduction. There is a lot to learn\n"
    + "in the world. Much of it is in the docs you must read (even though\n" 
    + "they may be old and outdated at times). Other things you will learn\n"
    + "by experience and by talking to your mentor and other wizards.\n"
    + "Enjoy your wizardhood!\n";
  dest_dir = ({ 
    "/players/uglymouth/appr/appr2", "next",
    "/players/airborne/new/station", "leave",
    });
}

