inherit "obj/container";

reset(arg) {
object dagger;

  ::reset(arg);
  if(!arg) {
    set_max_weight(3);
    set_value(100);
    set_name("box");
    set_short("A beautiful wooden box");
    set_weight(2);
    set_long("This is a smooth box made of shining wood. It was made to\n"
          + "contain three daggers, and on the bottom is blue velvet to\n"
           + "protect the contents against damage. Something is written on\n"
           + "the bottom.\n");
    set_read("For Ianthe, from Roelstra, for your hatred.\n");
    set_only_for("dagger");
    if(!present("dagger",this_object())) {
      dagger=clone_object("players/cashimor/things/dagger");
      transfer(dagger,this_object());
      dagger=clone_object("players/cashimor/things/dirk");
      transfer(dagger,this_object());
      dagger=clone_object("players/cashimor/things/misericorde");
      transfer(dagger,this_object());
    }
  }
}
