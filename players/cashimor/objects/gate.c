inherit "obj/thing";

int geopend,raadsel;
string raadsels,oplossing;

long() {
  ::long();
  if (geopend==1) {
    write("The gate is standing open...\n");
  }
}

reset(arg) {
  if(!arg) {
    set_name("gate");
    set_short("A beautiful stone gate");
    set_long("This is a gate to the north made by the lost elven smiths.\n"
           + "It's made of stone and magic and it looks pretty in the sun.\n"
           + "Many people seem to have knocked on it.\n");
    set_can_get(0);
    move_object(this_object(),"room/mount_pass");
    geopend = 0;
    raadsel = 666;
    raadsels = ({
      "What is that?\nInvisible.\nDifficult to find.\n"
    + "Useful for someone who knows.\nOften opens interesting new ways.\n",
      "Any human has got it\nand loves it when it's smooth,\n"
    + "soft and nice.\nYou have got it, unlike mice.\n",
      "In winter it is hard as stone,\nand without it there isn't wine,\n"
    + "sometimes it is in the sky\nAnd if you enter it, you could die.\n",
      "Hole next to hole, usually round,\nhowever dead still healthy,\n"
    + "often thick and heavy,\nbut in deserts it is light.\nYeah, right.\n"
               });
    oplossing = ({
      "secret door",
      "skin",
      "water",
      "sponge"
                });

  }
}

init() {
  add_action("open","open");
  add_action("say_it","say");
  add_action("open","close");
  add_action("enter","enter");
  add_action("enter","north");
  add_action("knock","knock");
}

enter(str) {
  if(!id(str)) return 0;
  if(geopend==0) {
    write("But the gate is closed!\n");
    say(this_player()->query_name()+" slams into a closed gate!\n");
    return 1;
  }
  this_player()->move_player("north#room/mine/tunnel");
  return 1;
}

open(str) {
  if(!id(str)) return 0;
  write("It's impossible to open or close the gate by hand!\n");
  say(this_player()->query_name()+" attempts to move the door but fails.\n");
  return 1;
}

say_it(str) {
  say(this_player()->query_name()+" says: "+str+"\n");
  write("Ok.\n");
  if (raadsel==666) return 1;
  if (oplossing[raadsel]==str) {
    raadsel = 666;
    write("The gate slowly opens!\n");
    say("The gate slowly opens!\n");
    geopend = 1;
    call_out("closegate",25);
  }
  return 1;
}

closegate() {
  geopend = 0;
  say("The gate slams shut!\n");
  write("The gate slams shut!\n");
}

knock(str) {
  if(!id(str)) return 0;
  if(geopend==1) {
    write("But the gate is opened!\n");
    return 1;
  }
  if(raadsel==666) {
    raadsel=random(sizeof(oplossing));
  }
  write("You knock on the door.\n");
  say(this_player()->query_name()+" knocks on the door.\n");
  write("The door says:\n"+raadsels[raadsel]);
  say("The door says:\n"+raadsels[raadsel]);
  return 1;
}

