inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Keidall Library";
    no_castle_flag = 0;
    long_desc = 
        "Although this library is small with limited holdings it still provides a \n"
        + "great deal of information for the inhabitants of Keidall and any interested\n"
        + "adventurers. All the walls are lined with shelves and comfortable looking\n"
        + "chairs and sofas are situated all over the place. A crackling fireplace in\n"
        + "the southern wall gives the library a homely feel and you could swear that\n"
        + "you were back at home. \n"
        + "A sign hangs above the fireplace. \n";
    items = ({
         "shelves","They're filled with books of all shapes and sizes",
         "chairs","Plush velvet chairs",
         "sofas","Eeeek! They're made of human skin!",
         "fireplace","It's spreading warmth throughout the library",
         "sign","Wow, what a beautiful sign! Maybe you could read it..",
            });
    dest_dir = 
        ({
        "/players/silas/fghant/keidall5", "north",
        });
    smell = "Smells like any other library...\n";
}
init() {
  ::init();
  add_action("switch_read","read");
}

switch_read(str) {
  switch (str) {
  case 0: case "sign":
   this_player()->more("/players/silas/obj/library.txt");
      return 1; break;
  case "1": case "pick":
   this_player()->more("/players/silas/obj/girl.txt");
      return 1; break;
  case "2": case "bears":
   this_player()->more("/players/silas/obj/bears.txt");
      return 1; break;
  case "3": case "bovine":
   this_player()->more("/players/silas/obj/bovine.txt");
      return 1; break;
  case "4": case "cats":
   this_player()->more("/players/silas/obj/cats.txt");
      return 1; break;
  case "5": case "punk":
   this_player()->more("/players/silas/obj/punk.txt");
      return 1; break;
  }
}
query_light() {
    return 1;
}
