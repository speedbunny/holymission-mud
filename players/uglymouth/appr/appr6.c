inherit "room/room";

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Conclusion";
  long_desc = "Conclusion.\n\n"
    + "You have arrived at the end if this introduction to wizardhood.\n"
    + "When you have read all this, you are well on your way to become\n"
    + "a good wizard. A lot of what is in the docs is a deeper discussion\n"
    + "of what could only be mentioned in a few words here. It is your\n"
    + "task now to study them. The coding room (above the adventurer's\n"
    + "inner guild) provides some help too (the examples are old, but\n"
    + "maybe you can do something with them).\n"
    + "Actual coding you will learn when you will be newwizard. You will\n"
    + "be expected to know a little bit about coding at your test. The\n"
    + "best thing to do here is to go to your mentor, and talk the code\n"
    + "of some files over together, step by step. It's the fastest way to\n" 
    + "learn things that would take pages to describe.\n"
    + "Good luck with reading. We all know it's a boring job, but we all\n"
    + "had to do it once. And hey, being an apprentice doesn't last a real\n" 
    + "long time anyway ;-) Enjoy your wizardhood!\n";
  dest_dir = ({
    "/players/airborne/new/station", "end",
    "/players/uglymouth/appr/appr5", "previous",
  });
}

