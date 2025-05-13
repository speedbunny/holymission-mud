// Mangla changed. reformat and remove llort clone to seperate file.

#define TP this_player()

inherit "/obj/treasure";

object mob;
int check;

int do_shoot(string arg) {

  object burst,red,blue,green,silver,scepter;

  if(arg!="stars") return 0;

  blue =present("blue star",TP);
  green =present("green star",TP);
  red =present("red star",TP);
  silver = present("silver star",TP);
  if (blue && green && red && silver) {
    if (!(scepter = present("scepter of arcanarton",TP))) {
      if (!check) {
        write("Llort arrives in a puff of smoke.\n");
        mob = clone_object("/obj/monster");
        mob->set_short("llort");
        mob->set_name("llort");
        mob->set_gender(1);
        mob->set_long("Llort the Master of Time and Space.\n");
        mob->set_hp(40000);
        mob->set_ac(1000);
        mob->set_dodge_bon(70);
        mob->set_n_wc(100);
        mob->set_level(100);
        move_object(mob,environment(TP));
        call_out("do_say1",4,TP);
        check = 1;
      }
      return 1;
    }  
    else {
      write("As you shoot the blue star a blue ball" +
            " of ice explodes in the sky.\n\n" +
            "As you shoot the red star a red ball" +
            " of fire explodes in the sky.\n\n" +
            "As you shoot the green star a green ball" +
            " of gas explodes in the sky.\n\n" +
            "As you shoot the silver star a silver ball"+
            " of electric power explodes in the sky.\n\n");

      write("Suddenly, as you shoot the golden star, a gigantic golden\n"+
            "ball of fire explodes in the sky and melts all the colored\n"+
            "stars into the mightiest weapon the gods have ever seen.\n");
      say(TP->query_name() + " makes a magical gesture and suddenly a\n"+
          "ball of fire explodes into the sky and melting five colored stars\n"+
          "into the mightiest weapon the gods have ever seen.\n");

      burst = clone_object("players/whisky/seaworld/obj/starburst2");

      destruct(red);
      destruct(scepter);
      destruct(blue);
      destruct(green);
      destruct(silver);
      move_object(burst,TP);
      shout(capitalize(this_player()->query_real_name())+
            " sends a mighty fireball to heaven "+
            "as "+this_player()->query_pronoun()+
            " shoots the mighty starburst.\n");
      destruct(this_object());
      return 1; 
    }
  }
}

void do_say1(object tp) {

  tell_room(environment(tp),
            "Llort says: wise decision mortal, but to build "
            "this strong weapon you\n");
  call_out("do_say2",4,tp);
}

void do_say2(object tp) {

  tell_room(environment(tp),
            "Llort says: need the gem and the staff of "
            "Arcarnaton, which are in the\n");
  call_out("do_say3",4,tp);
}

void do_say3(object tp) {

  tell_room(environment(tp),
            "Llort says: hands of evil deeply hidden in "
            "the Crescent lake and\n");
  call_out("do_say4",4,tp);
}

void do_say4(object tp) {

  tell_room(environment(tp),
            "Llort says: the orc camp. Then 'attach the gem "
            "to the staff' !\n");
  call_out("do_say5",4,tp);
}

void do_say5(object tp) {

  tell_room(environment(tp),
            "Llort waves happily, wishing you luck.\n");
  call_out("do_say6",4,tp);
}

void do_say6(object tp) {

  tell_room(environment(tp),
            "Llort disappears in a puff of smoke.\n");
  check = 0;
  if (mob)
    destruct(mob);
}

void reset(int arg) {

  check = 0;

  ::reset(arg);
  if (arg) return;

  set_id("star");
  set_alias("golden star");
  set_short("The golden star");
  set_long("If you you have the other four star "
           "you can <shoot stars> now!!.\n");
  set_value(4000);
}

void init() {

  ::init();
  add_action("do_shoot","shoot");
}

